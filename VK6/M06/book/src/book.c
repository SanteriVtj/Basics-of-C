#include "book.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int init_book(struct book *p_book, const char *p_id, const char *p_title, const char * p_author, struct date release)
{
	if (strlen(p_id) > 9) {
		return 0;
	}
	memset(p_book->id, 0, strlen(p_id)+1);
	p_book->title = malloc(strlen(p_title)+1);
	p_book->author = malloc(strlen(p_author)+1);
	strcpy(p_book->id, p_id);
	strcpy(p_book->title, p_title);
	strcpy(p_book->author, p_author);
	p_book->release_date = release;
	if (p_book == NULL) return 0;
	return 1;
}

struct book *add_to_collection(struct book *collection, unsigned int size, struct book new_book)
{
	collection = realloc(collection, sizeof(struct book) * (size + 2));
	memset(collection[size].id, 0, strlen(new_book.id)+1);
	collection[size].title = malloc(strlen(new_book.title)+1);
	collection[size].author = malloc(strlen(new_book.author)+1);
	strcpy(collection[size].id, new_book.id);
	strcpy(collection[size].title, new_book.title);
	strcpy(collection[size].author, new_book.author);
	collection[size].release_date = new_book.release_date;
	return collection;
}