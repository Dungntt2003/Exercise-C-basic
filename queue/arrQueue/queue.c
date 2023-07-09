#include "queue.h"

#include <stdlib.h>

queue_t *queueInit(queue_t *pQ) {
  pQ->front = -1;
  pQ->rear = -1;
  return pQ;
}

int isEmpty(const queue_t *pQ) { return pQ->front == -1; }

int isFull(const queue_t *pQ) {
  return (pQ->rear - pQ->front + 1) % MAX_LENGTH == 0;
}

queue_t *enqueue(queue_t *pQ, const data_t data) {
  if (isFull(pQ)) {
    printf("Queue is full!");
    return pQ;
  }

  if (isEmpty(pQ)) pQ->front = 0;
  pQ->rear = (pQ->rear + 1) % MAX_LENGTH;
  pQ->elements[pQ->rear] = data;

  return pQ;
}

// to check
queue_t *dequeue(queue_t *pQ) {
  if (isEmpty(pQ)) {
    printf("Queue is empty!");
    exit(-1);
  }

  if (pQ->front > pQ->rear)
    queueInit(pQ);
  else
    pQ->front = (pQ->front + 1) % MAX_LENGTH;

  return pQ;
}

queue_t *dequeueData(queue_t *pQ, data_t *pData) {
  *pData = top(pQ);
  return dequeue(pQ);
}

data_t top(const queue_t *pQ) {
  if (isEmpty(pQ)) {
    printf("Queue is empty!");
    exit(-1);
  }
  return pQ->elements[pQ->front];
}