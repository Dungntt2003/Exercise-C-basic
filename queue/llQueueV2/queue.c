#include <stdlib.h>
#include "queue.h"

// root_t llInit();
queue_t queueInit() {
  queue_t q;
  q.front = llInit();
  q.rear = NULL;      // <===
  return q;
}

int isEmpty(queue_t q) { return q.front == NULL; }

int isFull(queue_t q) { return 0; }

// ================================================
// Da duoc sua doi so voi phien ban truoc
// Noi dung sua doi: cap nhat su dung rear
// ================================================
queue_t enqueue(queue_t q, const data_t data) {
  if (isEmpty(q)) 
    q.rear = q.front = llInsertHead(q.front, data); // <=== 
  else {
    q.rear->next = createNewNode(data);
    q.rear = q.rear->next;  // <===
  }

  return q;
}

queue_t dequeue(queue_t q) {
  q.front = llDeleteHead(q.front);
  if (isEmpty(q)) q.rear = NULL; // <===
  return q;
}
// ================================================

queue_t dequeueData(queue_t q, data_t *pData) {
  *pData = top(q);
  return dequeue(q);
}

data_t top(queue_t q) {
  if (isEmpty(q)) {
    printf("ERROR: Empty Queue!!!\n");
    exit(EXIT_QUEUE_EMPTY);
  }
  data_t data = q.front->data;
  return data;
}