#include "main.h"

/**
 * _printf - custom printf function
 * @format: format string
 *
 * Return: number of characters printed (or -1 on error)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, printed_chars = 0;

    if (format == NULL)
        return (-1);

    va_start(args, format);

    while (format[i])
    {
        if (format[i] != '%')
        {
            write(1, &format[i], 1);
            printed_chars++;
        }
        else
        {
            i++;
            switch (format[i])
            {
                case 'c':
                    printed_chars += print_char(args);
                    break;
                case 's':
                    printed_chars += print_string(args);
                    break;
                case '%':
                    printed_chars += print_percent(args);
                    break;
                case 'd':
                case 'i':
                    printed_chars += print_int(args);
                    break;
                case 'b':
                    printed_chars += print_binary(args);
                    break;
                default:
                    /* Unknown specifier: print "%" then the char */
                    write(1, "%", 1);
                    write(1, &format[i], 1);
                    printed_chars += 2;
                    break;
            }
        }
        i++;
    }

    va_end(args);
    return (printed_chars);
}

