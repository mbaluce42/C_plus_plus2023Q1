#include "Dimension.h"
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const Dimension Dimension::VGA(640,480);
const Dimension Dimension::HD(1280,720);
const Dimension Dimension::FULL_HD(1920,1080);

// Constructeur par défaut
Dimension::Dimension(): Dimension(400,300)
{

}

// Constructeur avec paramètres
Dimension::Dimension(const int larg, const int haut)
{
    setLargeur(larg);
    setHauteur(haut);

    #ifdef DEBUG
  /*comme le contructeur par defaut sauf qu'il est parametre*/
  cout << "Je suis le contructeur d'initialisation Dimension" << endl<<endl;
  #endif
}

// Constructeur de copie
Dimension::Dimension(const Dimension& d)
{
    setHauteur(d.hauteur);
    setLargeur(d.largeur);

    #ifdef DEBUG
   cout << "Je suis le constructeur de copie Dimension" << endl<<endl;
   #endif
}

// Destructeur
Dimension::~Dimension() 
{
	#ifdef DEBUG
  	cout << "Je suis le destructeur Dimension" << endl<<endl;
  	#endif
}
// setter et getter
int Dimension::getLargeur() const 
{
    return largeur;
}

int Dimension::getHauteur() const 
{
    return hauteur;
}

void Dimension::setLargeur(int larg)
{
    if(larg >0){this->largeur = larg; } 
}

void Dimension::setHauteur(int haut)
{
    if(haut >0){this->hauteur= haut;}
}

void Dimension::Affiche() const 
{
    cout << "Largeur : " << largeur<<endl;
    cout << "Hauteur : " << hauteur<<endl;
}