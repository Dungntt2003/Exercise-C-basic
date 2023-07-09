#include <stdlib.h>
#include "stack.h"

// root_t llInit();
stack_t stackInit() { return llInit(); }

int isEmpty(stack_t s) { return s == NULL; }

int isFull(stack_t s) { return 0; }

stack_t push(stack_t stack, const data_t data) {
  return llInsertHead(stack, data);
 }

stack_t pop(stack_t stack) {
  return llDeleteHead(stack);
}

stack_t popData(stack_t stack, data_t *pData) {
  *pData = top(stack);
  return pop(stack);
}

data_t top(stack_t stack) {
  if (isEmpty(stack)) {
    printf("ERROR: Empty Stack!!!\n");
    exit(EXIT_STACK_EMPTY);
  }
  data_t data = stack->data;
  return data;
}