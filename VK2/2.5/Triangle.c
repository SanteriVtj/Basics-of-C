#include <stdio.h>


void draw_triangle(unsigned int size)
{
	for (int i = size; i > 0; i--) {
		int x = size - i + 1;
		for (int j = i - 1; j > 0; j--) {
			printf(".");
		}
		for (int j = x; j > 0; j--) {
			printf("#");
		}
		printf("\n");
	}
}

int main()
{
	draw_triangle(5);
	return 0;
}