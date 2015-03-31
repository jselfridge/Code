
##~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
##  makefile - MatLib Library
##  Justin M Selfridge
##~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

EXEC = DemoMatLib
CC = gcc
CFLAGS = -c -Wall
##DIR := $(shell ls -F | grep "\/" )
##NAME := $(patsubst %/, %, $(DIR) )
##OBJ := $(foreach o, $(NAME), $(o)/$(o).o )

all : $(EXEC)

##$(EXEC) : $(OBJ)
##	$(CC) $(OBJ) -o $@
##$(EXEC) : TestMatLib.o Temp.o
##	$(CC) TestMatLib.o Temp.o -o $@
$(EXEC) :     TestMatLib.o MatIO.o MatManip.o MatArith.o MatProp.o MatDecomp.o
	$(CC) TestMatLib.o MatIO.o MatManip.o MatArith.o MatProp.o MatDecomp.o -o $@
##$(EXEC) :     TestMatLib.o MatIO.o MatManip.o MatArith.o MatProp.o MatDecomp.o
##	$(CC) TestMatLib.o MatIO.o MatManip.o MatArith.o MatProp.o MatDecomp.o -o $@

##%.o : %/%.c %/%.h 
##	$(CC) $(CFLAGS) %/%.c $<
TestMatLib.o : TestMatLib.c
	$(CC) $(CFLAGS) TestMatLib.c
MatIO.o : MatIO.c MatIO.h
	$(CC) $(CFLAGS) MatIO.c MatIO.h
MatManip.o : MatManip.c MatManip.h
	$(CC) $(CFLAGS) MatManip.c MatManip.h
MatArith.o : MatArith.c MatArith.h
	$(CC) $(CFLAGS) MatArith.c MatArith.h
MatProp.o : MatProp.c MatProp.h
	$(CC) $(CFLAGS) MatProp.c MatProp.h
MatDecomp.o : MatDecomp.c MatDecomp.h
	$(CC) $(CFLAGS) MatDecomp.c MatDecomp.h
##Temp.o : Temp.c Temp.h
##	$(CC) $(CFLAGS) Temp.c Temp.h

##clean :
##	rm $(OBJ) $(EXEC)
clean :
	rm TestMatLib.o MatIO.o MatManip.o MatArith.o MatProp.o MatDecomp.o DemoMatlib
##clean :
##	rm TestMatLib.o MatIO.o MatManip.o MatArith.o MatProp.o MatDecomp.o DemoMatlib

