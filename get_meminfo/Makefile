CC=gcc
OPT=-std=c++11 -w -g

SRC=main.c get_meminfo.c
OBJ=$(SRC:.cpp=.o)
EXE=bin

all:$(OBJ)
	$(CC) $(OBJ) -o $(EXE)

get_meminfo.o:
	$(CC) -c get_meminfo.c
main.o:
	$(CC) -c main.cpp

clean:
	rm -r $(EXE)
   
