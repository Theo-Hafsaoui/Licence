
test.exe:echangiste.o test.o complexe.o
	g++ echangiste.o test.o complexe.o -o test.exe && ./test.exe
echangiste.o: echangiste.cpp echangiste.h
	g++ -c echangiste.cpp
test.o: test.cpp echangiste.h
	g++ -c test.cpp
complexe.o:complexe.cpp complexe.h
	g++ -c complexe.cpp
