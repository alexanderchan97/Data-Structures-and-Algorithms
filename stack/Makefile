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
EXECUTABLES = stack-test

.PHONY: all
all: $(EXECUTABLES)

stack-test: stack-test.o stack.o

stack-test.o: stack-test.c

stack.o: stack.c stack.h

.PHONY: clean
clean:
	rm -rf $(EXECUTABLES) *.o

