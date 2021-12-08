CC=gcc
FLAG= -Wall -g -Werror -Wextra -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wwrite-strings -Wunreachable-code
OBJ= io.o graph.o stack.o connected.o color.o ACM.o eulerian.o

libgraph.a: $(OBJ)
	ar -cr libgraph.a $^
graphe.o: graph.c graph.h io.h
	gcc $(FLAG) -c $<
inout.o: io.c io.h
	gcc $(FLAG) -c $<
stack.o: stack.c stack.h
	gcc $(FLAG) -c $<
connected.o: connected.c connected.h
	gcc $(FLAG) -c $<
color.o: color.c color.h
	gcc $(FLAG) -c $<
ACM.o: ACM.c ACM.h
	gcc $(FLAG) -c $<
eulerian.o: eulerian.c eulerian.h
	gcc $(FLAG) -c $<

test:test.exe
	./test.exe
test.exe:Test.o stack.o
	$(CC) $(FLAG) Test.o stack.o -o test.exe
Test.o:Test.c
	gcc -c $(FLAG) ./Test.c
