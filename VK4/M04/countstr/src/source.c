#include "source.h"
#include <string.h>
#include <stdio.h>



/* Count Substring
 * Count number of occurances of substring <sub> in string <str>,
 * and return the count.
 */
int num_substr(const char *str, const char *sub)
{
	char s[strlen(str)];
	strcpy(s, str);
	int count = 0;
	while (strstr(s, sub)) {
		count++;
		int x = 0;
		for (unsigned int i = (strlen(str) - strlen(strstr(s, sub))); i <= strlen(str); i++) {
			s[x] = s[i];
			x++;
		}
		x = 0;
	}
    return count;
}
