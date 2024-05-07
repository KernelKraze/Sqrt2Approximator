// my_stdio.c
#include "my_stdio.h"
#include <stdarg.h>  // 提供可变参数功能

int my_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    int int_val;
    double dbl_val;
    char ch;
    const char* str_val;

    while (*format != '\0') {
        if (*format == '%') {
            switch (*(++format)) {
                case 'd':  // 整数
                    int_val = va_arg(args, int);
                    char buffer[100];
                    int length = snprintf(buffer, 100, "%d", int_val);  // 使用 snprintf 转换整数为字符串
                    write(1, buffer, length);
                    break;
                case 'f':  // 浮点数
                    dbl_val = va_arg(args, double);
                    char floatBuf[100];
                    int floatLen = snprintf(floatBuf, 100, "%.2f", dbl_val);  // 浮点数转字符串
                    write(1, floatBuf, floatLen);
                    break;
                case 's':  // 字符串
                    str_val = va_arg(args, const char*);
                    write(1, str_val, strlen(str_val));
                    break;
                case 'c':  // 单个字符
                    ch = (char) va_arg(args, int);  // 需要用 int 提取 char 类型的参数
                    write(1, &ch, 1);
                    break;
            }
        } else {
            write(1, format, 1);
        }
        format++;
    }
    va_end(args);
    return 0;
}
