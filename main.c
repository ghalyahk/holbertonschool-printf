#include "main.h"

/**
 * main - Entry point for testing _printf
 *
 * Return: 0
 */
int main(void)
{
    _printf("Char: %c\n", 'A');
    _printf("String: %s\n", "Hello");
    _printf("Percent: %%\n");
    _printf("Integer: %d, %i\n", 123, -456);
    _printf("Binary of 98: %b\n", 98);
    _printf("Unknown: %r\n");
    return (0);
}

