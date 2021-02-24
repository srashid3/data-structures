CC:=gcc
CFLAGS:=-Iinclude

SRC:=$(wildcard src/*.c)

all: demo

demo: demo.c $(SRC)
	$(CC) -o demo $^ $(CFLAGS)

clean:
	rm -f demo
