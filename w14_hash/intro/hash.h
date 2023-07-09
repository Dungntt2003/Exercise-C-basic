// Exercise 14.1: Dictionary ADT

#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR (11)
#define TABLE_SIZE (13)
#define UNDEFINE ('\0')

enum { FALSE, TRUE };

typedef struct {
  char key[MAX_CHAR];
  /* other fields, for example word */
  char word[50];
} element_t;

void init_table(element_t ht[]);
int hash(const char *key);

element_t findElement(element_t ht[], char key[]);
int insertItem(element_t ht[], element_t o);
int removeElement(element_t ht[], char key[]);

int size(element_t ht[]);

int isEmpty(element_t ht[]);

void clear(element_t ht[]);

void traverse(element_t ht[]);  // Duyet
