#include "ArrayList.h"
#include "Couleur.h"
#include "Image.h"



/*constructeur par defaut*/
template <class T>
ArrayList<T>::ArrayList() // Constructeur par défaut
{
    pTete=NULL;
    
    #ifdef DEBUG
    cout << "Je suis le contructeur par defaut ArrayList" << endl<<endl;
    #endif
}

template <class T>
ArrayList<T>::ArrayList(const ArrayList& old) // Constructeur de copie
{
    pTete=NULL;// car nouvell arrayList; doit mettre tete a null

    //cree var temp de tete et met l'old pTete pour parcour arrayList
    Cellule<T>* tempTete = old.pTete; 

    //whille tant qu'on est pas arrivé à la fin 
    while (tempTete != NULL)
    {
        insereElement(tempTete->valeur);
        tempTete= tempTete->suivant;//passe au suivant
    }

    #ifdef DEBUG
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
    if(pTete== NULL) {return true;}
    else{return false;}
}

template <class T>
int ArrayList<T>::getNombreElements() const
{
    int nbrElem=0;
    //cree var temp de tete et met pTete pour parcour arrayList
    Cellule<T>* tempTete = pTete; 

    while (tempTete !=NULL)
    {
        nbrElem++;
        tempTete= tempTete->suivant;
    }
    return nbrElem;
}

template <class T>
void ArrayList<T>::Affiche() const
{
    //cree var temp de tete et met pTete pour parcour arrayList
    Cellule<T>* tempTete = pTete; 

    if(tempTete==NULL){cout<<"L'arrayList ne contient aucun element"<<endl;return;}

    cout<< "voici les elements de l'arrayList: "<<endl;
    while (tempTete !=NULL)
    {
        cout<< tempTete->valeur<<endl;
        tempTete= tempTete->suivant;
    }
}

template <class T>
void ArrayList<T>::insereElement(const T& val)
{
    //cree new cellule (cree un new espace dans la memoire)
    Cellule<T>* nouvelCellule= new Cellule<T>;

    //assigne val au new cellule
    nouvelCellule->valeur= val;

    //on add a la fin , ducoup aucun element au suivant(a la fin) 
    nouvelCellule->suivant= NULL;

    if(estVide()==true)
    {
        pTete=nouvelCellule;
    }
    else
    {
        //parcour arrayList avec pointeur temp pour arriver a la fin et on insert le new elem
        Cellule<T>* temp = pTete;
        // for find the end (en gros a la sortie de la boucle temp->suivant sera null)
        while (temp->suivant != NULL) 
        {
            temp= temp->suivant;
        }
        temp->suivant= nouvelCellule;
    }
}

template <class T>
T ArrayList<T>::retireElement(int ind)
{
    //ind est errone ou arrayList est vide
    if (ind<0 || ind>(getNombreElements()-1) || estVide()==true)
    {
        cout<<"ind errone ou arrayList vide"<<endl;//return NULL;
    }
    else
    {

        Cellule<T>* Pprecedent ;
        Cellule<T>* Psuivant=pTete ;
        
        int cpt=0;

        while(Psuivant != NULL)
        {
            if(cpt== ind)
            {
                break;
            }
            Pprecedent=Psuivant;
            Psuivant= Psuivant->suivant;
            cpt++;
        }

        if(Psuivant==NULL){ cout<<"element pas trouve"<<endl ;}//element pas trouve

        T valDelet= Psuivant->valeur;
        //c'est que la val a supprimer ce trouve au premier element
        if(Pprecedent==NULL)
        {
            pTete=Psuivant->suivant;
        }
        else
        {
            Pprecedent->suivant=Psuivant->suivant;
        }
        
        delete Psuivant;
        return valDelet;//element trouve 
    }
}

template <class T>
T& ArrayList<T>::getElement(int ind)
{
    //entre dans la cond si ind est errone ou arrayList est vide
    if (ind<0 || ind>(getNombreElements()-1) || estVide()==true)
    {
        cout<<"ind erronne ou arrayList vide "<<endl;//return NULL;
    }
    else
    {
        Cellule<T>* temp = pTete;
        int cpt=0;

        while(temp != NULL)
        {
            if(cpt== ind){break;}
            temp= temp->suivant;
            cpt++;
        }
        
        if(temp==NULL){ cout<<"NULL, element pas trouvé"<<endl;/*return NULL;*/}//element pas trouve
        return temp->valeur;//element trouve 
    }
}

template <class T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList& old)
{
    // Vérif l'auto-affectation
    if (this == &old){return *this;}
        
    // Supprimez la liste actuelle
    while (pTete != nullptr)
    {
        Cellule<T>* celluleASupprimer = pTete;
        pTete = pTete->suivant;
        delete celluleASupprimer;
    }

    // Copiez les éléments de 'old' dans la liste courante
    Cellule<T>* newCellule = old.pTete;
    while (newCellule != nullptr)
    {
        insereElement(newCellule->valeur);
        newCellule = newCellule->suivant;
    }

    return *this;
}

template class ArrayList<int>;
template class ArrayList<Couleur>;
template class ArrayList<Image>;