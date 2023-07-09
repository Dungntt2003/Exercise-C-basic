#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"

int main() {
  const int keys[] = {89, 18, 49, 58, 69};
  
  for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++) {
    printf("(key, hash(key)) = (%d, %d)\n", hash(keys[i]), keys[i]);
  }

  init_table();

  for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++) {
    insertItem(keys[i]);
  }

  printf("\nTraverse:\n");

  traverse();

  int n;
  printf("Nhap key can tim:");  scanf("%d", &n);
  printf("findElement(%d) = %d\n", n, findElement(n));

  int m;
  printf("Nhap key can xoa:");
  scanf("%d", &m);
  removeElement(findElement(m));

  printf("After remove key %d:\n", m);
  traverse();
  return 0;
}