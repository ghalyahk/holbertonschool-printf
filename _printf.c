#include "main.h"

/* انسخ هنا دوال buf_putchar و buf_puts و flush_buf */
static char buffer[1024];
static int buf_index = 0;

int buf_putchar(char c)
{
    if (buf_index >= 1024)
        flush_buf();
    buffer[buf_index++] = c;
    return 1;
}

int buf_puts(char *str)
{
    int i = 0;
    while (str[i])
    {
        buf_putchar(str[i]);
        i++;
    }
    return i;
}

int flush_buf(void)
{
    int wrote = 0;

    if (buf_index > 0)
    {
        wrote = write(1, buffer, buf_index);
        buf_index = 0;
    }
    return wrote;
}

/* دالة _printf */
int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;
    char ch;

    if (format == NULL)
        return -1;

    va_start(args, format);

    while ((ch = *format++) != '\0')
    {
        if (ch == '%')
        {
            ch = *format++;
            if (ch == 'c')
            {
                char c = (char)va_arg(args, int);
                printed_chars += buf_putchar(c);
            }
            else if (ch == 's')
            {
                char *str = va_arg(args, char *);
                if (str == NULL)
                    str = "(null)";
                printed_chars += buf_puts(str);
            }
            else if (ch == '%')
            {
                printed_chars += buf_putchar('%');
            }
            else
            {
                /* معالجة أخرى ممكن تضيفها */
                printed_chars += buf_putchar('%');
                printed_chars += buf_putchar(ch);
            }
        }
        else
        {
            printed_chars += buf_putchar(ch);
        }
    }

    va_end(args);
    printed_chars += flush_buf();
    return printed_chars;
}

