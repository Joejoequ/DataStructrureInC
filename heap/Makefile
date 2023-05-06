#Define  which  compiler  to use
COMPILER = gcc
# Define  which C standard  to use.
CSTD = --std=c18

HEAP = ../../CI/objects/heap/heapM.o

RHEAP = ../../CI/objects/heap/rheapM.o



all: heap rheap


heap: heap.o $(HEAP) array_list.o
	$(COMPILER) $(CSTD) array_list.o heap.o $(HEAP) -o heap
rheap: heap.o $(RHEAP) array_list.o
	$(COMPILER) $(CSTD) array_list.o heap.o $(RHEAP) -o rheap

heap.o: heap.c heap.h
	$(COMPILER) $(CSTD) -c heap.c

array_list.o: array_list.c array_list.h
	$(COMPILER) $(CSTD) -c array_list.c

# Clean  rule.
clean:
	rm -f *.o heap rheap 