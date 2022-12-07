CC=gcc
FLAGS=-Wall -g

all: my_mat.a connections


my_mat.a:my_mat.o
	ar -rcs my_mat.a my_mat.o

connections:main.o my_mat.o
	$(CC) $(FLAGS) -fPIC -o connections main.o my_mat.o

my_mat.o:my_mat.c
	$(CC) $(FLAGS) -fPIC -c my_mat.c

main.o: main.c my_mat.h
	$(CC) $(FLAGS) -c main.c

.PHONY:clean all
clean:
	rm -f *.o *.a connections