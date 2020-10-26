
#include "source.h"


/* Selection sort */
/* Parameters:
 * start: start of an array
 * size: length of an array
 */
void sort(int *start, int size)
{
    int min;
    for (int i = 0; i < size; i++) {
    	min = i;
    	for (int j = i + 1; j < size; j++) {
    		if (start[j] < start[min]) {
    			min = j;
    		}
    	}
    	int temp = start[i];
    	start[i] = start[min];
    	start[min] = temp;
    }
}
