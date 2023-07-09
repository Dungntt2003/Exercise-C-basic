#include "hash.h"

#include <string.h>

element_t hash_table[TABLE_SIZE];

// Hash Code Maps: Component Sum
static const int transform(const char *key) {
  int number;
  for (number = 0; (*key) != 0; key++) number += *key;
  return number;
}

// Compression map
int hash(const char *key) { return (transform(key) % TABLE_SIZE); }

// ====================================
//
// ====================================

void init_table(element_t ht[]) {
  for (int i = 0; i < TABLE_SIZE; i++) ht[i].key[0] = UNDEFINE;  // = NULL
}

element_t findElement(element_t ht[], char key[]) {
  static const element_t NO_SUCH_KEY = {"", ""};
  const int hash_value = hash(key);
  if (ht[hash_value].key[0] = UNDEFINE)
    return NO_SUCH_KEY;
  else
    return ht[hash_value];
}

int insertItem(element_t ht[], element_t o) {
  int hash_value = hash(o.key);
  if (ht[hash_value].key[0] != UNDEFINE)
    return FALSE;  // Khong xet truong hop collision
  else {
    strcpy(ht[hash_value].key, o.key);
    strcpy(ht[hash_value].word, o.word);
    return TRUE;
  }
}

int removeElement(element_t ht[], char key[]) {
  int hash_value = hash(key);
  if (ht[hash_value].key[0] == UNDEFINE) {
    return -1;  // khong tim thay
  } else if (strcmp(ht[hash_value].key, key) !=
             0)  // tim thay nhung key khong khop: collision
    return 0;
  else {
    ht[hash_value].key[0] = UNDEFINE;  // remove
    return 1;
  }
}

int size(element_t ht[]) {
  int count = 0;
  for (int i = 0; i < TABLE_SIZE; i++)
    if (ht[i].key[0] != UNDEFINE) count++;
  return count;
}

int isEmpty(element_t ht[]) {
  int i;
  for (i = 0; i < TABLE_SIZE; i++)
    if (ht[i].key[0] != UNDEFINE) return FALSE;
  if (i == TABLE_SIZE) return TRUE;
};

void clear(element_t ht[]) { init_table(ht); }

// Duyet
void traverse(element_t ht[]) {
  for (int i = 0; i < TABLE_SIZE; i++)
    if (ht[i].key[0] != UNDEFINE)
      printf("(id, key, value) = (%d, %s, %s)\n", hash(ht[i].key), ht[i].key,
             ht[i].word);  // In this example value = key
}
