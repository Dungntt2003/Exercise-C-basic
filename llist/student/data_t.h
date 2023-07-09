#ifndef __DATA_T_H__
#define __DATA_T_H__

// Must Adapt to new problem
typedef struct {
  char id[16];
  char name[40];
  int grade;
} data_t;

// Must Adapt to new problem
void showData(const data_t data);
data_t convert(char id[], char name[], int grade);

#endif