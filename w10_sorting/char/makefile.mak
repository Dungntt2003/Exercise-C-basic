main: sort.o sort.h main.o data_t.o
	gcc -o $@ sort.o main.o data_t.o

main.o: sort.h
	gcc -c -g main.c

sort.o: sort.h
	gcc -c -g sort.c

data_t.o: data_t.h
	gcc -c -g data_t.c