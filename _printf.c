#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _putchar - writes a character to stdout
 * @c: character to print
 * Return: 1 on success
 */
int _putchar(char c)
{
    return putchar(c);  /* استخدام putchar القياسي */
}

/**
 * _printf - prints formatted output to stdout
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;
    char *s;
    int num;

    va_start(args, format);
    if (!format)
        return -1;

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 'c')
                count += _putchar(va_arg(args, int));
            else if (format[i] == 's')
            {
                s = va_arg(args, char *);
                if (!s)
                    s = "(null)";
                for (int j = 0; s[j]; j++)
                    count += _putchar(s[j]);
            }
            else if (format[i] == 'd')
            {
                num = va_arg(args, int);
                char buf[20];
                int k = 0, neg = 0;

                if (num < 0)
                {
                    neg = 1;
                    num = -num;
                }

                if (num == 0)
                    buf[k++] = '0';

                while (num > 0)
                {
                    buf[k++] = (num % 10) + '0';
                    num /= 10;
                }

                if (neg)
                    count += _putchar('-');

                for (int l = k - 1; l >= 0; l--)
                    count += _putchar(buf[l]);
            }
            else
                count += _putchar(format[i]);
        }
        else
            count += _putchar(format[i]);
        i++;
    }

    va_end(args);
    return count;
}

