
#include "source.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Remove C comments from the program stored in memory block <input>.
 * Returns pointer to code after removal of comments.
 * Calling code is responsible of freeing only the memory block returned by
 * the function.
 */
int get_size(char *array) {
	int size = 0;
	while (*array++) size++;
	return size;
}

char *delete_comments(char *input)
{
	int s = get_size(input);
	char* x = malloc(s);
	int j;
	int len = 0;
	for (int i = 0; i < s; i++){
		if (input[i] == '/') {
			j = i;
			if (input[i+1] == '/') {
				while (input[j] != '\n' && j < s) j++;
				j++;
			} else if (input[i+1] == '*') {
				j++;
				while (j < s) {
					j++;
					if (input[j] == '*') {
						if (input[j+1] == '/') break;
					}
				}
				j += 2;
			}
			i = j;
		}
		x[len++] = input[i];
	}
	free(input);
	return realloc(x, len+1);
}
