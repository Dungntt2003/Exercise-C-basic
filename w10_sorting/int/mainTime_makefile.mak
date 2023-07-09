mainTime: sort.o sort.h mainTime.o data_t.o utils.o
	gcc -o $@ sort.o mainTime.o data_t.o utils.o

mainTime.o: sort.h
	gcc -c -g mainTime.c

sort.o: sort.h
	gcc -c -g sort.c

data_t.o: data_t.h
	gcc -c -g data_t.c

utils.o: utils.h
	gcc -c -g utils.c