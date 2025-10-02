#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

#define BUF_SIZE 1024

int _printf(const char *format, ...);

/* دوال مساعدة للكتابة باستخدام البفر */
int buf_putchar(char c, char *buf, int *buf_i);
int buf_puts(const char *s, char *buf, int *buf_i);
int flush_buf(char *buf, int *buf_i);

/* دوال تحويل الأعداد */
int int_to_str(int n, char *str);
int buf_putint(int n, char *buf, int *buf_i);

#endif

