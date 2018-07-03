CC=gcc
COPTS=-g -Wall -std=c99

all: dk

clean:
	-rm -rf *.o *~ *.dSYM core

clobber:
	-rm -rf *.o *~ *.dSYM core dk

dk: dk.c
	$(CC) $(COPTS) $^ -o $@ -lm