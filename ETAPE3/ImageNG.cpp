#include "ImageNG.h"
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

#include "MyQT.h"


//const int ImageNG::L_MAX= 500;
//const int ImageNG::H_MAX= 500;
// Constructeur par défaut
ImageNG::ImageNG(): ImageNG(99,"XXX")
{
    dimension.setHauteur(300);
    dimension.setLargeur(400);
    //setDimension(dimension);
   /* setId(99);
    //nom=NULL;
    setNom("XXX");}*/
}

// Constructeur avec paramètres
ImageNG::ImageNG(int id, const char* nom)
{
    setId(id);
    setNom(nom);

    #ifdef DEBUG
  /*comme le contructeur par defaut sauf qu'il est parametre*/
  cout << "Je suis le contructeur d'initialisation ImageNG" << endl<<endl;
  #endif
}

ImageNG::ImageNG(int id, const char* nom, const Dimension& dimension)
{
    setId(id);
    setNom(nom);
    setDimension(dimension);

    #ifdef DEBUG
  /*comme le contructeur par defaut sauf qu'il est parametre*/
  cout << "Je suis le contructeur d'initialisation ImageNG" << endl<<endl;
  #endif
}

// Constructeur de copie
ImageNG::ImageNG(const ImageNG& img)
{
    setNom(img.nom);
    setId(img.id);
    setDimension(img.dimension);

    #ifdef DEBUG
   cout << "Je suis le constructeur de copie ImageNG" << endl<<endl;
   #endif
}

// Destructeur
ImageNG::~ImageNG() 
{
    if(nom !=NULL)
	{
		delete nom;
		#ifdef DEBUG
  		cout << "Je suis le destructeur ImageNG" << endl<<endl;
  		#endif
	}
}

// Getter pour l'ID
int ImageNG::getId() const 
{
    return id;
}

// Getter pour le nom
const char* ImageNG::getNom() const 
{
    return nom;
}

// Setter pour l'ID
void ImageNG::setId(int id) 
{
    this->id = id;
}

// Setter pour le nom
void ImageNG::setNom(const char* nom) 
{
    this->nom=NULL;
    if(this->nom!=NULL)
    {
        delete this->nom;
    }
    this->nom = new char[strlen(nom) + 1];
    strcpy(this->nom, nom);
}

void ImageNG::setDimension(const Dimension& dimension)
{
    this->dimension= dimension;
    /*this->dimension.setHauteur(dimension.getHauteur());
    this->dimension.setLargeur(dimension.getLargeur());*/
} 

const Dimension& ImageNG::getDimension() const
{
    return dimension;
}

void ImageNG::setPixel(int x, int y, int val)
{
    if(x>=0 && x< dimension.getLargeur() && y>=0 && y< dimension.getHauteur() && (val<=255 && val>=0 ))
    {
        matrice[x][y]= val;
    }
}

int ImageNG::getPixel(const int x,const int y) const
{
    return matrice[x][y];
}

void ImageNG::setBackground(int val)
{
    if (val>255  || val<0 ){return ;}
    
    for(int x=0;x<dimension.getLargeur(); x++)
    {
        for(int y=0; y<dimension.getHauteur(); y++)
        {
            matrice[x][y]=val;
        }
    }
}

void ImageNG::Dessine() const
{
    MyQT::ViewImage(*this);
}

void ImageNG::importFromFile(const char* fichier)
{
    MyQT::ImportFromFile(*this,fichier);
}

void ImageNG::exportToFile(const char* fichier,const char* format) const 
{
    MyQT::ExportToFile(*this,fichier,format);
}

// Méthode pour afficher les caractéristiques de l'objet
void ImageNG::Affiche() const 
{
    cout << "ID : " << id <<endl;
    cout << "Nom : " << nom <<endl;
    cout << "Hauteur : " << dimension.getHauteur()<<endl;
    cout << "Largeur: " << dimension.getLargeur()<<endl;
}
