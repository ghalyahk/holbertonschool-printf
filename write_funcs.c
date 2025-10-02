#include "main.h"

/* هنا تكتب دوال أخرى مثل طباعة unsigned, hex, pointer لو حبيت */

/* مثال: طباعة unsigned int */
int buf_putunsigned(unsigned int n)
{
    char numbuf[11]; /* تكفي لأكبر unsigned int */
    int i = 0, j;
    unsigned int num = n;

    if (num == 0)
    {
        return buf_putchar('0');
    }

    while (num != 0)
    {
        numbuf[i++] = (num % 10) + '0';
        num /= 10;
    }

    /* عكس السلسلة */
    for (j = 0; j < i / 2; j++)
    {
        char temp = numbuf[j];
        numbuf[j] = numbuf[i - j - 1];
        numbuf[i - j - 1] = temp;
    }
    numbuf[i] = '\0';

    return buf_puts(numbuf);
}

/* دالة طباعة hex (lowercase أو uppercase حسب الباراميتر) */
int buf_puthex(unsigned int n, int uppercase)
{
    char hex_chars[] = "0123456789abcdef";
    char HEX_CHARS[] = "0123456789ABCDEF";
    char numbuf[9]; /* تكفي لـ 32-bit hex */
    int i = 0, j;
    unsigned int num = n;

    if (num == 0)
    {
        return buf_putchar('0');
    }

    while (num != 0)
    {
        if (uppercase)
            numbuf[i++] = HEX_CHARS[num % 16];
        else
            numbuf[i++] = hex_chars[num % 16];
        num /= 16;
    }

    /* عكس السلسلة */
    for (j = 0; j < i / 2; j++)
    {
        char temp = numbuf[j];
        numbuf[j] = numbuf[i - j - 1];
        numbuf[i - j - 1] = temp;
    }
    numbuf[i] = '\0';

    return buf_puts(numbuf);
}

/* طباعة pointer */
int buf_putptr(void *ptr)
{
    unsigned long addr = (unsigned long)ptr;
    int printed_chars = 0;

    printed_chars += buf_puts("0x");
    printed_chars += buf_puthex((unsigned int)addr, 0);
    return printed_chars;
}

