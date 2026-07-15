# Simple Calculator

A terminal-based interactive calculator written in C.

## Compile
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 calculator.c -o calculator

## Run
./calculator

## Supported Operations

Add
Subtract
Multiply
Divide
Quit


The menu repeats after each operation until `0` is chosen to quit.

## Numeric Behavior

All values (menu choice, operands, and results) are handled as `int`.
Division is **integer division**: the result is truncated toward zero,
not rounded to a decimal. For example, `10 / 4` prints `Result: 2`,
not `Result: 2.5`.

Dividing by zero does not crash the program. Instead it prints:
Error: division by zero

## Known Limitations

- Menu input is only validated as an integer within range (0-4).
  Non-numeric input (e.g. typing `x` instead of a number) is not
  handled and may cause unexpected looping behavior. This is
  intentional per the mandatory project scope; robust non-numeric
  input handling is an optional advanced task not implemented here.
- Since results are integers, division results are always truncated,
  never rounded or shown with decimal precision.
