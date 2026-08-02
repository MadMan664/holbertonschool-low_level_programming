# Valgrind Analysis: heap_example.c and aliasing_example.c

## AI Usage Disclosure

Claude was used to help interpret the raw Valgrind output. I independently
re-ran Valgrind myself and verified the line numbers, addresses, and byte
counts against my own program's source and my own terminal output before
accepting any explanation.

## heap_example.c — "6 bytes definitely lost"

==2311== 6 bytes in 1 blocks are definitely lost in loss record 1 of 1
==2311== at 0x4846828: malloc (...)
==2311== by 0x109211: person_new (heap_example.c:21)
==2311== by 0x1092FA: main (heap_example.c:51)


`main.c:51` is `alice = person_new("Alice", 30);` (line 52, the `bob`
call, is not implicated) — so this is `alice`'s allocation. "Alice" is 5
characters plus a null terminator = 6 bytes, matching exactly.

Comparing the two cleanup paths in `main`:

```c
free(bob->name);
free(bob);

person_free_partial(alice);
```

`bob` gets two explicit `free()` calls: one for the string buffer
(`bob->name`), one for the struct (`bob`). `alice` only goes through
`person_free_partial`, which is:

```c
static void person_free_partial(Person *p)
{
    if (!p)
        return;
    free(p);
}
```

This function contains exactly one `free()` call, and it only frees `p`
(the struct itself) — it never touches `p->name`. Once `alice` (the
struct) is freed, no variable in the program still holds `alice->name`'s
address, so that 6-byte block becomes permanently unreachable. This is a
**leak due to lost ownership**: the memory was never explicitly freed, and
after the struct that held the only pointer to it is gone, nothing can
reach it again for the rest of the program's life. That is exactly what
Valgrind's "definitely lost" classification means, as opposed to "still
reachable" (a pointer to it still exists somewhere at exit).

## aliasing_example.c — 3 "Invalid read/write" errors

All 3 errors point at the same freed block (`0x4a74480`, size 20 — five
ints), traced back to the same `malloc` in `make_numbers` and the same
`free(a)` call at line 38. This is a **use-after-free**: `b` is not a
separate allocation, it is an alias for the same address as `a` (`b = a`),
so freeing through `a` invalidates `b`'s target too, even though `b`'s
value never changes.

It is reported 3 separate times, not once, because Valgrind checks every
individual memory access independently, and there are 3 separate lines
that touch `b` after the free: the read at line 42 (`b[2]`), the write at
line 44 (`b[3] = 1234`), and the read at line 45 (printing `b[3]`). Same
root cause, three distinct moments it is triggered.

Notably, the actual value read back from `b[2]` differed between runs
without Valgrind (garbage values like `568897765` or `1605566220`,
different each run) and with Valgrind (`22`, the original value). This
shows that reading freed memory does not reliably return anything in
particular — the result depends on unpredictable allocator internals, not
on any guarantee. Neither result is "correct"; both are valid
manifestations of undefined behavior.

## "Definitely lost" vs. "still reachable"

`heap_example`'s 6 bytes are "definitely lost": no pointer anywhere in the
program still reaches that memory once `alice` is freed — it is genuinely
and permanently unreachable.

By contrast, Valgrind reported `crash_example`'s 1,024 bytes as "still
reachable," not a leak: reachable means some pointer chain to that memory
still exists at the point the program ends, it just was never explicitly
freed before exit. That is a much lower-severity classification than a
true leak, because the memory could in principle still have been freed if
the program had run longer or exited more carefully.
