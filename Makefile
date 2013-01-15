# Makefile for a simple linked list implementation
# Justin Ethier, 2012

build/linked-list.o: linked-list.h linked-list.c
	mkdir -p build
	gcc -c linked-list.c -o build/linked-list.o
test: build/linked-list.o test-linked-list.c
	gcc build/linked-list.o test-linked-list.c -o build/test-ll
#	build/test-ll
clean:
	rm -rf test-ll *.o build
