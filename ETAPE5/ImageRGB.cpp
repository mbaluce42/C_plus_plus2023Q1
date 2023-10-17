#include "ImageRGB.h"
#include "MyQT.h"

ImageRGB::ImageRGB()
{
    #ifdef DEBUG
	cout << "Je suis le constructeur par defaut ImageNG" << endl<<endl;
	#endif

}

ImageRGB::ImageRGB(int id, const string& nom): Image()
{
    #ifdef DEBUG
  /*comme le contructeur par defaut sauf qu'il est parametre*/
  cout << "Je suis le contructeur d'initialisation1 ImageRBG" << endl<<endl;
  #endif

}
    
ImageRGB::ImageRGB(int id, const string& nom, const Dimension& dimension): Image(id,nom,dimension)
{
    #ifdef DEBUG
  /*comme le contructeur par defaut sauf qu'il est parametre*/
  cout << "Je suis le contructeur d'initialisation2 ImageRGB" << endl<<endl;
  #endif

}

ImageRGB::ImageRGB(const ImageRGB& old): Image(old)
{
    for(int x=0;x<=dimension.getLargeur(); x++)
    {
        for(int y=0; y<=dimension.getHauteur(); y++)
        {
            (*this).matrice[x][y]=old.matrice[x][y];
        }
    } 

}

ImageRGB::ImageRGB(const char* nomFichier): Image(nomFichier)
{
    MyQT::ImportFromFile(*this, nomFichier);
}

ImageRGB::~ImageRGB() 
{
    #ifdef DEBUG
	cout << "Je suis le destructeur ImageRGB" << endl<<endl;
	#endif

}

void ImageRGB::setBackground(const Couleur& couleur) 
{
    for(int x=0;x<=dimension.getLargeur(); x++)
    {
        for(int y=0; y<=dimension.getHauteur(); y++)
        {
            setPixel(x,y,couleur);
        }
    }

}

void ImageRGB::setPixel(int x, int y, const Couleur& couleur) 
{
    if(x>=0 && x< dimension.getLargeur() && y>=0 && y< dimension.getHauteur() )
    {
        matrice[x][y]= couleur;
    }

}

Couleur ImageRGB::getPixel(int x, int y) const 
{
 
    return matrice[x][y];
}

void ImageRGB::Dessine() const
{
    MyQT::ViewImage(*this);
}

void ImageRGB::importFromFile(const char* fichier)
{
    MyQT::ImportFromFile(*this,fichier);
}

void ImageRGB::exportToFile(const char* fichier,const char* format) const 
{
    MyQT::ExportToFile(*this,fichier,format);
}

// Méthode pour afficher les caractéristiques de l'objet
void ImageRGB::Affiche() const 
{
    cout << "-Detail ImageRGB: "<<endl
    << "ID : " << id <<endl
    << "Nom : " << nom <<endl
    << "Dimension: "<< endl
    << "Hauteur : " << dimension.getHauteur()<<endl
    << "Largeur: " << dimension.getLargeur()<<endl;
}

ImageRGB& ImageRGB::operator=(const ImageRGB& old) 
{
    if(this == &old){return *this;}

    setId(old.id);
    setNom(old.nom);
    setDimension(old.dimension);

    for(int x=0;x<=dimension.getLargeur(); x++)
    {
        for(int y=0; y<=dimension.getHauteur(); y++)
        {
            matrice[x][y]=old.matrice[x][y];
        }
    } 

    return *this;
}

ostream& operator<<(ostream& os, const ImageRGB& image) 
{
    os <<"-Detail ImageRGB: "<<endl
    << "Id : "<< image.getId()<<endl
    <<"Nom :" <<image.getNom()<<endl
    << "Dimension: "<< endl
    <<"Hauteur: "<<image.getDimension().getHauteur()<<endl <<"Largeur: "<<image.getDimension().getLargeur() <<endl;
 
    return os;
}


