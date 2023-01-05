CC=gcc
FLAGS=-Wall -g

all:isort txtfind mainsort.a maintxt.a


mainsort.a:mainsort.o
	ar -rcs mainsort.a mainsort.o
maintxt.a:maintxt.o
	ar -rcs maintxt.a maintxt.o
isort:mainsort.o
	$(CC) $(FLAGS) -fPIC -o isort mainsort.o
txtfind:maintxt.o
	$(CC) $(FLAGS) -fPIC -o txtfind maintxt.o

maintxt.o: maintxt.c
	$(CC) $(FLAGS) -c maintxt.o maintxt.c
mainsort.o: mainsort.c
	$(CC) $(FLAGS) -c mainsort.o mainsort.c

.PHONY:clean all
clean:
	rm -f *.o *.a isort txtfind