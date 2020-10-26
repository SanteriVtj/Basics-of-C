#include <stdio.h>

unsigned int arraylen(const char *array)
{
	int i = 0;
    while (array[i] != 0) {
    	i++;
    }
    return i;
}

void countchars(const char *array, unsigned int *counts)
{
	int i = 0;
    while (array[i] != 0) {
    	counts[(int)array[i]] = counts[(int)array[i]] + 1;
    	i++;
    }
}




