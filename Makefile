CC:=gcc
CFLAGS:=-Iinclude -std=c11

SRC:=$(wildcard src/*.c)

all: demo

demo: demo.c $(SRC)
	$(CC) -o demo $^ $(CFLAGS)

clean:
	rm -f demo
