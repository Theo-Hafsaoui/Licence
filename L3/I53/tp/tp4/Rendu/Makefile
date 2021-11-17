CC = gcc
CFLAGS = -Wall -g

all: af mygrep

mygrep: mygrep.o compregex.o afn.o afd.o pile.o file.o
	$(CC) $(CFLAGS) $^ -o $@

af:af.o afd.o afn.o pile.o file.o
	$(CC) $(CFLAGS) $^ -o $@

ex1:afd.o afn.o ex1.o pile.o file.o
	$(CC) $(CFLAGS) $^ -o $@ && ./ex1; rm ex1

union:afd.o afn.o ex2_u.o pile.o file.o
	$(CC) $(CFLAGS) $^ -o $@ && ./union; rm union

concat:afd.o afn.o ex2_c.o pile.o file.o
	$(CC) $(CFLAGS) $^ -o $@ && ./concat; rm concat

kleen:afd.o afn.o ex2_k.o pile.o file.o
	$(CC) $(CFLAGS) $^ -o $@ && ./kleen; rm kleen

grep: ex3.o compregex.o afn.o afd.o pile.o file.o
	$(CC) $(CFLAGS) $^ -o $@ && ./grep; rm grep

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

ex1.o: ./test/test_ex1.c
	$(CC) -c $(CFLAGS) $< -o $@

ex2_u.o: ./test/test_ex2_union.c
	$(CC) -c $(CFLAGS) $< -o $@

ex2_c.o: ./test/test_ex2_concat.c
	$(CC) -c $(CFLAGS) $< -o $@

ex2_k.o: ./test/test_ex2_kleen.c
	$(CC) -c $(CFLAGS) $< -o $@

ex3.o: ./test/ex3_grep.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f *.o *~ *.bak

lint:
	indent -kr -ts4 *.c
