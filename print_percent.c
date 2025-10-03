#include "main.h"

/**
 * print_percent - prints a percent sign
 * @args: argument list (not used)
 *
 * Return: number of characters printed (1)
 */
int print_percent(va_list args)
{
    (void) args;
    return (write(1, "%", 1));
}

