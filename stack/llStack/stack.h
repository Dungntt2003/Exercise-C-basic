#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include "llist.h"

enum {EXIT_STACK_OVERFLOW = 1, EXIT_STACK_UNDERFLOW , EXIT_STACK_EMPTY};


typedef root_t stack_t;

stack_t stackInit();

int isEmpty(stack_t stack);
int isFull(stack_t stack);

root_t push(stack_t stack, const data_t data);
stack_t pop(stack_t stack);
stack_t popData(stack_t stack, data_t *pData);

// Tra ve phan tu tren cung cua stack, khong loai phan tu nay khoi stack
data_t top(stack_t stack);

#endif