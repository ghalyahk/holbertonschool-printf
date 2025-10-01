#include "main.h"

/**
 * _printf - Custom printf function supporting %b
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i, count = 0;
    char c;

    va_start(args, format);

    i = 0;
    while (format && format[i])
    {
        if (format[i] == '%' && format[i + 1])
        {
            i++;
            if (format[i] == 'b')
                count += print_binary(va_arg(args, unsigned int));
            else if (format[i] == '%')
                count += _putchar('%');
            else
            {
                c = format[i];
                count += _putchar(c);
            }
        }
        else
        {
            c = format[i];
            count += _putchar(c);
        }
        i++;
    }

    va_end(args);
    return count;
}
