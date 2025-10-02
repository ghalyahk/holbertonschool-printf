#include "main.h"

/**
 * print_unsigned - Prints an unsigned int in decimal
 * Return: number of characters printed
 */
int print_unsigned(unsigned int n)
{
    int count = 0;

    if (n / 10)
        count += print_unsigned(n / 10);

    _putchar((n % 10) + '0');
    return count + 1;
}
