#Define  which  compiler  to use
COMPILER = gcc
# Define  which C standard  to use.
CSTD = --std=c18

MAIN = ../../CI/objects/dictionary/dictM.o

dictionary: dictionary.o $(MAIN) bintree.o queue.o array_list.o stack.o
	$(COMPILER) $(CSTD) stack.o dictionary.o bintree.o array_list.o queue.o $(MAIN) -o dictionary

dictionary.o: dictionary.c dictionary.h
	$(COMPILER) $(CSTD)  -c dictionary.c

bintree.o:bintree.c bintree.h
	$(COMPILER) $(CSTD) -c bintree.c

array_list.o:array_list.c array_list.h
	$(COMPILER) $(CSTD) -c array_list.c

queue.o:queue.c queue.h
	$(COMPILER) $(CSTD) -c queue.c

stack.o:stack.c stack.h
	$(COMPILER) $(CSTD) -c stack.c


dictionary: dictionary.o $(MAIN) bintree.o queue.o array_list.o stack.o
	$(COMPILER) $(CSTD) stack.o dictionary.o bintree.o array_list.o queue.o $(MAIN) -o dictionary




# Clean  rule.
clean:
	rm -f *.o
	rm -f dictionary
