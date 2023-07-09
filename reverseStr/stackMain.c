#include <stdio.h>
#include "stack.h"

int main() {
  char str[100];
  printf("Nhap chuoi:");
  scanf("%s", str);

  stack_t s;
  initialize(&s);

  printf("Tach du lieu vao stack:\n");
  for (int i = 0; str[i] != '\0'; i++) push(str[i], &s);

  // Pop data from Stack and add to str
  for (int i = 0; !isEmpty(s); i++) str[i] = pop(&s);

  printf("Chuoi sau khi reverse la: %s\n", str);
  return 0;
}