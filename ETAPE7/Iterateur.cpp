
#include "Iterateur.h"
#include "Couleur.h"


template<class T>
Iterateur<T>::Iterateur(ArrayList<T>& l) : pListe(l), pElement(pListe.pTete)
{
    #ifdef DEBUG
    cout << "Je suis le contructeur d'initialisation Iterateur" << endl<<endl;
    #endif
}

template<class T>
void Iterateur<T>::reset() 
{
    pElement=pListe.pTete;
}

template<class T>
bool Iterateur<T>::end() const 
{
    if(pElement==NULL){return true;}
    else{return false;}
}

template<class T>
void Iterateur<T>::operator++() 
{
    pElement=pElement->suivant;
}

template<class T>
void Iterateur<T>::operator++(int)
{
  return operator++();
}

template<class T>
Iterateur<T>::operator T()const
{
  return pElement->suivant;
}

template<class T>
T& Iterateur<T>::operator&()
{
    return pElement->valeur;
}

template class Iterateur<int>;
template class Iterateur<Couleur>;