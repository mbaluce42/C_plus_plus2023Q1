
PROGAMS = ApplicPhotoShop TestSortedArrayList

all: $(PROGAMS)
ApplicPhotoShop:	moc_mainwindowphotoshop.o mainwindowphotoshop.o main.o ImageNG.o Image.o ImageRGB.o ImageB.o Dimension.o Couleur.o ArrayList.o SortedArrayList.o Iterateur.o Traitements.o PhotoShop.o MyQT.o Exception.o RGBException.o XYException.o
					echo Creation de ApplicPhotoShop...
					g++ -o ApplicPhotoShop moc_mainwindowphotoshop.o mainwindowphotoshop.o main.o /usr/lib64/libQt5Widgets.so /usr/lib64/libQt5Gui.so /usr/lib64/libQt5Core.so /usr/lib64/libGL.so -lpthread MyQT.o ImageNG.o Image.o ImageRGB.o ImageB.o Dimension.o Couleur.o ArrayList.o SortedArrayList.o Iterateur.o Traitements.o PhotoShop.o Exception.o RGBException.o XYException.o -lSDL -lpthread -Wl,-O1 -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -I.DQT_CORE_LIB -isystem      /usr/include/qt5      -isystem /usr/include/qt5/QtWidgets -isystem  /usr/include/qt5/QtGui  -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++ /usr/lib64/libQt5Gui.so /usr/lib64/libQt5Widgets.so /usr/lib64/libQt5Core.so /usr/lib64/libGL.so -DDEBUG

moc_mainwindowphotoshop.o:	moc_mainwindowphotoshop.cpp mainwindowphotoshop.h
							echo Creation de moc_mainwindowphotoshop.o...
							g++ -c -pipe -g -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_QML_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++ -o moc_mainwindowphotoshop.o moc_mainwindowphotoshop.cpp

mainwindowphotoshop.o:	mainwindowphotoshop.cpp mainwindowphotoshop.h ui_mainwindowphotoshop.h 	
	echo Creation de mainwindowphotoshop.o...
	g++ -c -pipe -g -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_QML_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++ -o mainwindowphotoshop.o mainwindowphotoshop.cpp

main.o:	main.cpp
	echo Creation de main.o...
	g++ -c -pipe -g -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_QML_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++ -o main.o main.cpp

	
TestSortedArrayList:	TestSortedArrayList.cpp SortedArrayList.o ArrayList.o Couleur.o RGBException.o Exception.o
						g++ TestSortedArrayList.cpp -o TestSortedArrayList SortedArrayList.o ArrayList.o Couleur.o RGBException.o Exception.o

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

ArrayList.o:	ArrayList.cpp ArrayList.h
				g++ ArrayList.cpp -c -DDEBUG

SortedArrayList.o:	SortedArrayList.cpp SortedArrayList.h
					g++ SortedArrayList.cpp -c -DDEBUG

Iterateur.o:	Iterateur.cpp Iterateur.h
				g++ Iterateur.cpp -c -DDEBUG

Traitements.o:	Traitements.cpp Traitements.h
				g++ Traitements.cpp -c -DDEBUG

PhotoShop.o:	PhotoShop.cpp PhotoShop.h
				g++ PhotoShop.cpp -c -DDEBUG
		
MyQT.o:	MyQT.cpp MyQT.h
		g++ -c MyQT.cpp -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS  -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -I.DQT_CORE_LIB -isystem      /usr/include/qt5      -isystem /usr/include/qt5/QtWidgets  -isystem  /usr/include/qt5/QtGui   -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++

Exception.o:	Exception.cpp Exception.cpp
				g++ Exception.cpp -c -DDEBUG


RGBException.o:	RGBException.cpp RGBException.cpp
				g++ RGBException.cpp -c -DDEBUG
			
XYException.o:	XYException.cpp XYException.cpp
				g++ XYException.cpp -c -DDEBUG

clean :
			rm -f *.o