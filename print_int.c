#include "main.h"

/**
 * print_int - prints an integer (signed)
 * @args: argument list
 *
 * Return: number of characters printed
 */
int print_int(va_list args)
{
    int n = va_arg(args, int);
    unsigned int num;
    int count = 0;
    char buffer[12];  /* Enough for 32-bit int + sign */
    int i = 0, j;

    if (n < 0)
    {
        count += write(1, "-", 1);
        num = (unsigned int)(-n);
    }
    else
    {
        num = (unsigned int) n;
    }

    /* convert number to string in reverse order */
    do {
        buffer[i++] = (num % 10) + '0';
        num /= 10;
    } while (num > 0);

    /* print in correct order */
    for (j = i - 1; j >= 0; j--)
    {
        count += write(1, &buffer[j], 1);
    }

    return (count);
}

