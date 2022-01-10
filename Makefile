CC=gcc
AR=ar
FLAGS= -Wall -g

all: graph

graph: main.o Node.o Edge.o Graph.o 
	$(CC) $(FLAGS) -o graph main.o Node.o Edge.o Graph.o 
main.o: main.c Graph.h Edge.h Node.h
	$(CC) $(FLAGS) -c main.c
Graph.o: Graph.c Graph.h Edge.h Node.h
	$(CC) $(FLAGS) -c Graph.c
Node.o: Node.c Graph.h Node.h
	$(CC) $(FLAGS) -c Node.c
Edge.o: Edge.c Graph.h Edge.h Node.h
	$(CC) $(FLAGS) -c Edge.c
.PHONY: clean all
clean:
	rm -f *.o *.a *.so graph