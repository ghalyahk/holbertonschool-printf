#include "main.h"

/**
 * print_hex - Prints an unsigned int in hexadecimal
 * @uppercase: 1 for uppercase A-F, 0 for lowercase a-f
 * Return: number of characters printed
 */
int print_hex(unsigned int n, int uppercase)
{
    int count = 0;
    char digit;

    if (n / 16)
        count += print_hex(n / 16, uppercase);

    digit = n % 16;
    if (digit < 10)
        _putchar(digit + '0');
    else
        _putchar(digit - 10 + (uppercase ? 'A' : 'a'));

    return count + 1;
}
