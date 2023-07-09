#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//data.h

typedef struct {
	char id[10];
	char name[30];
	float grade;
}  data_t;

//data.c

void showData(data_t data) { 
  printf("%s %s %g\n",data.id,data.name,data.grade);
}

data_t convert(char id[],char name[],float grade) {
  data_t data;
  strcpy(data.id,id);
  strcpy(data.name,name);
  data.grade=grade;
  return data;
}


// queue.h

typedef struct { 
   data_t elements[100];  //Store the elements 
   int front, rear; 
} queue_t;

//queue.c

queue_t *queueInit(queue_t *pQ) {
  pQ->front = -1;
  pQ->rear = -1;
  return pQ;
}

int isEmpty(const queue_t *pQ) { return pQ->front == -1; }

int isFull(const queue_t *pQ) {
  return (pQ->rear - pQ->front + 1) % 100 == 0;
}

queue_t *enqueue(queue_t *pQ, const data_t data) {
  if (isFull(pQ)) {
    printf("Queue is full!");
    return pQ;
  }

  if (isEmpty(pQ)) pQ->front = 0;
  pQ->rear = (pQ->rear + 1) % 100;
  pQ->elements[pQ->rear] = data;

  return pQ;
}

// to check
queue_t *dequeue(queue_t *pQ) {
  if (isEmpty(pQ)) {
    printf("Queue is empty!");
    return 1;
  }

  if (pQ->front > pQ->rear)
    queueInit(pQ);
  else
    pQ->front = (pQ->front + 1) % 100;

  return pQ;
}



data_t top(const queue_t *pQ) {
  if (isEmpty(pQ)) {
    printf("Queue is empty!");
  }
  return pQ->elements[pQ->front];
}


queue_t *dequeueData(queue_t *pQ, data_t *pData) {
  *pData = top(pQ);
  return dequeue(pQ);
}


// main.c

int main() {
  queue_t* pQ;
  data_t a[100],b[100];
  pQ = queueInit(pQ);


  return 0;
}

