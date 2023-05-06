#Define  which  compiler  to use
COMPILER = gcc
# Define  which C standard  to use.
CSTD = --std=c18

MAIN = ../../CI/objects/bintree/bintreeM.o

PRE = ../../CI/objects/bintree/pretreeM.o

IN = ../../CI/objects/bintree/intreeM.o

POST = ../../CI/objects/bintree/posttreeM.o

REV = ../../CI/objects/bintree/revtreeM.o

all: bintree pretree intree posttree revtree


bintree: bintree.o $(MAIN)
	$(COMPILER) $(CSTD) bintree.o $(MAIN) -o bintree

bintree.o: bintree.c bintree.h
	$(COMPILER) $(CSTD) -c bintree.c

pretree: bintree.o $(PRE)
	$(COMPILER) $(CSTD) bintree.o $(PRE) -o pretree

intree: bintree.o $(IN)
	$(COMPILER) $(CSTD) bintree.o $(IN) -o intree

posttree: bintree.o $(POST)
	$(COMPILER) $(CSTD) bintree.o $(POST) -o posttree

revtree: bintree.o $(REV)
	$(COMPILER) $(CSTD) bintree.o $(REV) -o revtree


# Clean  rule.
clean:
	rm -f bintree.o  bintree pretree.o intree.o posttree.o revtree.o pretree intree posttree revtree