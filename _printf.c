#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;
    char buf[BUF_SIZE];
    int buf_i = 0;
    int total = 0;
    const char *p;

    if (!format)
        return -1;

    va_start(args, format);
    p = format;

    while (*p)
    {
        if (*p == '%')
        {
            p++;
            if (*p == 'c')
            {
                char c = (char)va_arg(args, int);
                buf_putchar(c, buf, &buf_i);
                total++;
            }
            else if (*p == 's')
            {
                char *s = va_arg(args, char *);
                if (!s)
                    s = "(null)";
                total += buf_puts(s, buf, &buf_i);
            }
            else if (*p == 'd' || *p == 'i')
            {
                int num = va_arg(args, int);
                total += buf_putint(num, buf, &buf_i);
            }
            else if (*p == '%')
            {
                buf_putchar('%', buf, &buf_i);
                total++;
            }
            else
            {
                buf_putchar('%', buf, &buf_i);
                buf_putchar(*p, buf, &buf_i);
                total += 2;
            }
        }
        else
        {
            buf_putchar(*p, buf, &buf_i);
            total++;
        }
        p++;
    }

    va_end(args);
    flush_buf(buf, &buf_i);

    return total;
}

