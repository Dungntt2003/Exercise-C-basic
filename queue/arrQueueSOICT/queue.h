#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>

#define MAX_LENGTH 100 

typedef int ElementType;

typedef struct { 
   ElementType Elements[MAX_LENGTH];  //Store the elements 
   int Front, Rear; 
} Queue;

void initialize(Queue *pQ);
int Empty_Queue(Queue Q);
int Full_Queue(Queue Q);
void EnQueue(ElementType X, Queue *pQ);
ElementType DeQueue(Queue *pQ);

#endif