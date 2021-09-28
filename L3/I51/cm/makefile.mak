Myprog : matrix.o vecteur.o
	gcc -wall matrix.o 
	main.o vecteur.o -o Myprog
main.o: main.c
	gcc -c main.c

vecteur.o: vecteur.c
	gcc -c vecteur.c

matrix.o: matrix.c vecteur.o
	gcc -c matrix.c
