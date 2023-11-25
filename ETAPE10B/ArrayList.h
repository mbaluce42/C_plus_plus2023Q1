#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include "Cellule.h"
#include <iostream>
using namespace std;

template<class T> class Iterateur;

template<class T>
class ArrayList
{
protected:
    Cellule<T>* pTete;
    
public:
    ArrayList(); // Constructeur par défaut
    ArrayList(const ArrayList& old); // Constructeur de copie
    ~ArrayList(); // Destructeur

    bool estVide() const;
    int getNombreElements() const;
    void Affiche() const;
    void insereElement(const T& val);
    T retireElement(int ind);
    T& getElement(int ind);
    ArrayList& operator=(const ArrayList& old);
    friend class Iterateur<T>;//pour que l'itérateur puisse accéder aux membres privés de ArrayList
};
#endif
