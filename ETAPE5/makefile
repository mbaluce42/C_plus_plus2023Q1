
PROGAMS = Test5

all: $(PROGAMS)

Test5:	Test5.cpp ImageNG.o Image.o ImageRGB.o ImageB.o Dimension.o Couleur.o MyQT.o
		g++ Test5.cpp -o Test5 MyQT.o ImageNG.o Image.o ImageRGB.o ImageB.o Dimension.o Couleur.o -lSDL -lpthread -Wl,-O1 -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -I.DQT_CORE_LIB -isystem      /usr/include/qt5      -isystem /usr/include/qt5/QtWidgets -isystem  /usr/include/qt5/QtGui  -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++ /usr/lib64/libQt5Gui.so /usr/lib64/libQt5Widgets.so /usr/lib64/libQt5Core.so /usr/lib64/libGL.so -DDEBUG

ImageNG.o:	ImageNG.cpp ImageNG.h
			g++ ImageNG.cpp -c -DDEBUG

Image.o: Image.cpp Image.h
		g++ Image.cpp -c -DDEBUG

ImageRGB.o:	ImageRGB.cpp ImageRGB.h
			g++ ImageRGB.cpp -c -DDEBUG

ImageB.o:	ImageB.cpp ImageB.h
			g++ ImageB.cpp -c -DDEBUG

Dimension.o: Dimension.cpp Dimension.h
			g++ Dimension.cpp -c -DDEBUG

Couleur.o:	Couleur.cpp Couleur.h
			g++ Couleur.cpp -c -DDEBUG
		
MyQT.o:	MyQT.cpp MyQT.h
		g++ -c MyQT.cpp -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS  -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -I.DQT_CORE_LIB -isystem      /usr/include/qt5      -isystem /usr/include/qt5/QtWidgets  -isystem  /usr/include/qt5/QtGui   -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++

clean :
			rm -f *.o