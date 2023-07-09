#include <stdio.h>
#include <string.h>
#include "data_t.h"

void showData(data_t data) { 
  printf("%s - %s - %d\n", data.id, data.name, data.grade);
}

data_t convert(char id[], char name[], int grade) {
  data_t data;
  strcpy(data.id, id);
  strcpy(data.name, name);
  data.grade = grade;
  return data;
}