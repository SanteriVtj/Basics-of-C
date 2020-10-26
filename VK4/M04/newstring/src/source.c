#include "source.h"
#include <stdio.h>
#include <stddef.h>

/* Print string */
/* Parameters:
 * s: string to be printed */
void qstr_print(const char *s)
{
	int i = 0;
    while (s[i] != '?') {
    	printf("%c", s[i]);
    	i++;
    }
}

/* String length */
/* Parameters:
 * s: string to be evaluated
 * Returns: length of the string */
unsigned int qstr_length(const char *s)
{
	int i = 0;
    while (s[i] != '?') {
    	i++;
    }
    return i;
}

/* String cat */
/* Parameters:
 * dst: buffer to which the new string is appended
 * src: string to be appended
 * Returns: Number of characters in the new string */
int qstr_cat(char *dst, const char *src)
{
	int i = 0;
    while (dst[i] != '?') {
    	i++;
    }
    int j = 0;
    while (src[j] != '?') {
    	j++;
    }
    int ret = i + j;
    int a = 0;
    for (int x = i; x <= ret; x++) {
    	dst[x] = src[a];
    	a++;
    }
    return ret;
}

/* String strstr */
const char *qstr_strstr(const char *str1, const char *str2)
{
	int len = 0;
    while (str1[len] != '?') {
    	len++;
    }
    int len2 = 0;
    while (str2[len2] != '?') {
    	len2++;
    }
	for (int i = 0; i <= len; i++) {
		if (str1[i] == str2[0]) {
			int t = 0;
			int j = 0;
			for (j = 0; j < len2; j++) {
				if (str2[j] == str1[i + j]) {
					t++;
				}
			}
			j = 0;
			if (t == len2) {
				return &str1[i];
			}
		}
	}
    return NULL;
}
