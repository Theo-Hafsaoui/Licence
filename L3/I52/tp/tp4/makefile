CC=G++
FLAG= -Wall
OBJ= test.o Personne.o

test.exe: $(OBJ)
	$(CC) $(FLAG) $^

test.o: test.cpp Personne.h
	$(CC) $(FLAG) $<

Personne.o: Personne.cpp Personne.h
	$(CC) $(FLAG) $<