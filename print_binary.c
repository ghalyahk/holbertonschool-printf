#include "main.h"

/**
 * print_binary - prints an unsigned int in binary (custom specifier %b)
 * @args: argument list
 *
 * Return: number of characters printed
 */
int print_binary(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);
    unsigned int mask = 1 << 31;  /* mask to check bits */
    int printed = 0;
    int started = 0;

    if (n == 0)
    {
        write(1, "0", 1);
        return (1);
    }

    while (mask > 0)
    {
        if (n & mask)
        {
            started = 1;
            write(1, "1", 1);
            printed++;
        }
        else if (started)
        {
            write(1, "0", 1);
            printed++;
        }
        mask >>= 1;
    }

    return (printed);
}

