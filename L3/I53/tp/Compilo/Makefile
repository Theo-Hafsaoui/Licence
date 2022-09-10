CC=gcc
CFLAGS= -Wall -g
OBJ=ts.o asa.o parser.o lexer.o

all: arc

comparaison.ram: arc comp.algo
	./arc comp.algo

exemple.ram: arc exemple.algo
	./arc exemple.algo

test: arc exemple.ram
	nl -v0 -b p"^[^;]" exemple.ram

arc : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) -lfl

asa.o: asa.c

*.o: *.c

parser.h: parser.y

parser.c: parser.y asa.o
	bison -o $@ -d $<

lexer.c: lexer.lex parser.h
	flex -o  $@ $^

clean:
	rm -rf *~ *.o lexer.c parser.c parser.h
