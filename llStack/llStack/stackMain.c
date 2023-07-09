#include <stdio.h>
#include "stack.h"

int main() {
  stack_t s = llInit();
  printf("Them du lieu vao stack (-1 de ket thuc):\n");

  data_t t;
  for (scanf("%d", &t); t != -1; scanf("%d", &t)) {
    s = push(s, t);    
  }

  // Pop data from Stack and display to screen
  while (!isEmpty(s)) {
    showData(top(s));
    s = pop(s);
  }

  llDeleteAll(s); // <===

  return 0;
}