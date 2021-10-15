
test.exe:test.o complex.o poly.o
	g++  test.o complex.o poly.o -o test.exe && ./test.exe
test.o: test.cpp complex.h poly.h
	g++ -c test.cpp
complex.o:complex.cpp complex.h
	g++ -c complex.cpp
poly.o:poly.cpp poly.h
	g++ -c poly.cpp
clean:
	rm *.o *.exe
