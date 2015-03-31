
##~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
##  makefile - MatLib Library
##  Justin M Selfridge
##~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

EXEC = DemoMatLib
CC = gcc
CFLAGS = -c -Wall
DIR := $(shell ls -F | grep "\/" )
NAME := $(patsubst %/, %, $(DIR) )
OBJ := $(foreach o, $(NAME), $(o)/$(o).o )

all : $(EXEC)

##$(EXEC) : $(OBJ)
##	$(CC) $(OBJ) -o $@
$(EXEC) : TestMatLib.o Temp.o
	$(CC) TestMatLib.o Temp.o -o $@

##%.o : %/%.c %/%.h 
##	$(CC) $(CFLAGS) %/%.c $<

TestMatLib.o : TestMatLib.c
	$(CC) $(CFLAGS) TestMatLib.c
Temp.o : Temp.c Temp.h
	$(CC) $(CFLAGS) Temp.c Temp.h

##clean :
##	rm $(OBJ) $(EXEC)
clean :
	rm TestMatLib.o Temp.o DemoMatlib

