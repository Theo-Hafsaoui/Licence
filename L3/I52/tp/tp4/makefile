CC=g++
FLAG= -g -Wall 
OBJ= test.o Personne.o prof.o etudiant.o

test.exe: $(OBJ)
	$(CC) $(FLAG) $(OBJ) -o test.exe && ./test.exe

test.o: test.cpp Personne.h prof.h
	$(CC) -c $(FLAG) $<

Personne.o: Personne.cpp Personne.h
	$(CC) -c $(FLAG) $<

prof.o: prof.cpp prof.h
	$(CC) -c $(FLAG) $<

etudiant.o: etudiant.cpp etudiant.h
	$(CC) -c $(FLAG) $<
