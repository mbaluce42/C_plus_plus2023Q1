#ifndef SORTEDARRAYLIST_H
#define SORTEDARRAYLIST_H
#include "ArrayList.h"

template<class T>
class SortedArrayList: public ArrayList<T>
{
public:
    SortedArrayList(); // Constructeur par défaut
    SortedArrayList(const SortedArrayList& old); // Constructeur de copie
    ~SortedArrayList(); // Destructeur

    void insereElement(const T& val);
};
#endif
