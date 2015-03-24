
##~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
##  Runge-Kutta-Fehlberg ODE Solver
##  Justin M Selfridge
##  makefile
##~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

EXEC = RunRKF
CC = gcc
CFLAGS = -c -Wall
DIR := $(shell ls -F | grep "\/" )
NAME := $(patsubst %/, %, $(DIR) )
OBJ := $(foreach o, $(NAME), $(o)/$(o).o )

all : $(EXEC)

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $@

%.o : %/%.c %/%.h 
	$(CC) $(CFLAGS) %/%.cpp $<

clean :
	rm $(OBJ) $(EXEC)


