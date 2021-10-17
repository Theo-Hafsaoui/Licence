
LIBS=`fltk-config --ldflags` -lfltk -lfltk_images -ljpeg -lstdc++ -lXfixes -lXext -lpthread -ldl -lm -lX11
ex1.exe: test.o complex.o
	g++  test.o complex.o -o test.exe $(LIBS)
	./test.exe

test.exe:test.o complex.o poly.o
	g++  -Wall test.o complex.o poly.o -o test.exe 
test.o: test.cpp complex.h
	g++ -c test.cpp
complex.o:complex.cpp complex.h
	g++ -c complex.cpp
poly.o:poly.cpp poly.h
	g++ -c poly.cpp
clean:
	rm *.o *.exe
