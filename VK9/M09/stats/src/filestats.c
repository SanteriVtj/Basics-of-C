    
#include "filestats.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


/* Returns the line count in given file
 * 
 * Parameters:
 * filename: name of the file to be investigated.
 * 
 * Returns:
 * The number of lines in file. */
int line_count(const char *filename)
{
    FILE *f = fopen(filename, "rb");
    if (!f) return(-1);
    char c[2500];
    int count = 0;
    if (fgets(c, sizeof(c), f) == NULL) return(count);
    while (1) {
        count++;
        if (fgets(c, sizeof(c), f) == NULL) {
            fclose(f);
            return(count);
        }
    }
    fclose(f);
    return(count);
}


/* Count the number of words in the file. Word has to include at least one
 * alphabetic character, and words are separated by whitespace.
 * 
 * Parameters:
 * filename: name of the file to be investigated.
 * 
 * Returns:
 * number of words in the file */
int word_count(const char *filename)
{
    FILE *f = fopen(filename, "rb");
    if (!f) return(-1);
    int count = 0;
    int c = fgetc(f);
    int got_alpha = 0;
    while (c != EOF) {
        if (isalpha(c)) got_alpha = 1;
        if (isspace(c) && got_alpha == 1) {
            got_alpha = 0;
            count++;
        }

        c = fgetc(f);
    }
    if (got_alpha == 1) count++;
    fclose(f);
    return(count);
}
