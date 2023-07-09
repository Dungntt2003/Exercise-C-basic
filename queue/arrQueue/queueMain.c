#include <stdio.h>

#include "queue.h"

int main() {
  queue_t* pQ;
  pQ = queueInit(pQ);

  for (int i = 0; i < 10; i++) enqueue(pQ, i);

  for (int i = 0; i < 10; i++) {
    int t = top(pQ);
    dequeue(pQ);
    printf("%d ", t);
  }

  return 0;
}