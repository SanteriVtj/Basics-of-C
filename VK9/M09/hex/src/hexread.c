#include "hexread.h"
#include <stdio.h>
#include <stdlib.h>


/* Prints the given file as hexdump, at most 16 numbers per line.
 * <filename> parameter is the name of the file.
 * 
 * Returns the number of characters read
 */
int file_to_hex(const char *filename)
{
    FILE *f = fopen(filename, "rb");
    if (f == NULL) {
        return(-1);
    }

    int c = 0;
    int bytes = 0;
    int hex = fgetc(f);
    while (hex != EOF) {
        bytes++;
        
        printf("%02x ", hex);
        c++;
        if (c == 16) {
            printf("\n");
            c = 0;
        }
        hex = fgetc(f);
    }
    fclose(f);
    return(bytes);
}
