CC = gcc
OBJ=af.o afd.o afn.o lexer.o parser.o
CFLAGS = -Wall -g

all: af

af: af.o afd.o afn.o lexer.o parser.o
	$(CC) $(CFLAGS) $^ -o $@ 

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f *.o *~
