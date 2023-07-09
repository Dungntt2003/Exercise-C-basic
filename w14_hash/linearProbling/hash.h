// Exercise 14.3: ADT Hash Table with linear probing method

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE (10)
#define NULLKEY (-1)

typedef struct node_t {
  int key;
  /* other fields */
} element_t;

void init_table();
int hash(const int k);

int findElement(const int k);
int insertItem(const int k);
int removeElement(int k);

void traverse();  // Duyet