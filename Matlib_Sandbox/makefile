
##~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
##  makefile - Matlib Library Development
##  Justin M Selfridge
##~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

EXEC = Demo_Matlib
CC = gcc
CFLAGS = -c -Wall
DIR := $(shell ls -F | grep "\/" )
NAME := $(patsubst %/, %, $(DIR) )
OBJ := $(foreach o, $(NAME), $(o)/$(o).o )

##all : $(EXEC)
all : Demo_Matlib

##$(EXEC) : $(OBJ)
##	$(CC) $(OBJ) -o $@
Demo_Matlib : Main.o Temp.o
	gcc Main.o Temp.o -o $@

##%.o : %/%.c %/%.h 
##	$(CC) $(CFLAGS) %/%.c $<

Main.o : Main.c
	gcc -c -Wall Main.c
Temp.o : Temp.c Temp.h
	gcc -c -Wall Temp.c Temp.h

##clean :
##	rm $(OBJ) $(EXEC)
clean :
	rm Main.o Temp.o Demo_Matlib

