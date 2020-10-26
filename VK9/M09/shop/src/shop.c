#include "shop.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int write_binary(const char* filename, const Product* shop)
{
	FILE *f = fopen(filename, "w");
    if (!f) return(0);
    int i = 0;
    while (shop[i].name[0] != '\0') i++;
    int fr = fwrite(shop, sizeof(Product), i, f);
    if (fr != i) return(1);
    fclose(f);
    return(0);
}

Product* read_binary(const char* filename)
{
    FILE *f = fopen(filename, "rb");
    if (!f) return(0);
    int i = 0;
    int fr = 1;
    Product *ret = malloc(sizeof(Product));
    while (fr == 1) {
        fr = fread(&ret[i], sizeof(Product), 1, f);
        i++;
        ret = realloc(ret, sizeof(Product) * (i+1));
    }
    ret[i-1].name[0] = '\0';
    fclose(f);
    return(ret);
}

int write_plaintext(const char* filename, const Product* shop)
{
    FILE *f = fopen(filename, "w");
    if (!f) return(1);
    int i = 0;
    while (shop[i].name[0] != '\0')  {
        fprintf(f, "%s %f %d\n", shop[i].name, shop[i].price, shop[i].in_stock);
        i++;
        fprintf(f, "%s", "\0\n");
    }
    fclose(f);
	return(0);
}

Product* read_plaintext(const char* filename)
{
    FILE *f = fopen(filename, "r");
    if (!f) return(NULL);
	Product *ret = malloc(sizeof(Product));
    int i = 0;
    int fs = fscanf(f, "%s %f %d\n", ret[i].name, &ret[i].price, &ret[i].in_stock);
    while (fs == 3) {
        i++;
        ret = realloc(ret, sizeof(Product) * (i + 1));
        fs = fscanf(f, "%s %f %d\n", ret[i].name, &ret[i].price, &ret[i].in_stock);
    }
    ret[i].name[0] = '\0';
    fclose(f);
	return(ret);
}
