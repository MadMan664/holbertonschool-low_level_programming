# Baseline Loop Execution Measurements

## Compile Command
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long baseline_loop.c -o baseline_loop

## Run 1
Iterations: 100000000
Execution time: 0.084868 seconds

## Run 2
Iterations: 100000000
Execution time: 0.090980 seconds

## Run 3
Iterations: 100000000
Execution time: 0.110653 seconds

## Observations
Execution times varied across the three runs (0.084868s, 0.090980s, 0.110653s)
despite running the exact same deterministic computation each time. This
timing variability is expected: it reflects normal system-level noise (CPU
scheduling, cache state, background processes) rather than any change in the
program itself.
