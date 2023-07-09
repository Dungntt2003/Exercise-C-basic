sum: main.o sum.o
	gcc -o $@ main.o sum.o

main.o sum.o: sum.h
	gcc -c $*.c