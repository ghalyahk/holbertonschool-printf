#include "main.h"

int _putchar(char c)
{
    return write(1, &c, 1);
}

int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;
    char c;

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 'u')
                count += print_unsigned(va_arg(args, unsigned int));
            else if (format[i] == 'o')
                count += print_octal(va_arg(args, unsigned int));
            else if (format[i] == 'x')
                count += print_hex(va_arg(args, unsigned int), 0);
            else if (format[i] == 'X')
                count += print_hex(va_arg(args, unsigned int), 1);
            else
                count += _putchar('%'), count += _putchar(format[i]);
        }
        else
        {
            count += _putchar(format[i]);
        }
        i++;
    }

    va_end(args);
    return count;
}
