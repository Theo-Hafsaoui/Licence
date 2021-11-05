CC=g++
FLAG= -Wall -g
OBJ= film.o recompense.o meilleursFilms.o main.o

all:main.exe

main.exe: film.o recompense.o main.o meilleursFilms.o
	$(CC) $(FLAG) $^ -o main.exe

film.o:film.cc film.h
	$(CC) -c $(FLAG) $<

recompense.o:recompense.cc recompense.h
	$(CC) -c $(FLAG) $<

meilleurFilms.o:meilleursFilms.cc meilleursFilms.h
	$(CC) -c $(FLAG) $<

main.o:main.cc film.h recompense.h meilleursFilms.h
	$(CC) -c $(FLAG) $<
