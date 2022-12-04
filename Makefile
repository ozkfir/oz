CC=gcc
FLAGS=-Wall -g

all: my_mat.a

my_mat.so:my_mat.o
	$(CC) -shared -o my_mat.so my mat.o
my_mat.a:my_mat.o
	ar -rcs my_mat.a my_mat.o


my_mat.o:my_mat.c
	$(CC) $(FLAGS) -fPIC -c my_mat.c

main.o: main.c my_mat.h
	$(CC) $(FLAGS) -c main.c

.PHONY:clean all
clean:
	rm -f *.o *.a *.so