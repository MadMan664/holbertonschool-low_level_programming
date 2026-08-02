# Memory Maps: stack_example.c and aliasing_example.c

## AI Usage Disclosure

I used Claude to run both programs, generate a first-pass memory analysis,
and propose explanations. I then verified every claim against the real
program output and Valgrind output from my own sandbox, and corrected the
AI's explanation where it was imprecise (documented in the "AI Mistake"
section below).

## stack_example.c

### Stack growth direction

Actual addresses observed for `&local_int` across recursion depths:

depth=0: 0x7ffc406849a4
depth=1: 0x7ffc40684974
depth=2: 0x7ffc40684944
depth=3: 0x7ffc40684914


Each depth's address is exactly `0x30` lower than the previous depth's.
This shows the stack grows toward **lower** addresses as more functions are
called: every new function call pushes a frame by decrementing the stack
pointer register, so deeper recursive calls end up with lower addresses
than the calls that made them. depth=3 (deepest, most recent call) has the
lowest address of all four; depth=0 (outermost) has the highest.

### Pointer vs. value: `p_local`

`int *p_local = &local_int;` does **not** copy `local_int`'s value (100).
It stores `local_int`'s **address**. `p_local` is a pointer: a variable
whose content is a memory address, not a copy of the data at that address.

### Frame reuse on function return

[enter] depth=3: &local_int=0x...4914
[exit] depth=3: &local_int=0x...4914


These are identical because between the `[enter]` and `[exit]` calls to
`dump_frame` at depth 3, no other function call happened (`3 < 3` is
false, so `walk_stack` does not recurse further). The first `dump_frame`
call used that stack slot and returned, freeing that slot for reuse; the
second `dump_frame` call was the very next thing to request a frame, so it
was handed the same slot. Nothing else touched that memory in between.

### AI Mistake (documented correction)

Claude's first-pass description called this "the memory being logically
freed" when a stack frame returns, implicitly comparing it to heap
`free()`. This is incorrect and misleading: there is no function call
involved in releasing a stack frame at all. Checking `stack_example.c`
directly, `dump_frame` contains no `free()` call and no cleanup of any
kind before it returns. What actually happens is purely mechanical: when
the function returns, the CPU moves the stack pointer register back up
(undoing the decrement from when the function was called). No memory is
zeroed, no bookkeeping happens, and no function is invoked — the space is
just considered available for the next call. This is why `[exit] depth=3`
still showed the old values (103, 'D', etc.) unchanged: the bytes were
never touched, only the accounting of what memory is "in use" changed.
Heap `free()`, by contrast, is an explicit call that the allocator must
process. Describing both as "logically freed" erases a real and important
mechanical difference.

## aliasing_example.c

### Aliasing

a=0x4a74480 b=0x4a74480


`b = a;` makes `b` an alias: both variables hold the identical heap
address. There is only one array in memory; `a` and `b` are two names for
the same block, not two separate copies.

### Dangling pointer

after free(a): b=0x4a74480 (dangling)


After `free(a)`, `b`'s address **value does not change** — it is still
the exact same number it always was. `free()` does not modify the pointer
variables that hold an address; it only tells the allocator that the
memory at that address is available for reuse. `b` is now a **dangling
pointer**: a pointer whose stored address is still perfectly well-formed,
but which no longer refers to memory the program owns. The danger is
precisely that nothing about the pointer itself looks broken.
