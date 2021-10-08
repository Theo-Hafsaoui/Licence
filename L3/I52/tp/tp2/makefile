
test.exe:test.o complex.o
	g++  test.o complex.o -o test.exe && ./test.exe
test.o: test.cpp complex.h
	g++ -c test.cpp
complex.o:complex.cpp complex.h
	g++ -c complex.cpp
clean:
	rm *.o *.exe
