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
     ArrayList<T>& pListe;
    Cellule<T>* pElement;
    
public:
    Iterateur(const ArrayList<T>& l); // Constructeur
    void reset(); // Réinitialiser l'itérateur au début de la liste
    bool end() const; // Vérifier si l'itérateur est à la fin de la liste
    void operator++(); // Déplacer l'itérateur vers la droite
    void operator++(int);
    operator T() const; // casting ,Retourner (par valeur) l'élément pointé par l'itérateur
    T& operator&(); // Retourner (par référence) l'élément pointé par l'itérateur
};
#endif
