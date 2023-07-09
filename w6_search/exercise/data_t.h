#ifndef __DATA_T_H__
#define __DATA_T_H__

typedef struct {
  char name[20], tel[20], email[32];
} mobAdd_t;

    typedef mobAdd_t data_t;

// Must Adapt to new problem
void showData(const data_t data);
// data_t convert(int i);

#endif