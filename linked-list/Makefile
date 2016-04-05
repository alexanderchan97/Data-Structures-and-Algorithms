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
EXECUTABLES = linked-list-test

.PHONY: all
all: $(EXECUTABLES)

linked-list-test: linked-list-test.o linked-list.o

linked-list-test.o: linked-list-test.c

linked-list.o: linked-list.c linked-list.h

.PHONY: clean
clean:
	rm -rf $(EXECUTABLES) *.o

