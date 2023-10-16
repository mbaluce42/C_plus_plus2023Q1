
PROGAMS = Test2

all: $(PROGAMS)

Test2:		Test2.cpp ImageNG.o Dimension.o
			g++ Test2.cpp ImageNG.o Dimension.o -o Test2 -DDEBUG


ImageNG.o:	ImageNG.cpp ImageNG.h
			g++ ImageNG.cpp -c -DDEBUG

Dimension.o: Dimension.cpp Dimension.h
			g++ Dimension.cpp -c -DDEBUG


clean :
			rm -f *.o