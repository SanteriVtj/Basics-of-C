#include "stringsplit.h"

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>


/* Split string by another string, return split parts + NULL in array.
 *
 * Parameters: 
 *  str: the string to split
 *  split: the string to split str with
 *
 * Returns:
 *  A dynamically reserved array of dynamically reserved string parts.
 *
 * For example called with "Test string split" and " ",
 * returns ["Test", "string", "split", NULL].
 * Or called with "Another - test" and " - ",
 * returns ["Another", "test", NULL].
 */

char** split_string(const char *str, const char* split) {
	char* s = malloc((strlen(str) + 1) * sizeof(char));
	int c = 0;
	strcpy(s, str);
	char **ret = malloc(strlen(str) * sizeof(char *));
	char *temp = malloc((strlen(str) + 1) * sizeof(char));
	int temp_c = 0;
	int idx = 0;
	int te_b = 1;
	while (s[c] != '\0') {
		te_b = 1;
		temp[temp_c] = s[c];
		if ((&s[c] == strstr(&s[c], split)) || s[c+1] == '\0') {
			c += strlen(split) - 1;
			if (s[c+1] == '\0') {
				temp[temp_c+1] = s[c];
				temp_c++;
			}
			temp[temp_c] = '\0';
			ret[idx] = malloc((strlen(temp) + 1) * sizeof(char));
			strcpy(ret[idx++], temp);
			free(temp);
			temp = malloc((strlen(str) + 1) * sizeof(char));
			temp_c = 0;
			te_b = 0;
		}
		c++;
		if (te_b) temp_c++;
	}
	free(temp);
	free(s);
    return ret;
}

void print_split_string(char **split_string) {
	int idx = 0;
	while (split_string[idx] != NULL) {
		printf("%s\n", split_string[idx]);
		idx++;
	}
}

void free_split_string(char **split_string) {
	int idx = 0;
    while (split_string[idx] != NULL) {
    	free(split_string[idx]);
    	idx++;
    }
    free(split_string);
}



