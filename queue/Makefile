#Define  which  compiler  to use
COMPILER = gcc
# Define  which C standard  to use.
CSTD = --std=c18
MAIN = ../../CI/objects/queue/queueM.o
queue: queue.o $(MAIN)
	$(COMPILER) $(CSTD) queue.o $(MAIN) -o queue

queue.o: queue.c queue.h
	$(COMPILER) $(CSTD) -c queue.c


# Clean  rule.
clean:
	rm -f queue.o  queue