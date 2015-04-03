
##~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
##  makefile - SampleSim Program
##  Justin M Selfridge
##~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

EXEC   = RunSampleSim
CC     = gcc
CFLAGS = -c -Wall

DIR  := $(shell ls -F | grep "\/" )
NAME := $(patsubst %/, %, $(DIR) )
OBJ  := $(foreach o, $(NAME), $(o)/$(o).o )

LIBPATH = ../../Libraries/
MATLIB  = $(LIBPATH)MatLib/libMat.a
ROTLIB  = $(LIBPATH)RotLib/libRot.a

all : $(EXEC)

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $@ $(MATLIB) $(ROTLIB)

%/%.o : %/%.c %/%.h 
	$(CC) $(CFLAGS) %/%.c $<

clean :
	rm $(OBJ) $(EXEC)


