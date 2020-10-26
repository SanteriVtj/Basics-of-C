#include <stdio.h>
#include <ctype.h>
#include "source.h"


/* Array Sum
 * Calculate the sum of integers in array starting at address <array>.
 * There will be <count> elements in array. Return the sum as return value.
 */
int array_sum(int *array, int count)
{
	int sum = 0;
    for (int i = 0; i < count; i++) {
    	sum = sum + array[i];
    }
    return sum;
}

/* Array Reader */
/* Parameters:
 * vals: array to be filled
 * n: maximum size of array
 * returns: number of values read */
unsigned int array_reader(int *vals, int n)
{
	int i = 0;
	while (scanf("%d", &vals[i++]));
	while (i < n && isdigit(vals[i])) {
		i++;
	}
	/*for (int j = 0; j < n; j++) {
		printf("%d\n", j);
	}*/
	return i-1;
	/*int i = 0;
	while (i < n) {
		printf("%d\n", vals[i]);
		if (!(isdigit(vals[i]))) {
			break;
		}
		i++;
	}
    return i;*/
}