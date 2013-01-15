# Makefile for a simple linked list implementation
# Justin Ethier, 2012
CC=gcc
CFLAGS=-g
ODIR=build

all: $(ODIR)/linked-list.o test
$(ODIR)/linked-list.o: linked-list.h linked-list.c
	mkdir -p $(ODIR)
	$(CC) -c linked-list.c -o $(ODIR)/linked-list.o $(CFLAGS)
test: $(ODIR)/linked-list.o test-linked-list.c
	$(CC) $(ODIR)/linked-list.o test-linked-list.c -o $(ODIR)/test-ll $(CFLAGS)
clean:
	rm -rf $(ODIR)
