#include "queue.h"

#include <stdlib.h>
void initialize(Queue *pQ) {
  pQ->Front = -1;
  pQ->Rear = -1;
}
int Empty_Queue(Queue Q) { return Q.Front == -1; }
int Full_Queue(Queue Q) { return (Q.Rear - Q.Front + 1) % MAX_LENGTH == 0; }
void EnQueue(ElementType X, Queue *pQ) {
  if (!Full_Queue(*pQ)) {
    if (Empty_Queue(*pQ)) pQ->Front = 0;
    pQ->Rear = (pQ->Rear + 1) % MAX_LENGTH;
    pQ->Elements[pQ->Rear] = X;
  } else
    printf("Queue is full!");
}
ElementType DeQueue(Queue *pQ) {
  if (!Empty_Queue(*pQ)) {
    ElementType retVal = pQ->Elements[pQ->Front];
    if (pQ->Front == pQ->Rear)
      initialize(pQ);
    else
      pQ->Front = (pQ->Front + 1) % MAX_LENGTH;

    return retVal;
  } else {
    printf("Queue is empty!");
    exit(-1);
  }
}
