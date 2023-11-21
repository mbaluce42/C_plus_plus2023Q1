#ifndef SORTEDARRAYLIST_H
#define SORTEDARRAYLIST_H
#include "ArrayList.h"

template<class T> class Iterateur;

template<class T>
class SortedArrayList: public ArrayList<T>
{
public:
    SortedArrayList(); // Constructeur par défaut
    SortedArrayList(const SortedArrayList& old); // Constructeur de copie
    ~SortedArrayList(); // Destructeur

    void insereElement(const T& val);
    friend class Iterateur<T>;//pour que l'itérateur puisse accéder aux membres privés de ArrayList
};
#endif
