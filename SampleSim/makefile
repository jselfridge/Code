
##~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
##  makefile - SampleSim Program
##  Justin M Selfridge
##~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

EXEC   = RunSampleSim
CC     = gcc
CFLAGS = -c -Wall

#SRCDIR = src
#INCDIR = inc
#OBJDIR = obj
LIBDIR = ../../Libraries/
MATLIB = $(LIBDIR)MatLib/libMat.a
ROTLIB = $(LIBDIR)RotLib/libRot.a

#SEARCH := $(shell find $(SRCDIR) -name '*.c')
#NAME := $(patsubst src/%.c, %, $(SEARCH) )
#OBJ  := $(foreach o, $(NAME), $(o).o )

#SRC := $(shell find $(SRCDIR) -name '*.c')
#INC := $(patsubst src/%.c, inc/%.h, $(SRC) )
#OBJ := $(patsubst scr/%.c, obj/%.o, $(SRC) )

all : $(EXEC)

$(EXEC) : obj/SampleSim.o obj/ODE.o
	$(CC) obj/SampleSim.o obj/ODE.o -o $@ $(MATLIB) $(ROTLIB)

#$(OBJDIR)/%.o : $(SRCDIR)/%.c $(INCDIR)/%.h 
#	$(CC) $(CFLAGS) $<

obj/SampleSim.o : src/SampleSim.c inc/SampleSim.h
	$(CC) $(CFLAGS) $<; mv SampleSim.o ./obj/;

obj/ODE.o : src/ODE.c inc/ODE.h
	$(CC) $(CFLAGS) $<; mv ODE.o ./obj/;

clean :
	rm $(EXEC) ./obj/*

#install :
#	@echo "$(SRC)"

