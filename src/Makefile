.PHONY: clean, mrproper

.SUFFIXES:

CC = gcc
CFLAGS = -std=c99 -g

all: main.c view.o parse.o other_functions.o
	$(CC) $^ -o ascii_art $(CFLAGS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -rf *.bak rm -rf *.o

mrproper: clean
	rm -rf ascii_art
