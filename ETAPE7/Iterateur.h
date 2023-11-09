#ifndef ITERATEUR_H
#define ITERATEUR_H
#include <iostream>
#include "Cellule.h"
#include "ArrayList.h"
using namespace std;

template<class T>
class Iterateur
{
private:
    Cellule<T>* pElement;
    
public:
    Iterateur(Cellule<T>* element); // Constructeur
    void reset(); // Réinitialiser l'itérateur au début de la liste
    bool end() const; // Vérifier si l'itérateur est à la fin de la liste
    void operator++(); // Déplacer l'itérateur vers la droite
    T operator*() const; // Retourner (par valeur) l'élément pointé par l'itérateur
    T& operator&() const; // Retourner (par référence) l'élément pointé par l'itérateur
};
#endif
