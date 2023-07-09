#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include "data_t.h"

#define MAX_LENGTH 100 

typedef struct { 
   data_t elements[MAX_LENGTH];  //Store the elements 
   int front, rear; 
} queue_t;

queue_t* queueInit(queue_t *pQ);
int isEmpty(const queue_t *pQ);
int isFull(const queue_t *pQ);
queue_t* enqueue(queue_t *pQ, const data_t data);
queue_t* dequeue(queue_t *pQ);
queue_t* dequeueData(queue_t *pQ, data_t *pData);
data_t top(const queue_t *pQ);

#endif