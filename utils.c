#include "main.h"

/* تحويل عدد صحيح إلى نص */
int int_to_str(int n, char *str)
{
    int i = 0, j;
    int is_negative = 0;
    unsigned int num;

    if (n == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return i;
    }

    if (n < 0)
    {
        is_negative = 1;
        num = (unsigned int)(-n);
    }
    else
    {
        num = (unsigned int)n;
    }

    while (num != 0)
    {
        str[i++] = (num % 10) + '0';
        num /= 10;
    }

    if (is_negative)
        str[i++] = '-';

    /* عكس السلسلة */
    for (j = 0; j < i / 2; j++)
    {
        char temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }
    str[i] = '\0';
    return i;
}

/* طباعة عدد صحيح */
int buf_putint(int n)
{
    char numbuf[12]; /* تكفي لأكبر int مع الإشارة */
    int len;

    len = int_to_str(n, numbuf);
    return buf_puts(numbuf);
}

