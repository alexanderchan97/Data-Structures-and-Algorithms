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
EXECUTABLES = rb_tree-test

.PHONY: all
all: $(EXECUTABLES)

rb_tree-test: rb_tree-test.o rb_tree.o

rb_tree-test.o: rb_tree-test.c

rb_tree.o: rb_tree.c rb_tree.h

.PHONY: clean
clean:
	rm -rf $(EXECUTABLES) *.o

