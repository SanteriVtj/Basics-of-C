#include <stdio.h> 
#include <math.h>

double vectorlength(double x, double y, double z)
{
	return pow((pow(x,2) + pow(y,2) + pow(z,2)), 0.5);
}

int main(void)
{
	printf("Value of d = %f\n",vectorlength(1.2,5.3,4.2));
}