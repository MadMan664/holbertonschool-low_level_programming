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
| `0-strcat.c` | Concatenates two strings |
| `1-strncat.c` | Concatenates two strings, using at most n bytes from src |
| `2-strncpy.c` | Copies at most n bytes from src to dest |
| `3-strcmp.c` | Compares two strings |
| `4-rev_array.c` | Reverses the content of an array of integers |
| `5-string_toupper.c` | Converts lowercase letters of a string to uppercase |
| `6-cap_string.c` | Capitalizes all words of a string |
| `7-leet.c` | Encodes a string into 1337 |
| `main.h` | Function prototypes |
