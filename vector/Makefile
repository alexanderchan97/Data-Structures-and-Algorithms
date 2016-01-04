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
EXECUTABLES = vector-test

.PHONY: all
all: $(EXECUTABLES)

vector-test: vector-test.o vector.o

vector-test.o: vector-test.c

vector.o: vector.c vector.h

.PHONY: clean
clean:
	rm -rf $(EXECUTABLES) *.o

