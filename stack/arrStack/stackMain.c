#include <stdio.h>

#include "stack.h"

int main() {
  stack_t s;
  initialize(&s);

  printf("Them du lieu vao stack (-1 de ket thuc):\n");

  int t;
  for (scanf("%d", &t); t != -1; scanf("%d", &t)) {
    push(convert(t), &s);    
  }

  // Pop data from Stack and display to screen
  while (!isEmpty(s)) {
    showData(pop(&s));
  }

  return 0;
}