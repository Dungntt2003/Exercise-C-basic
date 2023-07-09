#include <stdio.h>
#include "queue.h"

int main() {
  queue_t q = queueInit();
  // queueInit(&q);
  printf("Them du lieu vao stack (-1 de ket thuc):\n");

  data_t t;
  for (scanf("%d", &t); t != -1; scanf("%d", &t)) {
    q = enqueue(q, t);    
  }

  // Pop data from Stack and display to screen
  while (!isEmpty(q)) {
    showData(top(q));
    q = dequeue(q);
  }

  llDeleteAll(q.front);

  return 0;
}