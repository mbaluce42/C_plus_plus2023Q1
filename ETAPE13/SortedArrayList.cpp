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


/*template <class T>
void SortedArrayList<T>::insereElement(const T& val)
{
    //cree new cellule (cree un new espace dans la memoire)
    Cellule<T>* nouvelCellule= new Cellule<T>;

    //assigne val au new cellule
    nouvelCellule->valeur= val;

    if(this->estVide()==true)
    {
        //on add au debut ou fin (pareil car liste vide ), ducoup aucun element au suivant(a la fin) 
        nouvelCellule->suivant= NULL;
        this->pTete=nouvelCellule;
    }
    else
    {
        //parcour SortedarrayList avec pointeur temp pour arriver a la fin et on insert le new elem
        Cellule<T>* temp = this->pTete;
        Cellule<T>* tempPrec = NULL;

        while(temp->suivant != NULL && nouvelCellule->valeur > temp->valeur )
        {
            tempPrec= temp;
            temp= temp->suivant; 
        }
        if(nouvelCellule->valeur <= temp->valeur)
        {
            nouvelCellule->suivant=temp;
            if(tempPrec==NULL)
            {
                //ajout debut
                this->pTete= nouvelCellule;
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
}*/

template <class T>
void SortedArrayList<T>::insereElement(const T& val)
{
    // Crée une nouvelle cellule (cree un nouvel espace dans la memoire)
    Cellule<T>* nouvelleCellule = new Cellule<T>;
    
    // Assigne val à la nouvelle cellule
    nouvelleCellule->valeur = val;
    
    if (this->estVide() || val <= this->pTete->valeur)
    {
        // Ajout au début ou à une liste vide
        nouvelleCellule->suivant = this->pTete;
        this->pTete = nouvelleCellule;
    }
    else
    {
        // Parcours de la SortedArrayList avec un pointeur temp pour arriver à la fin
        Cellule<T>* temp = this->pTete;
        Cellule<T>* tempPrec = NULL;
        
        // Cherche l'endroit où insérer la nouvelle cellule
        while (temp != NULL && val > temp->valeur)
        {
            tempPrec = temp;
            temp = temp->suivant;
        }
        
        // Ajout au milieu ou à la fin
        nouvelleCellule->suivant = temp;
        tempPrec->suivant = nouvelleCellule;
    }
}


template class SortedArrayList<int>;
