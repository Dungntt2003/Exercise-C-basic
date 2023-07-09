#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include "bst.h"

#define MAX_STACK_SIZE 50
enum {EXIT_STACK_OVERFLOW=1, EXIT_STACK_UNDERFLOW };

typedef tree_t elem_t;

typedef struct stack_s{
	tree_t storage[MAX_STACK_SIZE];
   int top;
} stack_t;

void initialize(stack_t *pStack);
int isEmpty(stack_t stack);
int isFull(stack_t stack);
void push(elem_t el, stack_t *pStack);
elem_t pop(stack_t *pStack);

#endif