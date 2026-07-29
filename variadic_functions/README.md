# 0x0f. C - Variadic functions

Implements variadic functions in C using `stdarg.h`: summing an arbitrary list of integers, printing numbers and strings separated by a separator, and a `printf`-like `print_all` that dispatches on a format string using a lookup table of function pointers (no `switch`/`else`/`for`, within the 2-if/2-while/9-variable limits).

All code is compiled with `gcc -Wall -Werror -Wextra -pedantic -std=gnu89` and follows Betty coding style.
