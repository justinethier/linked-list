# Makefile for a simple linked list implementation
# Justin Ethier, 2012
all: linked-list.h linked-list.c test-linked-list.c
	gcc linked-list.c test-linked-list.c -g -O0 -o test-ll
clean:
	rm -f test-ll *.o
