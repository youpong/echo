CFLAGS = -g -Wall

all: echo

clean:
	- rm -f *.o echo
format:
	clang-format -i *.c
echo: echo.o
