
test.exe:test.o complex.o poly.o Vcomplex.o
	g++  -Wall test.o Vcomplex.o complex.o poly.o -o test.exe 
	test.exe
test.o: test.cpp complex.h
	g++ -c test.cpp
complex.o:complex.cpp complex.h
	g++ -c complex.cpp
poly.o:poly.cpp poly.h
	g++ -c poly.cpp
Vcomplex.o:Vcomplex.cpp Vcomplex.h
	g++ -c Vcomplex.cpp
clean:
	rm *.o *.exe
