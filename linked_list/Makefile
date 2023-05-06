#Define  which  compiler  to use
COMPILER = gcc
# Define  which C standard  to use.
CSTD = --std=c18
MAIN = ../../CI/objects/linked_list/linkedM.o
linked_list: linked_list.o $(MAIN)
	$(COMPILER) $(CSTD) linked_list.o $(MAIN) -o linked_list

linked_list.o: linked_list.c linked_list.h
	$(COMPILER) $(CSTD) -c linked_list.c


# Clean  rule.
clean:
	rm -f linked_list.o linked_list