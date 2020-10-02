# choose your compiler
CC=gcc
# CC=gcc -Wall

mysh: get_path.o shell-with-builtin.o which.o
	$(CC) -g shell-with-builtin.o get_path.o which.o -o mysh

shell-with-builtin.o: shell-with-builtin.c sh.h
	$(CC) -g -c shell-with-builtin.c

which.o: which.c
	$(CC) -g -c which.c

get_path.o: get_path.c get_path.h
	$(CC) -g -c get_path.c

clean:
	rm *.o mysh
