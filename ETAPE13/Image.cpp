#include "Image.h"
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

#include <iostream>
#include <fstream>

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
   // MyQT::ImportFromFile(*this, nomFichier);
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

void Image::Save(ofstream & fichier) const
{
  if(!fichier)
  {
    cout<<"!!! ERREUR D'OUVERTURE FICHIER !!!"<<endl;
  }
  else
  {

    fichier.write((char *)&id,sizeof(int));

    int taille= nom.size();
    fichier.write((char *)&taille,sizeof(int));
    fichier.write((char *)nom.data(),taille*sizeof(char));
    dimension.Save(fichier);
    cout<< ">>>Image : Save <<<"<<endl;
  }
}

void Image::Load(ifstream & fichier)
{
  if(!fichier)
  {
    cout<<"!!! ERREUR D'OUVERTURE FICHIER !!!"<<endl;
  }

  else
  {
    fichier.read((char *)&id,sizeof(int));

    int t;

    fichier.read((char *)&t, sizeof(int));
    nom.resize(t);
    fichier.read((char *)nom.data(), t*sizeof(char));

    dimension.Load(fichier);

    cout<< ">>>Image : Load <<<"<<endl;
  }

}
