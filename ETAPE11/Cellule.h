#ifndef CELLULE_H
#define CELLULE_H

template<class T>
struct Cellule
{
    T valeur;
    Cellule<T>* suivant;
};

#endif
