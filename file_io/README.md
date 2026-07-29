# 0x11. C - File I/O

Low-level file I/O using raw POSIX system calls (`open`, `read`, `write`, `close`) instead of buffered `stdio` streams: reading a text file and printing it to stdout, creating a file with specific permissions (`rw-------`), appending to an existing file, and a `cp`-style program that copies file contents 1024 bytes at a time with proper exit codes (97/98/99/100) on each failure mode.

All code is compiled with `gcc -Wall -Werror -Wextra -pedantic -std=gnu89` and follows Betty coding style.
