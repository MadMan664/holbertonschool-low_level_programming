# Crash Report: crash_example.c

## AI Usage Disclosure

Claude helped generate an initial explanation of the crash, which I
verified against the actual Valgrind output and the source code directly,
and against the aliasing_example error for comparison (see critique
below).

## Description of the crash

`crash_example` terminates with a segmentation fault (exit code 139 /
signal 11) when run with `n = 0`.

## Root cause analysis

The causal chain, in order:

1. `main` sets `n = 0`.
2. `allocate_numbers(0)` is called. Its first check, `if (n <= 0) return
   NULL;`, is true for `n = 0`, so the function returns `NULL` immediately
   — `malloc` is never called at all.
3. Back in `main`, `nums = allocate_numbers(n);` assigns `nums = NULL`.
4. The next line, `nums[0] = 42;`, is equivalent to writing to address
   `nums + 0`. Since `nums` is `NULL` (address `0x0`), this attempts to
   write the value 42 to address `0x0`.
5. Address `0x0` is never backed by any real memory page — the OS
   deliberately leaves it unmapped so that any dereference of a NULL
   pointer fails immediately. The write instruction faults, and the
   kernel delivers SIGSEGV, killing the process.

Valgrind confirms this precisely:

==2314== Invalid write of size 4
==2314== at 0x10928A: main (crash_example.c:32)
==2314== Address 0x0 is not stack'd, malloc'd or (recently) free'd


## Why the memory access is invalid

This is a **NULL pointer dereference**, a distinct category from
use-after-free. The distinction matters and is worth stating explicitly:

- In `aliasing_example.c`, Valgrind reported the invalid address as
  `"8 bytes inside a block of size 20 free'd"` — that address *was* real,
  valid memory at one point; it only became invalid after `free()` ran.
- In `crash_example.c`, Valgrind reported the address as `"not stack'd,
  malloc'd or (recently) free'd"` — address `0x0` was never valid memory
  for this program at all, at any point in its execution. It is not a
  case of "previously valid, now invalid"; it is a sentinel value (`NULL`)
  that C uses specifically to mean "this pointer does not point to
  anything," and the OS refuses to back it with real memory for exactly
  that reason.

## Critique of AI-provided explanation

An early version of this analysis described `nums[0] = 42` only as
"pointer arithmetic" (`*(nums + 0)`) without explaining why address `0x0`
specifically is invalid, as opposed to just being an unlucky address.
That framing restates the syntax but does not explain the actual
mechanism. The corrected explanation above is more precise: address `0x0`
is invalid not because of bad luck or arithmetic, but because it was never
mapped to any real memory in the first place, by deliberate OS design —
which is a fundamentally different situation from dereferencing a pointer
to memory that used to be valid (as in the aliasing_example use-after-free
case).

## Suggested fix (optional)

`main` could check `nums != NULL` before dereferencing it, e.g.:

```c
if (nums == NULL) {
    return 1;
}
```

This would not fix the underlying issue of requesting 0 numbers, but would
prevent the NULL dereference from crashing the program.
