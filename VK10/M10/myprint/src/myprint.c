#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int myprint(const char *str, ...) {
    va_list args;
    va_start(args, str);

    int c = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '&') {
            c++;
            printf("%d", va_arg(args, int));
        } else {
            fputc(str[i], stdout);
        }
    }

    va_end(args);
    return(c);
}