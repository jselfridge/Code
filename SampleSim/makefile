
##~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
##  makefile - SampleSim Program
##  Justin M Selfridge
##~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

EXEC    = RunSampleSim
CC      = gcc
CFLAGS  = -c -Wall
LIB     = Libraries/libMat/libMat.a

DIR    := $(shell ls -F | grep "\/" )
NAME   := $(patsubst %/, %, $(DIR) )
OBJ    := $(foreach o, $(NAME), $(o)/$(o).o )

all : $(EXEC)

$(EXEC) : $(OBJ) $(LIB)
	$(CC) $(OBJ) -o $@ 

%.o : %/%.c %/%.h 
	$(CC) $(CFLAGS) %/%.c $< 

clean :
	rm $(OBJ) $(EXEC)


