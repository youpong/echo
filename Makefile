CC = gcc
CFLAGS = -g -Wall -std=c17

TARGET = echo

.PHONY: all clean format check

all: $(TARGET)

clean:
	- rm -f *.o $(TARGET) test
format:
	clang-format -i *.c

check: all test
	./test

echo: echo.o
