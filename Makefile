CC = gcc
CXX = clang

INCLUDES = 

# Compilation options
CFLAGS = -g -Wall $(INCLUDES)
CXXFLAGS = -g -Wall $(INCLUDES)

# Linking options
LDFLAGS = -g

# Libraries
LDLIBS = 

# Executables
<<<<<<< HEAD
EXECUTABLES = vector-test
=======
EXECUTABLES = bst linked-list queue stack vector graph-adj-list
>>>>>>> 339c22c29a744518f9e0afb5c2f802a83a85561a

.PHONY: all
all: $(EXECUTABLES)

<<<<<<< HEAD
vector-test: vector-test.o vector.o

vector-test.o: vector-test.c

vector.o: vector.c vector.h
=======
bst: bst.c

linked-list: linked-list.c

queue: queue.c

stack: stack.c

vector: vector.c

graph-adj-list: graph-adj-list.c
>>>>>>> 339c22c29a744518f9e0afb5c2f802a83a85561a

.PHONY: clean
clean:
	rm -rf $(EXECUTABLES) *.o

