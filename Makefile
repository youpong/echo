CFLAGS = -g -Wall

.PHONY: all clean format test

all: echo

clean:
	- rm -f *.o echo
format:
	clang-format -i *.c

test: all
	./test.sh

echo: echo.o
