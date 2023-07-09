#include "hash.h"

#include <string.h>

static element_t hashtable[TABLE_SIZE];  // <===
static int N = 0;

// Hash Code Maps
// Component Sum
static const int transform(const int key) { return key % 10; }

// Compression map
int hash(const int key) { return (transform(key) % TABLE_SIZE); }

// ====================================
//
// ====================================

void init_table() {  // <===
  for (int i = 0; i < TABLE_SIZE; i++) hashtable[i].key = NULLKEY;
  N = 0;  // so nut hien co khoi dong bang 0
}

// Check the state of table
static const int full() { return (N == TABLE_SIZE - 1 ? 1 : 0); }

static const int empty() { return (N == 0 ? 1 : 0); }

// tra ve chi so cua phan tu neu tim thay
// tra ve TABLE_SIZE neu khong tim thay
int findElement(const int k) {
  int i = hash(k);
  // your code here
  
}

// tra ve 1 neu thanh cong, 0 neu that bai 
int insertItem(const int k) {  
  // your code here
  
}

int removeElement(int i) {
  int j, r, a, cont = 1;
  do {
    hashtable[i].key = NULLKEY;
    j = i;
    do {
      i = i + 1;
      if (i >= TABLE_SIZE) i = i - TABLE_SIZE;
      if (hashtable[i].key == NULLKEY)
        cont = 0;
      else {
        r = hash(hashtable[i].key);
        a = (j < r && r <= i) || (r <= i && i < j) || (i < j && j < r);
      }
    } while (cont && a);
    if (cont) hashtable[j].key = hashtable[i].key;
  } while (cont);
}

void traverse() {
  for (int b = 0; b < TABLE_SIZE; b++) {
    if (hashtable[b].key != NULLKEY) {
      printf("\n(i, key) = (%d, %d)\n", b, hashtable[b].key);
    }
  }
}