#include "filebasics.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/* Print give file <filename> to the standard output stream.
 * Return number of characters printed, -1 if file opening fails.
 */
int print_file_and_count(const char *filename)
{
    FILE *f = fopen(filename, "rb");
    if (!f) return(-1);
    char c = fgetc(f);
    while (c != EOF) {
        printf("%c", c);
        c = fgetc(f);
    }
    fseek(f, 0, SEEK_END);
    return(ftell(f));
}

/* Compare two files. The function should return the first lines that differ
 * in the two files, concatenated together, separated by four dashes, on
 * different lines. If the files are equal, NULL is returned. 
 * Function stops immediately, if either one of the files end and returns NULL.
 * You can assume that lines are not longer than 1000 characters.
 */
char *difference(const char *file1, const char *file2)
{
    FILE *f1 = fopen(file1, "rb");
    FILE *f2 = fopen(file2, "rb");
    if (!f1 || !f2) return(NULL);
    char l1[2500];
    char l2[2500];
    fgets(l1, 2500, f1);
    fgets(l2, 2500, f2);
    char *x = "----\n";
    while (1) {
        // printf("l1: %s", l1);
        // printf("l2: %s", l2);
        if (strcmp(l1, l2) != 0) {
            char *res = malloc(sizeof(l1) + sizeof(l2) + sizeof(x));
            strcpy(res, l1);
            strcat(res, x);
            strcat(res, l2);
            fclose(f1);
            fclose(f2);
            return(res);
        }
        if (fgets(l1, sizeof(l1), f1) == NULL) {
            return(NULL);
        }
        if (fgets(l2, sizeof(l2), f2) == NULL) {
            return(NULL);
        }
        // fgets(l1, sizeof(l1), f1);
        // fgets(l2, sizeof(l2), f2);
    }
    return(NULL);
}


