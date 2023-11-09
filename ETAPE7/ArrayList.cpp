#include "ArrayList.h"
#define DEBUG


/*constructeur par defaut*/
template <class T>
ArrayList<T>::ArrayList() // Constructeur par défaut
{
    pTete=NULL;
    
    #ifdef DEBUG
    /*comme le contructeur par defaut sauf qu'il est parametre*/
    cout << "Je suis le contructeur par defaut ArrayList" << endl<<endl;
    #endif
}

template <class T>
ArrayList<T>::ArrayList(const ArrayList& old) // Constructeur de copie
{
    this->pTete=NULL;// car nouvell arrayList; doit mettre tete a null

    cellule<T>* tempTete = old.pTete; //cree var temp de tete et met l'old pTete pour parcour arrayList

    while (tempTete != NULL)
    {
        insereElement(tempTete->val);
        tempTete= tempTete->suivant;
    }

    #ifdef DEBUG
    /*comme le contructeur par defaut sauf qu'il est parametre*/
    cout << "Je suis le contructeur par de copie ArrayList" << endl<<endl;
    #endif
}

template <class T>
ArrayList<T>::~ArrayList() // Destructeur
{

    while(pTete!=NULL)
    {
        Cellule<T>* CelluleForDel = pTete;
        pTete= pTete->suivant;
        delete CelluleForDel ;
    }

    #ifdef DEBUG
    /*comme le contructeur par defaut sauf qu'il est parametre*/
    cout << "Je suis le destructeur ArrayList" << endl<<endl;
    #endif
}

template <class T>
bool ArrayList<T>::estVide() const
{

}

template <class T>
int ArrayList<T>::getNombreElements() const
{

}

template <class T>
void ArrayList<T>::Affiche() const
{

}

template <class T>
void ArrayList<T>::insereElement(const T& val)
{

}

template <class T>
T ArrayList<T>::retireElement(int ind)
{

}

template <class T>
T& ArrayList<T>::getElement(int ind)
{

}

template<class T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList& old)
{

}

template class ArrayList<int>;