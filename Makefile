CFLAGS=	-Werror -Wall -pedantic -ansi -s -O3
LDFLAGS=-lX11
CC=gcc

dist:
	$(CC) $(CFLAGS) $(LDFLAGS) -o cpr main.c

clean:
	rm -f cpr

install:
	install -s cpr /usr/bin

uninstall:
	rm -f /usr/bin/cpr
