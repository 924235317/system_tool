CC=gcc
OPT=-std=c++11 -w -g

SRC=main.c get_cpuinfo.c
OBJ=$(SRC:.cpp=.o)
EXE=bin

all:$(OBJ)
	$(CC) $(OBJ) -o $(EXE)

get_cpuinfo.o:
	$(CC) -c get_cpuinfo.c
main.o:
	$(CC) -c main.cpp

clean:
	rm -rf $(EXE)   
