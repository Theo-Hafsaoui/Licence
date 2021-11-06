CC= g++
FLAG= -Wall -g
OBJ= albumMP3.o  main.o  musique.o  musiqueCompressee.o 
EX1= main.o  musique.o 

all:exam.exe

exam.exe:$(EX1)
	$(CC) $(FLAG) $^ -o $@

main.o: main.cc albumMP3.h musique.h musiqueCompressee.h 
	$(CC) $(FLAG) -c $<

musique.o: musique.cc musique.h
	$(CC) $(FLAG) -c $<

musiqueCompressee.o: musiqueCompressee.cc musiqueCompressee.h
	$(CC) $(FLAG) -c $<

albumMP3.o: albumMP3.cc albumMP3.h
	$(CC) $(FLAG) -c $<

