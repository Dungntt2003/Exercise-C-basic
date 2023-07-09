#ifndef __DATA_T_H__
#define __DATA_T_H__

typedef int data_t;
typedef int keyT;  // to find

void showData(data_t data);
data_t convert(int number);

int eq(const keyT key, const data_t* dat);
// less than
int lt(const keyT key, const data_t* dat);
// great than
int gt(const keyT key, const data_t* dat);

#endif