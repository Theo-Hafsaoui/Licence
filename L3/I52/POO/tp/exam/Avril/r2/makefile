CC=g++
FLAG= -g -Wall
OBJ= musique.o musiqueCompressee.o main.o albumMP3.o
EX1= musique.o main.o
EX2= musique.o main.o musiqueCompressee.o

exam.exe:$(OBJ)
	$(CC) $(FLAG) $^ -o exam.exe

musique.o: musique.cc musique.h
	$(CC) -c $(FLAG) $< 

musiqueCompressee.o: musiqueCompressee.cc musiqueCompressee.h
	$(CC) -c $(FLAG) $< 

albumMP3.o: albumMP3.cc albumMP3.h
	$(CC) -c $(FLAG) $< 

main.o: main.cc albumMP3.h musiqueCompressee.h musique.h
	$(CC) -c $(FLAG) $< 
