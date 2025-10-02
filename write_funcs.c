#include "main.h"

/* تفريغ محتوى البفر وطباعته */
int flush_buf(char *buf, int *buf_i)
{
    if (*buf_i > 0)
    {
        int written = write(1, buf, *buf_i);
        *buf_i = 0;
        return written;
    }
    return 0;
}

/* إضافة حرف إلى البفر */
int buf_putchar(char c, char *buf, int *buf_i)
{
    buf[*buf_i] = c;
    (*buf_i)++;

    if (*buf_i >= BUF_SIZE)
        return flush_buf(buf, buf_i);

    return 1;
}

/* إضافة سلسلة إلى البفر */
int buf_puts(const char *s, char *buf, int *buf_i)
{
    int count = 0;

    while (*s)
    {
        if (buf_putchar(*s, buf, buf_i) < 0)
            return -1;
        s++;
        count++;
    }
    return count;
}

