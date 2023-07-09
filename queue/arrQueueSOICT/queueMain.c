#include <stdio.h>
#include "queue.h"

int main() {
   Queue q;
   initialize(&q);

   for (int i = 0; i < 10; i++) 
      EnQueue(i, &q);

   for (int i = 0; i < 10; i++) {
      int t = DeQueue(&q);
      printf("%d ", t);
   }

   return 0;
}