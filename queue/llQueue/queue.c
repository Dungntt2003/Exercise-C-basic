#include <stdlib.h>
#include "queue.h"

// root_t llInit();
queue_t queueInit() { return llInit(); }

int isEmpty(queue_t q) { return q == NULL; }

int isFull(queue_t q) { return 0; }

// todo: modify
queue_t enqueue(queue_t q, const data_t data) {
  return llInsertTail(q, data); // <===
 }

queue_t dequeue(queue_t q) {
  return llDeleteHead(q);       // <===
}

queue_t dequeueData(queue_t q, data_t *pData) {
  *pData = top(q);
  return dequeue(q);
}

data_t top(queue_t q) {
  if (isEmpty(q)) {
    printf("ERROR: Empty Queue!!!\n");
    exit(EXIT_QUEUE_EMPTY);
  }
  data_t data = q->data;
  return data;
}