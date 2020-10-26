#include <stdio.h>

int main(void) {
    unsigned char x = 0xff;
    printf("%d\n", x>>4<<4);
    x = (x >> 4);
    printf("%d\n", x);
    x = (x << 4);
    printf("%d\n", x);
}