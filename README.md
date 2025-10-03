# holbertonschool-printf

A custom implementation of the C standard library function `printf`.

## Description

This project is a collaborative recreation of the standard C `printf` function for the Holberton School curriculum. It supports several format specifiers and handles variable argument lists using `stdarg`.

## Supported Format Specifiers

| Specifier    | Description                                 |
|--------------|---------------------------------------------|
| `%c`         | Prints a single character                   |
| `%s`         | Prints a string                              |
| `%%`         | Prints a percent sign                        |
| `%d` / `%i`   | Prints a signed integer                     |
| `%b`         | Prints an unsigned int in binary (custom)    |

Unsupported specifiers (like `%r`) are printed literally (e.g. `%r` → `%r`).

## Compilation

Compile all `.c` files with:

```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 *.c

