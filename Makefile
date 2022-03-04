GCC=gcc
GPP=g++
FLAGS =-pedantic -Wall

PROGS = Algorithm1 Algorithm2 Algorithm3 

all: Algorithm1 Algorithm2 Algorithm3
Algorithm1:
	$(GCC) $(FLAGS) $@.c -o $@
Algorithm2:
	$(GPP) $(FLAGS) $@.cpp -o $@
Algorithm3:
	$(GPP) $(FLAGS) $@.cpp -o $@
clean:
	$(RM) $(PROGS) 