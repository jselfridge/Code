
##~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
##  GNU C++ Project Template
##  Justin M Selfridge
##  makefile
##  Source and header files located in a directory with same name
##~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

EXEC = ProgramName
CC = g++
CFLAGS = -c -Wall
DIR := $(shell ls -F | grep "\/" )
NAME := $(patsubst %/, %, $(DIR) )
OBJ := $(foreach o, $(NAME), $(o)/$(o).o )

all : $(EXEC)

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $@

%.o : %/%.cpp %/%.h 
	$(CC) $(CFLAGS) %/%.cpp $<

clean :
	rm $(OBJ) $(EXEC)



