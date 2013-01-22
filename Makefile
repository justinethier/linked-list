# Makefile for a simple linked list implementation
# https://github.com/justinethier/linked-list
#
# Justin Ethier, 2012
#
# References:
#  http://www.adp-gmbh.ch/cpp/gcc/create_lib.html
#  http://tldp.org/HOWTO/Program-Library-HOWTO/shared-libraries.html
#
AR=ar
CC=gcc
CFLAGS=-g
ODIR=build

obj = linked-list.o
lib_a = libllist.a
lib_so = libllist.so

#_LIB = $(lib_so)
#LIB = $(patsubst %,$(ODIR)/%,$(_LIB))

#TODO: should be specified via configure
PREFIX=/usr/local

all: $(ODIR)/$(lib_so) $(ODIR)/$(lib_a)

$(ODIR)/$(obj): linked-list.h linked-list.c
	mkdir -p $(ODIR)
	$(CC) -fPIC -Wall -c linked-list.c -o $@

$(ODIR)/$(lib_so): $(ODIR)/$(obj)
	$(CC) -shared $< -o $(ODIR)/$(lib_so) $(CFLAGS)

$(ODIR)/$(lib_a): $(ODIR)/$(obj)
	$(AR) rcs $(ODIR)/$(lib_a) $<

$(ODIR)/test-ll: $(ODIR)/$(lib_so)
	$(CC) -Wall test-linked-list.c -L$(ODIR) -lllist -o $(ODIR)/test-ll $(CFLAGS)

unittest: $(ODIR)/test-ll
	LD_LIBRARY_PATH=$(ODIR):$LD_LIBRARY_PATH $(ODIR)/test-ll

test: $(ODIR)/test-ll
	$(ODIR)/test-ll

.PHONY: install
install:
	cp linked-list.h $(PREFIX)/include/linked-list.h
	cp $(ODIR)/$(lib_so) $(PREFIX)/lib/$(lib_so)
	cp $(ODIR)/$(lib_a) $(PREFIX)/lib/$(lib_a)
	ldconfig

.PHONY: uninstall
uninstall:
	rm -f $(PREFIX)/include/linked-list.h
	rm -f $(PREFIX)/lib/$(lib_so)
	rm -f $(PREFIX)/lib/$(lib_a)
	ldconfig

clean:
	rm -rf $(ODIR)
