#include <stdio.h>
#include <ctype.h>

void ascii_chart(char min, char max)
{
	int count = 0;
	for (int i = min; i <= max; i++) {
		count++;
		if (i < 100) {
			if (isprint(i)) {
			printf(" %d 0x%02x %c", i, i, i);
			}
			else {
				printf(" %d 0x%02x ?", i, i);	
			}
		}
		else {
			if (isprint(i)) {
			printf("%-d 0x%02x %c", i, i, i);
			}
			else {
				printf("%-d 0x%02x ?", i, i);	
			}
		}
		if (count == 4) {
			printf("\n");
			count = 0;
		}
		else {
			printf("\t");
		}
	}
}

int main()
{
	ascii_chart(28,35);
	return 0;
}