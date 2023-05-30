#include <stdarg.h>
#include <stdio.h>
#include "printf.h"

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0;
    char c;
    const char *s;

    int i = 0; // Move the declaration to the beginning of the block

    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            i++;
            switch (format[i])
            {
                case 'c':
                    c = va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                case 's':
                    s = va_arg(args, const char *);
                    while (*s != '\0')
                    {
                        putchar(*s);
                        s++;
                        count++;
                    }
                    break;
                case '%':
                    putchar('%');
                    count++;
                    break;
            }
        }
        else
        {
            putchar(format[i]);
            count++;
        }
        i++;
    }

    va_end(args);
    return count;
}
