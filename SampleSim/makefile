
##~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
##  makefile - SampleSim Program
##  Justin M Selfridge
##~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

EXEC    = RunSampleSim
CC      = gcc
CFLAGS  = -c -Wall
PATH    = ../../Libraries/
DEP     = $(PATH)MatLib/MatLib.h
LIB     = $(PATH)MatLib/libMat.a

#DIR    := $(shell ls -F | grep "\/" )
#NAME   := $(patsubst %/, %, $(DIR) )
#OBJ    := $(foreach o, $(NAME), $(o)/$(o).o )

all : $(EXEC)

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $@ $(LIB)
#$(EXEC) : SampleSim.o
#	$(CC) SampleSim.o -o $@ $(LIB) 

%.o : %/%.c %/%.h
	$(CC) $(CFLAGS) -I$(PATH)MatLib %/%.c $< 
#SampleSim.o : SampleSim.c SampleSim.h 
#	$(CC) $(CFLAGS) -I$(PATH)MatLib -c -o $@ $< 

clean :
	rm $(OBJ) $(EXEC)

