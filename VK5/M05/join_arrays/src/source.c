
#include "source.h"
#include <stdlib.h>
#include <string.h>

int* join_arrays(unsigned int n1, const int *a1,
		 unsigned int n2, const int *a2,
		 unsigned int n3, const int *a3)
{
	int* tot = malloc(((n1 + n2 + n3) * sizeof(int)));
    memcpy(tot, a1, n1 * sizeof(int));
    memcpy(tot + n1, a2, n2 * sizeof(int));
    memcpy(tot + n1 + n2, a3, n3 * sizeof(int));
    return tot;
}
