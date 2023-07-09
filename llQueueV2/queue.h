#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include "llist.h"

enum {EXIT_QUEUE_OVERFLOW = 1, EXIT_QUEUE_UNDERFLOW , EXIT_QUEUE_EMPTY};

typedef struct {
  llst_t front;
  node_t *rear;
} queue_t;

queue_t queueInit();

int isEmpty(queue_t queue);
int isFull(queue_t queue);

queue_t enqueue(queue_t queue, const data_t data);
queue_t dequeue(queue_t queue);
queue_t dequeueData(queue_t queue, data_t *pData);

// Tra ve phan tu dau tien cua queue, khong loai phan tu nay khoi queue
data_t top(queue_t queue);

#endif