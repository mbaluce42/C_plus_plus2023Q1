#include "SortedArrayList.h"

#include <stdlib.h>
#include <iostream>
#include <unistd.h>


using namespace std;



int main(int argc,char* argv[])
{
    SortedArrayList<int> liste;
    liste.Affiche();                                       // --> ()
    cout << endl;

    cout << "Liste Vide ? " << liste.estVide() << endl;
    cout << "On insere 3,-2,5,-1,0 et 17..." << endl;
    liste.insereElement(3);
    liste.insereElement(-2);
    liste.insereElement(5);
    liste.insereElement(-1);
    liste.insereElement(0);
    liste.insereElement(17);
    cout << "Liste Vide ? " << liste.estVide() << endl;
    liste.Affiche();                                       // --> (-2 -1 0 3 5 17)
    cout << "La liste contient " << liste.getNombreElements() << " elements." << endl;

    cout << "----- 1.2 On recupere une elements de la Liste dans le supprimer ----------------------------" << endl;
    cout << "On recupere l'element d'indice 3 (3)  : " << liste.getElement(3) << endl;
    liste.Affiche();

    cout << "----- 1.3 On recupere une elements de la Liste et on le modifie a 100 -----------------------" << endl;
    cout << "On modifie l'element d'indice 4 (5)  : " << liste.getElement(4) << endl; 
    liste.getElement(4) = 100;
    liste.Affiche();

    cout << "----- 1.4 On retire des elements de la Liste ------------------------------------------------" << endl;
    cout << "On retire l'element d'indice 4 (100) : " << liste.retireElement(4) << endl;
    liste.Affiche();
    cout << "On retire l'element d'indice 0 (-2)   : " << liste.retireElement(0) << endl;
    liste.Affiche();
    cout << "On retire l'element d'indice 1 (-1)  : " << liste.retireElement(1) << endl;
    liste.Affiche();

    cout << endl;



  return 0;
}