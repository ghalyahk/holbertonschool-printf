#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/* دوال مساعدة للكتابة باستخدام البفر */
int buf_putchar(char c);
int buf_puts(char *str);
int flush_buf(void);

/* دوال الكتابة */
int buf_putint(int n);
int buf_putunsigned(unsigned int n);
int buf_puthex(unsigned int n, int uppercase);
int buf_putptr(void *ptr);

/* دالة الطباعة */
int _printf(const char *format, ...);

#endif /* MAIN_H */

