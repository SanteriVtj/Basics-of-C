#include "source.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>




char *my_toupper(char *dest, const char *src)
{
	int d = 0;
	for (unsigned int i = 0; i <= strlen(src); i++) {
		if (isalpha(src[i])) {
			dest[d] = toupper(src[i]);
		} 
		else if (src[i] == '.') {
			int j = d + 2;
			for (int c = d; c <= j; c++) {
				dest[c] = '!';
			}
			d += 2;
		}
		else if (src[i] == '?') {
			dest[d] = '!';
		} 
		else {
			dest[d] = src[i];
		}
		d++;
	}
	return dest;
}