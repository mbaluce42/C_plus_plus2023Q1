#include "ImageB.h"
#include "MyQT.h"
#include "XYException.h"

Couleur ImageB::couleurTrue(255,255,255);
Couleur ImageB::couleurFalse(0,0,0);

ImageB::ImageB():Image()
{
    #ifdef DEBUG
	cout << "Je suis le constructeur par defaut ImageB" << endl<<endl;
	#endif
}

ImageB::ImageB(int id, const string& nom): Image()
{
    #ifdef DEBUG
  /*comme le contructeur par defaut sauf qu'il est parametre*/
  cout << "Je suis le contructeur d'initialisation1 ImageB" << endl<<endl;
  #endif
}
    
ImageB::ImageB(int id, const string& nom, const Dimension& dimension): Image(id,nom,dimension)
{
    #ifdef DEBUG
  /*comme le contructeur par defaut sauf qu'il est parametre*/
  cout << "Je suis le contructeur d'initialisation2 ImageB" << endl<<endl;
  #endif
}

ImageB::ImageB(const ImageB& old): Image(old)
{
    for(int x=0;x<dimension.getLargeur(); x++)
    {
        for(int y=0; y<dimension.getHauteur(); y++)
        {
            this->matrice[x][y]=old.matrice[x][y];
        }
    } 
    #ifdef DEBUG
	cout << "Je suis le constructeur copie ImageB" << endl<<endl;
	#endif
}

ImageB::~ImageB() 
{
    #ifdef DEBUG
	cout << "Je suis le destructeur ImageB" << endl<<endl;
	#endif
}

void ImageB::setBackground(const bool valeur) 
{
    for(int x=0;x<dimension.getLargeur(); x++)
    {
        for(int y=0; y<dimension.getHauteur(); y++)
        {
            setPixel(x,y,valeur);
        }
    }
}

void ImageB::setPixel(int x, int y, const bool valeur) 
{
    if(x>=0 && x< dimension.getLargeur() && y>=0 && y< dimension.getHauteur() )
    {
        matrice[x][y]= valeur;
    }
    else{throw XYException("Coordonnees pixel invalides !",'d');}
    
}

bool ImageB::getPixel(int x, int y) const 
{
    return matrice[x][y];
}

void ImageB::Dessine() const
{
    MyQT::ViewImage(*this);
}


void ImageB::exportToFile(const char* fichier,const char* format) const 
{
    MyQT::ExportToFile(*this,fichier,format);
}

// Méthode pour afficher les caractéristiques de l'objet
void ImageB::Affiche() const 
{
    cout << "-Detail ImageB: "<<endl
    << "ID : " << id <<endl
    << "Nom : " << nom <<endl
    << "Dimension: "<< endl
    << "Hauteur : " << dimension.getHauteur()<<endl
    << "Largeur: " << dimension.getLargeur()<<endl;
}

ImageB& ImageB::operator=(const ImageB& old) 
{
    if(this == &old){return *this;}

    setId(old.id);
    setNom(old.nom);
    setDimension(old.dimension);

    for(int x=0;x<dimension.getLargeur(); x++)
    {
        for(int y=0; y<dimension.getHauteur(); y++)
        {
            matrice[x][y]=old.matrice[x][y];
        }
    } 
    return *this;
}

ostream& operator<<(ostream& os, const ImageB& image) 
{
    os <<"-Detail ImageB: "<<endl
    << "Id : "<< image.getId()<<endl
    <<"Nom :" <<image.getNom()<<endl
    << "Dimension: "<< endl
    <<"Hauteur: "<<image.getDimension().getHauteur()<<endl <<"Largeur: "<<image.getDimension().getLargeur() <<endl;
 
    return os;
}


