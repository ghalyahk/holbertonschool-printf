#include "main.h"

/**
 * print_binary - Prints the binary representation of a number
 * @n: unsigned int number
 *
 * Return: Number of characters printed
 */
int print_binary(unsigned int n)
{
    int count = 0;
    unsigned int mask = 1 << (sizeof(unsigned int) * 8 - 1);
    int started = 0;

    if (n == 0)
    {
        _putchar('0');
        return 1;
    }

    while (mask)
    {
        if (n & mask)
        {
            _putchar('1');
            started = 1;
        }
        else if (started)
            _putchar('0');

        mask >>= 1;
    }

    /* Count number of digits printed */
    unsigned int tmp = n;
    while (tmp)
    {
        count++;
        tmp >>= 1;
    }

    return count;
}

