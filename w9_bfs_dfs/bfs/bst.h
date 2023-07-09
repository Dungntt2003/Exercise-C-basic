#ifndef __BST_H__
#define __BST_H__

#define MAX_STACK_SIZE 100

typedef struct phoneAddr_s {
  char name[20];
  char tel[12];
  union {
    char email[28];
    char key[28];
  };
} phoneAddr_t;

typedef phoneAddr_t data_t;  // specify a type for the data

typedef char *keyT;

typedef struct node_s {
  data_t data;
  struct node_s *left;
  struct node_s *right;
} node_t;

typedef node_t *tree_t;

tree_t search(keyT x, tree_t root);
void insertNode(data_t x, tree_t *pRoot);
keyT deleteMin(tree_t *pRoot);
void deleteNode(keyT x, tree_t *pRoot);
void prettyPrint(tree_t tree);
void freeTree(tree_t tree);


#define MAX_LENGTH 100 

typedef struct { 
   tree_t elements[MAX_LENGTH];  //Store the elements 
   int Front, Rear; 
} Queue;

void initialize(Queue *pQ);
int Empty_Queue(Queue Q);
int Full_Queue(Queue Q);
void EnQueue(tree_t X, Queue *pQ);
tree_t DeQueue(Queue *pQ);

#endif