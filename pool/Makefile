#Define  which  compiler  to use
COMPILER = gcc
# Define  which C standard  to use.
CSTD = --std=c18

POOL = ../../CI/objects/pool/poolM.o



pool: pool.o $(POOL) array_list.o queue.o linked_list.o
	$(COMPILER) $(CSTD) array_list.o pool.o $(POOL) linked_list.o queue.o -o pool -lpthread


pool.o: pool.c pool.h
	$(COMPILER) $(CSTD) -c pool.c 

array_list.o: array_list.c array_list.h
	$(COMPILER) $(CSTD) -c array_list.c 

queue.o: queue.c queue.h
	$(COMPILER) $(CSTD) -c queue.c

linked_list.o: linked_list.c linked_list.h
	$(COMPILER) $(CSTD) -c linked_list.c

# Clean  rule.
clean:
	rm -f *.o pool