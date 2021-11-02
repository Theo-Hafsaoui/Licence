CC= gcc
FLAG= -Wall -g 
OBJ= backt.o main.o

all:main.exe

main.exe:$(OBJ)
	$(CC) $(FLAG) $^ -o $@

backt.o: backt.c backt.h
	$(CC) -c $(FLAG) $< -o $@

main.o: main.c backt.h
	$(CC) -c $(FLAG) $< -o $@
