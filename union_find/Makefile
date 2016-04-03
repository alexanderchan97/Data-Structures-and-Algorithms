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
EXECUTABLES = union_find-test

.PHONY: all
all: $(EXECUTABLES)

union_find-test: union_find-test.o union_find.o

union_find-test.o: union_find-test.c

union_find.o: union_find.c union_find.h

.PHONY: clean
clean:
	rm -rf $(EXECUTABLES) *.o

