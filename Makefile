CFLAGS = -g

all: echo

clean:
	- rm -f *.o echo
echo: echo.o
