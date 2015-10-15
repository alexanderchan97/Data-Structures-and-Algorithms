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
EXECUTABLES = bst linked-list queue stack

.PHONY: all
all: $(EXECUTABLES)

bst: bst.c

linked-list: linked-list.c

queue: queue.c

stack: stack.c

.PHONY: clean
clean:
	rm -rf $(EXECUTABLES) *.o

