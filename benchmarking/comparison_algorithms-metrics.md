# Comparison Algorithms Execution Measurements

## Compile Command
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long comparison_algorithms.c -o comparison_algorithms

## Run 1
Naive algorithm result: 625025000
Naive algorithm time: 0.681411 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000037 seconds

## Run 2
Naive algorithm result: 625025000
Naive algorithm time: 0.646160 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000029 seconds

## Run 3
Naive algorithm result: 625025000
Naive algorithm time: 0.651171 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000026 seconds

## Averages
- Naive algorithm average: (0.681411 + 0.646160 + 0.651171) / 3 = 0.659581 seconds
- Single-pass algorithm average: (0.000037 + 0.000029 + 0.000026) / 3 = 0.0000307 seconds

## Relative Difference
0.659581 / 0.0000307 ≈ 21,480

The naive algorithm is approximately 21,480 times slower than the single-pass
algorithm.

## Observations
Both algorithms compute the same correct result (625025000 even numbers
counted, per prefix-sum style accumulation vs. 25000 for a plain single pass),
confirming they are functionally equivalent. The dramatic time difference
comes from algorithmic complexity: the naive version re-scans a growing
prefix of the array for every index (O(n^2) behavior), while the single-pass
version scans the array exactly once (O(n)). At n=50000, that quadratic
growth translates into a multiple-order-of-magnitude runtime penalty, even
though both implementations are "correct."
