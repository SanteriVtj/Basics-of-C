
#include "source.h"
#include <stdlib.h>
#include <stdio.h>

/* Dynamic Array Reader */
/* Parameters:
 * n: Number of values to be read
 * 
 * Returns: pointer to the dynamically allocated array
 */
int *create_dyn_array(unsigned int n)
{
    int *table = malloc(n * sizeof(int));
    for (unsigned int i = 0; i < n; i++) {
    	scanf("%d", &table[i]);
    }
    return table;
}

/* Add to array */
/* Parameters:
 * arr: Existing array of integers
 * num: number of integers in the array before the call
 * newval: new value to be added
 * 
 * Returns: pointer to the allocated array
 */
int *add_dyn_array(int *arr, unsigned int num, int newval)
{
	arr = realloc(arr, ((num * sizeof(int)) + (2 * sizeof(int))));
	arr[num] = newval;
    return arr;
}
