#Define  which  compiler  to use
COMPILER = gcc
# Define  which C standard  to use.
CSTD = --std=c18

MAIN = ../../CI/objects/search/searchM.o

DFS = ../../CI/objects/search/dfsM.o

BFS = ../../CI/objects/search/bfsM.o

INCLUDES = -I../search

LIBFLAGS = -l

all: search bfs dfs

search.o: bintree.c bintree.h
	$(COMPILER) $(CSTD) $(LIBFLAGS) $(INCLUDES) -c bintree.c
	mv bintree.o search.o

queue.o:queue.c queue.h
	$(COMPILER) $(CSTD) -c queue.c

stack.o:stack.c stack.h
	$(COMPILER) $(CSTD) -c stack.c

search: search.o $(MAIN) queue.o stack.o
	$(COMPILER) $(CSTD) search.o stack.o queue.o $(MAIN) -o search

bfs: search.o $(BFS)
	$(COMPILER) $(CSTD) search.o  stack.o queue.o $(BFS) -o bfs

dfs: search.o $(DFS)
	$(COMPILER) $(CSTD) search.o stack.o queue.o $(DFS) -o dfs



# Clean  rule.
clean:
	rm -f queue.o stack.o search.o  search bfs dfs
