#ifndef __DATA_T_H__
#define __DATA_T_H__

#include <string.h>

typedef struct phoneAddr_s {
  char name[20];
  char tel[12];
  char email[28];
} phoneAddr_t;

typedef phoneAddr_t data_t;

typedef char* keyT;  // to find

void showData(data_t data);
data_t convert(char* name, char* tel, char* email);

// copy data
// void datcpy(data_t* pDst, data_t* pSrc);
// equal
int eq(const keyT key, const data_t* dat);
// less than
int lt(const keyT key, const data_t* dat);
// great than
int gt(const keyT key, const data_t* dat);

#endif