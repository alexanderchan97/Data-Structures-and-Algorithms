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

bst: bst.c

linked-list: linked-list.c

.PHONY: clean
clean:
	rm -rf bst linked-list *.o

.PHONY: all
	bst linked-list
