CC = gcc
OBJ=af.o afd.o afn.o
CFLAGS = -Wall -g

all: af

af: af.o afd.o afn.o
	$(CC) $(CFLAGS) $^ -o $@ 

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f *.o *~
