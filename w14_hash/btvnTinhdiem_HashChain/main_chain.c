#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

element_t* ht[TABLE_SIZE];

int main() {
  const char* keys[] = {"John Smith", "Lisa Smith", "Sam Doe", "Sandra Dee"};
  // const char* keys[] = {"John Smith", "Lisa Smith", "Sam Doe"};
  // const char* keys[] = {"Lisa Smith", "Sandra Dee"};

  for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++) {
    printf("(key, hash(key)) = (%d, %s)\n", hash(keys[i]), keys[i]);
  }

  init_table(ht);
  for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++) {
    element_t e;
    strcpy(e.key, keys[i]);
    strcpy(e.word, keys[i]);
    e.next = NULL;
    insertItem(ht, e);
  }

  printf("Traverse:\n");

  traverse(ht);
  return 0;
}