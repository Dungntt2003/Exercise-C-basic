main: main.o bst.o
	gcc -o main main.o bst.o

main.o bst.o: bst.h
	gcc -c -g bst.c main.c