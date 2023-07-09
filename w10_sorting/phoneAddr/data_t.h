#ifndef __DATA_T_H__
#define __DATA_T_H__

#include <string.h>

typedef struct phoneAddr_s {
  char name[20];
  char tel[12];
  union {
    char email[28];
    char key[28];
  };
} phoneAddr_t;

typedef phoneAddr_t data_t;
typedef char* keyT;

void swap(data_t *x, data_t *y);
void showData(data_t data);
data_t convert(const char* const name, const char* const tel,
               const char* const email);

// equal
int eq(const keyT key, const data_t* const dat);
// less than
int lt(const keyT key, const data_t* const dat);
// great than
int gt(const keyT key, const data_t* const dat);

#endif