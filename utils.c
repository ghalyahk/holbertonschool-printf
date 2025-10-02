#include "main.h"

/* تحويل int إلى نص */
int int_to_str(int n, char *str)
{
    int i = 0, sign = n, start = 0;
    char temp[12];
    int j;

    if (n == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return 1;
    }

    if (n < 0)
        n = -n;

    while (n > 0)
    {
        temp[i++] = (n % 10) + '0';
        n /= 10;
    }

    if (sign < 0)
        temp[i++] = '-';

    for (j = i - 1; j >= 0; j--)
    {
        str[start++] = temp[j];
    }

    str[start] = '\0';
    return start;
}

/* طباعة رقم int باستخدام البفر */
int buf_putint(int n, char *buf, int *buf_i)
{
    char numbuf[12];
    int_to_str(n, numbuf);
    return buf_puts(numbuf, buf, buf_i);
}

