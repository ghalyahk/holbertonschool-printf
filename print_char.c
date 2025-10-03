#include "main.h"

/**
 * print_char - prints a single character
 * @args: argument list
 *
 * Return: number of characters printed (1)
 */
int print_char(va_list args)
{
    char c = (char) va_arg(args, int);

    return (write(1, &c, 1));
}

