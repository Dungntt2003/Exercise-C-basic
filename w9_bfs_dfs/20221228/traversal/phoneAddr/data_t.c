#include "data_t.h"

#include <stdio.h>
#include <string.h>

// void showData(data_t data) {
//   printf("{name: '%s', tel: '%s', email: '%s'}", data.name, data.tel,
//          data.email);
// }

// Copy data
// void datcpy(data_t* pDst, const data_t* pSrc) { strcpy(pDst, pSrc); }

void showData(data_t data) {
  printf("{'%s','%s','%s'}", data.name, data.tel,
         data.email);
}

data_t convert(char* name, char* tel, char* email) {
  data_t tmp;
  strcpy(tmp.name, name);
  strcpy(tmp.tel, tel);
  strcpy(tmp.email, email);
  return tmp;
}

int eq(const keyT key, const data_t* dat) {
  return (strcmp(key, dat->email) == 0);
}

// less than
int lt(const keyT key, const data_t* dat) {
  return (strcmp(key, dat->email) < 0);
}

// great than
int gt(const keyT key, const data_t* dat) {
  return (strcmp(key, (*dat).email) > 0);
}