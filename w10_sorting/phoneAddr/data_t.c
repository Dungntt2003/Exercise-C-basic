#include "data_t.h"
#include <stdio.h>
#include <string.h>

void swap(data_t *x, data_t *y) {
  data_t tmp = *x;
  *x = *y;
  *y = tmp;
}

void showData(const data_t data) {
  printf("{'%s','%s','%s'}", data.name, data.tel,
         data.email);
}

data_t convert(const char*const name, const char*const tel, const char*const email) {
  data_t tmp;
  strcpy(tmp.name, name);
  strcpy(tmp.tel, tel);
  strcpy(tmp.email, email);
  return tmp;
}

void cpyData(data_t* dst, const data_t*const src) {
  memcpy(dst, src, sizeof(data_t));
}

int eq(const keyT key, const data_t*const dat) {
  return (strcmp(key, dat->key) == 0);
}

// less than
int lt(const keyT key, const data_t*const dat) {
  return (strcmp(key, dat->key) < 0);
}

// great than
int gt(const keyT key, const data_t* const dat) {
  return (strcmp(key, (*dat).key) > 0);
}