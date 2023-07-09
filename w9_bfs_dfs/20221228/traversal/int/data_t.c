#include <stdio.h>
#include "data_t.h"

void showData(data_t data) {
  printf(" %d ", data);
}

data_t convert(int number) { return number; }



int eq(const keyT key, const data_t* dat) {
  return (key == *dat);
}

// less than
int lt(const keyT key, const data_t* dat) {
  return (key < *dat);
}

// great than
int gt(const keyT key, const data_t* dat) {
  return (key > *dat);
}