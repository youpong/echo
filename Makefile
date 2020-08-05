CC = gcc
CFLAGS = -g -Wall

TARGET = echo

.PHONY: all clean format check

all: $(TARGET)

clean:
	- rm -f *.o $(TARGET)
format:
	clang-format -i *.c

check: all
	./test.sh

echo: echo.o
