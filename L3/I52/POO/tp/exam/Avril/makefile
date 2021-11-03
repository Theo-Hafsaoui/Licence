CC=g++
FLAG= -Wall -g
OBJ= film.o recompense.o meilleurFilms.o main.o

all:main.exe

main.exe: film.o recompense.o meilleurFilms.o main.o
	$(CC) $(FLAG) $^ -o main.exe

film.o:film.cc film.h
	$(CC) -c $(FLAG) $<

recompense.o:recompense.cc recompense.h
	$(CC) -c $(FLAG) $<

meilleurFilms.o:meilleurFilms.cc meilleurFilms.h
	$(CC) -c $(FLAG) $<

main.o:main.cc film.h recompense.h meilleurFilms.h
	$(CC) -c $(FLAG) $<
