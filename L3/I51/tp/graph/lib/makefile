OPT =  -wall -g
OBJ =  inout.o graph.o

libgraphe.a : $(OBJ)
	ar crs libgraph.a $(OBJ)

inout.o : inout.h inout.c
	gcc $(OPT) -c inout.c

graph.o : graph.h graph.c
	gcc $(OPT) -c graph.c

connexe.o : connexe.h connexe.c graph.h
	gcc $(OPT) -c connexe.c

