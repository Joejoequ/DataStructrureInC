#Define  which  compiler  to use
COMPILER = gcc
# Define  which C standard  to use.
CSTD = --std=c18
MAIN = ../../CI/objects/array_list/arrayM.o
array_list: array_list.o $(MAIN)
	$(COMPILER) $(CSTD) array_list.o $(MAIN) -o array_list

array_list.o: array_list.c array_list.h
	$(COMPILER) $(CSTD) -c array_list.c


# Clean  rule.
clean:
	rm -f array_list.o  array_list