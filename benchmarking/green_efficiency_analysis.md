# Green Efficiency Analysis

## Measurement Methodology

All measurements were taken on the same machine using `clock()` from `<time.h>`,
converting ticks to seconds via `CLOCKS_PER_SEC`. Each program was compiled with
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long` and run multiple
times to account for natural timing variability. For `baseline_loop.c`, the
program was run 3 times as-is. For `comparison_algorithms.c`, both the naive
and single-pass implementations were run 3 times each and averaged. For
`instrumentation_lab.c`, four separate `clock_t` start/end pairs were added:
one wrapping the entire `main` sequence (`TOTAL`) and one around each of the
three phases (`build_dataset`, `process_dataset`, `reduce_checksum`), so that
`TOTAL` could be checked against the sum of the sub-measurements.

## Observed Performance Differences

The baseline loop (100,000,000 iterations) ran in 0.084868s, 0.090980s, and
0.110653s across three runs — a spread of about 30% between the fastest and
slowest run despite executing identical work each time. In the algorithm
comparison, the naive nested-loop implementation averaged 0.659581 seconds
while the single-pass implementation averaged 0.0000307 seconds, a relative
difference of roughly 21,480x. Both produced correct, matching logic (an
even-count derived from the same 50,000-element array), so the runtime gap is
attributable entirely to algorithmic structure, not correctness. In the
instrumentation lab, phase timings were on the order of hundreds of
microseconds (e.g. one run: TOTAL 0.000640s, BUILD_DATA 0.000305s, PROCESS
0.000206s, REDUCE 0.000124s), with TOTAL consistently greater than or equal to
the sum of the three phases, as expected.

## Relation Between Runtime and Energy Consumption

This project treats runtime as a proxy for energy use rather than measuring
watts directly. A CPU drawing power for 0.66 seconds to finish a task
generally consumes more energy than one drawing power for 0.00003 seconds to
produce the same result, since the core is active and switching transistors
for a longer window either way. The naive vs. single-pass comparison makes
this concrete: at scale (many users, many requests, repeated execution), a
21,480x difference in per-call runtime compounds into a proportionally larger
difference in aggregate CPU-active time, and by extension, aggregate energy
draw — even though this project measures none of that directly in watts.

## Limitations of the Experiment

`clock()` measures CPU time, not wall-clock time or actual power draw, and its
resolution is coarse enough that very short operations (like the single-pass
algorithm's ~0.00003s) carry proportionally more measurement noise than longer
ones. The machine was not otherwise idle or isolated from background OS
activity during these runs, which explains the ~30% variance seen in the
baseline loop's three identical executions. No hardware power meter or
tool like `perf` was used, so "energy consumption" here is inferred from
runtime, not measured directly.

## Practical Engineering Takeaway

Algorithmic complexity has a far larger effect on runtime — and by extension,
inferred energy cost — than micro-level code tweaks. The 21,480x gap between
an O(n^2) and an O(n) approach to the same problem dwarfs any variance caused
by system noise (the ~30% seen in the baseline loop). Before optimizing
constants or syntax, checking whether an algorithm's fundamental complexity
class can be improved is the highest-leverage efficiency decision a developer
can make.
