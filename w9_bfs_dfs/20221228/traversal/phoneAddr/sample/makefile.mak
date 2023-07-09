main: main.o bst.o bst_traversal.o stack.o queue.o
	gcc -o $@ data_t.o bst.o stack.o queue.o bst_traversal.o main.o

main.o: bst_traversal.o
	gcc -c -g main.c

bst_traversal.o: ../bst_traversal.h stack.o queue.o
	gcc -c -g ../bst_traversal.c

queue.o: ../bst.h ../data_t.h ../queue.h data_t.o
	gcc -c -g ../queue.c

stack.o: ../data_t.h ../bst.h ../stack.h bst.o
	gcc -c -g ../stack.c

bst.o: ../bst.h ../data_t.h data_t.o
	gcc -c -g ../bst.c

data_t.o: ../data_t.h
	gcc -c -g ../data_t.c