CC=gcc
FLAG= -Wall -g -Werror -Wextra -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wwrite-strings -Wunreachable-code
OBJ= io.o graph.o

libgraph.a: $(OBJ)
	ar -cr libgraph.a $^
graphe.o: graph.c graph.h io.h
	gcc $(FLAGS) -c $<
inout.o: io.c io.h
	gcc $(FLAGS) -c $<


