# Pointers, Arrays and Strings

Functions demonstrating pointer manipulation, array handling, and
manual string operations, written without the standard library
(except where explicitly permitted).

## Compile
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 <main.c> <file.c> -o <output>

`100-atoi.c` additionally requires `-fsanitize=signed-integer-overflow`.

## Files

| File | Description |
|---|---|
| `0-reset_to_98.c` | Updates an int through a pointer to 98 |
| `1-swap.c` | Swaps the values of two integers via pointers |
| `2-strlen.c` | Returns the length of a string |
| `3-puts.c` | Prints a string followed by a newline |
| `4-print_rev.c` | Prints a string in reverse |
| `5-rev_string.c` | Reverses a string in place |
| `6-puts2.c` | Prints every other character of a string |
| `7-puts_half.c` | Prints the second half of a string |
| `8-print_array.c` | Prints n elements of an int array |
| `9-strcpy.c` | Copies a string, including the null byte |
| `100-atoi.c` | Converts a string to an integer |
| `main.h` | Function prototypes |
