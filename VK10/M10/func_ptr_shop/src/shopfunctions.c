#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shopfunctions.h"

int compareAlpha(const void* a, const void* b)
{
	const Product *prod_a = a;
	const Product *prod_b = b;
	
	return(strcmp(prod_a->name, prod_b->name));
}

int compareNum(const void* a, const void* b)
{	
	const Product *prod_a = a;
	const Product *prod_b = b;
	
	if (prod_a->in_stock > prod_b->in_stock) {
		return(-1);
	} else if (prod_a->in_stock < prod_b->in_stock) {
		return(1);
	}
	return(compareAlpha(a, b));
}

const Product* findProduct(const Product* p_array, const char* search_key, int (*cmp)(const void*, const void*))
{
	(void)p_array;
	(void)search_key;
	(void)cmp;

	int i;
	for (i = 0; p_array[i].name[0] != '\0'; i++); 
	return bsearch(search_key, p_array, i, sizeof(Product), cmp);
}
