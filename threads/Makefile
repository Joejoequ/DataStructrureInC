#Define  which  compiler  to use
COMPILER = gcc
# Define  which C standard  to use.
CSTD = --std=c18

THREADS = ../../CI/objects/threads/threadsM.o

UNSAFE = ../../CI/objects/threads/unsafeM.o

SAFE = ../../CI/objects/threads/safeM.o



all: threads unsafe safe


threads: threads.o $(THREADS)
	$(COMPILER) $(CSTD) threads.o $(THREADS) -o threads -lpthread

threads.o: threads.c threads.h
	$(COMPILER) $(CSTD) -c threads.c 

unsafe: unsafe.o $(UNSAFE)
	$(COMPILER) $(CSTD) unsafe.o $(UNSAFE) -o unsafe -lpthread

unsafe.o: unsafe.c unsafe.h
	$(COMPILER) $(CSTD) -c unsafe.c 

safe: safe.o $(SAFE)
	$(COMPILER) $(CSTD) safe.o $(SAFE) -o safe -lpthread

safe.o: safe.c safe.h
	$(COMPILER) $(CSTD) -c safe.c 




# Clean  rule.
clean:
	rm -f *.o unsafe safe threads
