CC = gcc
CFLAGS = -Iinclude -Wall

# Source files
SRCS = src/main.c src/lexer.c src/parser.c src/codegen.c
# Output binary
TARGET = bin/compiler

all: clean build

build:
	mkdir -p bin
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f bin/compiler