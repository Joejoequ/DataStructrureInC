#Define  which  compiler  to use
COMPILER = gcc
# Define  which C standard  to use.
CSTD = --std=c18
MAIN = ../../CI/objects/stack/stackM.o
stack: stack.o $(MAIN)
	$(COMPILER) $(CSTD) stack.o $(MAIN) -o stack

stack.o: stack.c stack.h
	$(COMPILER) $(CSTD) -c stack.c


# Clean  rule.
clean:
	rm -f stack.o  stack