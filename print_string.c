#include "main.h"

/**
 * print_string - prints a string
 * @args: argument list
 *
 * Return: number of characters printed
 */
int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int i = 0;

    if (str == NULL)
        str = "(null)";

    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }

    return (i);
}

