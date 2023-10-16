#include "Image.h"
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

#include "MyQT.h"




// Constructeur par défaut
Image::Image(): Image(99,"XXX")
{
    dimension.setHauteur(300);
    dimension.setLargeur(400);
}

// Constructeur avec paramètres
Image::Image(int id, const string& nom)
{
    setId(id);
    setNom(nom);

    #ifdef DEBUG
  /*comme le contructeur par defaut sauf qu'il est parametre*/
  cout << "Je suis le contructeur d'initialisation Image" << endl<<endl;
  #endif
}

Image::Image(int id, const string& nom, const Dimension& dimension)
{
    setId(id);
    setNom(nom);
    setDimension(dimension);

    #ifdef DEBUG
  /*comme le contructeur par defaut sauf qu'il est parametre*/
  cout << "Je suis le contructeur d'initialisation Image" << endl<<endl;
  #endif
}

// Constructeur de copie
Image::Image(const Image& old)
{
    setNom(old.nom);
    setId(old.id);
    setDimension(old.dimension);

    #ifdef DEBUG
   cout << "Je suis le constructeur de copie Image" << endl<<endl;
   #endif
}

Image::Image(const char* nomFichier)
{
    setId(0); 
    setNom(nomFichier);
    dimension.setHauteur(300);
    dimension.setLargeur(400);
    //setDimension(Dimension(dimension.getLargeur(), dimension.getHauteur())); 
    MyQT::ImportFromFile(*this, nomFichier);
}


// Destructeur
Image::~Image() 
{
    #ifdef DEBUG
  	cout << "Je suis le destructeur Image" << endl<<endl;
  	#endif
}

int Image::getId() const 
{
    return id;
}

const string& Image::getNom() const 
{
    return nom;
}

void Image::setId(int id) 
{
    this->id = id;
}

void Image::setNom(const string& nom) 
{
    this->nom =nom ;
}

void Image::setDimension(const Dimension& dimension)
{
    this->dimension= dimension;
} 

const Dimension& Image::getDimension() const
{
    return dimension;
}

