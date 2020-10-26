#include "queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int enqueue(struct studentqueue *q, const char *name)
{
	struct studentqueue *cur = q;
    while (1) {
    	if (cur->next == NULL) {
    		struct studentqueue *x = malloc(sizeof(struct studentqueue));
    		cur->next = x;
    		x->name = malloc(strlen(name)+1);
    		strcpy(x->name, name);
    		x->next = NULL;
    		break;
    	}
    	cur = cur->next;
    }
    if (cur != NULL) return 1;
    return 0;
}

int dequeue(struct studentqueue *q, char *buffer, unsigned int size)
{
	if (q->next == NULL) return 0;
	for (unsigned int i = 0; i < size-1 && i < strlen(q->next->name); i++) {
		buffer[i] = q->next->name[i];
	}
    free (q->next->name);
	struct studentqueue *x = malloc(sizeof(struct studentqueue));
	x->next = q->next;
    q->next = q->next->next;
    free(x->next);
    free(x);
    return 1;
}