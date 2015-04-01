
##~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
##  makefile - SampleSim Program
##  Justin M Selfridge
##~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

EXEC    = RunSampleSim
CC      = gcc
CFLAGS  = -c -Wall
LIB     = ../../Libraries/libMat/libMat.a
DEP     = ../../Libraries/libMat/MatLib.h

DIR    := $(shell ls -F | grep "\/" )
NAME   := $(patsubst %/, %, $(DIR) )
OBJ    := $(foreach o, $(NAME), $(o)/$(o).o )

all : $(EXEC)

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $@ $(LIB)

%.o : %/%.c %/%.h $(DEP) 
	$(CC) $(CFLAGS) %/%.c $< 

clean :
	rm $(OBJ) $(EXEC)


