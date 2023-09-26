
PROGAMS = Test2

all: $(PROGAMS)

Test2:		Test2.cpp ImageNG.o Dimension.o
			g++ Test2.cpp ImageNG.o Dimension.o -o Test2


ImageNG.o:	ImageNG.cpp ImageNG.h
			g++ ImageNG.cpp -c

Dimension.o: Dimension.cpp Dimension.h
			g++ Dimension.cpp -c


clean :
			rm -f *.o