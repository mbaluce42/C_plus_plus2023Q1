#include "SortedArrayList.h"



/*constructeur par defaut*/
template <class T>
SortedArrayList<T>::SortedArrayList(): ArrayList<T>()// Constructeur par défaut
{    
    #ifdef DEBUG
    cout << "Je suis le contructeur par defaut SortedArrayList" << endl<<endl;
    #endif
}

template <class T>
SortedArrayList<T>::SortedArrayList(const SortedArrayList& old): ArrayList<T>(old) // Constructeur de copie
{
    #ifdef DEBUG
    cout << "Je suis le contructeur par de copie SortedArrayList" << endl<<endl;
    #endif
}

template <class T>
SortedArrayList<T>::~SortedArrayList() // Destructeur
{
    #ifdef DEBUG
    /*comme le contructeur par defaut sauf qu'il est parametre*/
    cout << "Je suis le destructeur SortedArrayList" << endl<<endl;
    #endif
}


template <class T>
void SortedArrayList<T>::insereElement(const T& val)
{
    //cree new cellule (cree un new espace dans la memoire)
    Cellule<T>* nouvelCellule= new Cellule<T>;

    //assigne val au new cellule
    nouvelCellule->valeur= val;

    if(estVide()==true)
    {
        //on add au debut ou fin (pareil car liste vide ), ducoup aucun element au suivant(a la fin) 
        nouvelCellule->suivant= NULL;
        pTete=nouvelCellule;
    }
    else
    {
        //parcour SortedarrayList avec pointeur temp pour arriver a la fin et on insert le new elem
        Cellule<T>* temp = pTete;
        Cellule<T>* tempPrec = NULL;

        while(temp->suivant != NULL && nouvelCellule->valeur > temp->valeur )
        {
            tempPrec= temp:
            temp= temp->suivant; 
        }
        if(nouvelCellule->valeur <= temp->valeur)
        {
            nouvelCellule->suivant=temp;
            if(tempPrec==NULL)
            {
                //ajout debut
                pTete= nouvelCellule;
            }
            else// !=null
            {
                //ajout entre
                tempPrec->suivant= nouvelCellule;
            }
        }
        else
        {
            //ajout fin 
            nouvelCellule->suivant=NULL;//rien ne doit suivre derriere
            temp->suivant= nouvelCellule;
            tempPrec->suivant= temp;
        }
        
    }
}

template class SortedArrayList<int>;
