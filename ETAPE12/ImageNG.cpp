#include "ImageNG.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;
#include "MyQT.h"
#include "RGBException.h"
#include "XYException.h"


//const int ImageNG::L_MAX= 500;
//const int ImageNG::H_MAX= 500;
// Constructeur par défaut
ImageNG::ImageNG():Image()
{

}

// Constructeur avec paramètres
ImageNG::ImageNG(int id, const string& nom) : Image(id,nom)
{
    #ifdef DEBUG
  /*comme le contructeur par defaut sauf qu'il est parametre*/
  cout << "Je suis le contructeur d'initialisation ImageNG" << endl<<endl;
  #endif
}

ImageNG::ImageNG(int id, const string& nom,const Dimension& dimension) : Image(id,nom,dimension)
{
    #ifdef DEBUG
  /*comme le contructeur par defaut sauf qu'il est parametre*/
  cout << "Je suis le contructeur d'initialisation ImageNG" << endl<<endl;
  #endif
}

// Constructeur de copie
ImageNG::ImageNG(const ImageNG& old) : Image(old)
{
    for(int x=0;x<dimension.getLargeur(); x++)
    {
        for(int y=0; y<dimension.getHauteur(); y++)
        {
            (*this).matrice[x][y]=old.matrice[x][y];
        }
    } 

    #ifdef DEBUG
   cout << "Je suis le constructeur de copie ImageNG" << endl<<endl;
   #endif
}

ImageNG::ImageNG(const char* nomFichier) : Image(nomFichier)
{
    MyQT::ImportFromFile(*this, nomFichier);
}


// Destructeur
ImageNG::~ImageNG() 
{
	#ifdef DEBUG
	cout << "Je suis le destructeur ImageNG" << endl<<endl;
	#endif
}

// Getter pour l'ID

void ImageNG::setPixel(int x, int y, int val)
{
    if (val>255 || val<0 ) {throw RGBException("Niveau de gris invalide !",val);}

    if(x>=0 && x<dimension.getLargeur() && y>=0 && y<dimension.getHauteur())
    {
        matrice[x][y]= val;
    }
    else{throw XYException("Coordonnees pixel invalides !",'d');}
}

int ImageNG::getPixel(const int x,const int y) const
{
    return matrice[x][y];
}

void ImageNG::setBackground(int val)
{   
    for(int x=0;x<dimension.getLargeur(); x++)
    {
        for(int y=0; y<dimension.getHauteur(); y++)
        {
            setPixel(x,y,val);
        }
    }
}

int ImageNG::getLuminance() const
{
    int somme=0;
    int nbrElem= dimension.getHauteur()*dimension.getLargeur();

    for(int x=0;x<dimension.getLargeur(); x++)
    {
        for(int y=0; y<dimension.getHauteur(); y++)
        {
            somme+= matrice[x][y];
        }
    }
    if(somme ==0) return 0;
    return (somme/nbrElem);
}

int ImageNG::getMinimum() const
{
    int min=matrice[0][0];
    for(int x=0;x<dimension.getLargeur(); x++)
    {
        for(int y=1; y<dimension.getHauteur(); y++)
        {
            if(matrice[x][y]<min){min=matrice[x][y]; }
        }
    }
    return min;
}

int ImageNG::getMaximun() const
{
    int max=matrice[0][0];
    for(int x=0;x<dimension.getLargeur(); x++)
    {
        for(int y=1; y<dimension.getHauteur(); y++)
        {
            if(matrice[x][y]>max){max=matrice[x][y]; }
        }
    }
    return max;
}
 
float ImageNG::getContraste() const
{
    int max= getMaximun();
    int min= getMinimum();

    if(max-min==0) return 0;

    return ((max-min)/(max+min)); 
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
    cout << "-Detail ImageNG: "<<endl
    << "ID : " << id <<endl
    << "Nom : " << nom <<endl
    << "Dimension: "<< endl
    << "Hauteur : " << dimension.getHauteur()<<endl
    << "Largeur: " << dimension.getLargeur()<<endl
    << "Luminance: "<< getLuminance()<<endl
    << "Contraste: "<< getContraste()<<endl;
}


const ImageNG& ImageNG::operator=(const ImageNG& old)
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

ostream& operator<<(ostream& os, const ImageNG& image) 
{
    os << "-Detail ImageNG: "<<endl
    << "Id : "<< image.getId()<<endl
    <<"Nom :" <<image.getNom()<<endl
    << "Dimension: "<< endl
    <<"Hauteur: "<<image.getDimension().getHauteur()<<endl <<"Largeur: "<<image.getDimension().getLargeur() <<endl
    << "Luminance: "<< image.getLuminance()<<endl
    << "Contraste: "<< image.getContraste()<<endl;

    return os;
}

ImageNG ImageNG::operator+(int valeur) const 
{
    ImageNG newImage(*this);
    for (int x = 0; x <  newImage.getDimension().getLargeur(); x++) 
    {
        for (int y = 0; y < newImage.getDimension().getHauteur(); y++) {
            int niveauGris = newImage.getPixel(x, y);
            niveauGris += valeur;
            if(niveauGris > 255){ niveauGris=255;}
            newImage.setPixel( x,y, niveauGris);
        }
    }
    return newImage;
}

ImageNG operator+(int valeur,const ImageNG& i)
{
    return i + valeur;
}

ImageNG ImageNG::operator-(int valeur) const 
{
    ImageNG newImage(*this);
    for (int x = 0; x < newImage.getDimension().getLargeur(); x++) 
    {
        for (int y = 0; y < newImage.getDimension().getHauteur(); y++) 
        {
            int niveauGris = newImage.getPixel(x, y);
            niveauGris -= valeur;
            if(niveauGris < 0){ niveauGris=0;}
            newImage.setPixel( x,y, niveauGris);
        }
    }
    return newImage;
}

ImageNG& ImageNG::operator++() 
{
    for (int x = 0; x < dimension.getLargeur(); x++) {
        for (int y = 0; y < dimension.getHauteur(); y++) 
        {
            int pixel = matrice[x][y] + 20;
            if (pixel > 255) {matrice[x][y] = 255;} 
            else {matrice[x][y] = pixel;}
        }
    }
    return *this;
}

ImageNG ImageNG::operator++(int) 
{
    ImageNG newImage(*this);
    ++(*this);
    return newImage;
}

ImageNG& ImageNG::operator--() 
{
    for (int x = 0; x < dimension.getLargeur(); x++) 
    {
        for (int y = 0; y < dimension.getHauteur(); y++) 
        {
            int pixel= matrice[x][y] - 20;
            if (pixel < 0) {matrice[x][y] = 0;} 
            else {matrice[x][y] = pixel;}
        }
    }
    return *this;
}

ImageNG ImageNG::operator--(int) 
{
    ImageNG newImage(*this);
    --(*this);
    return newImage;
}

ImageNG ImageNG::operator-(const ImageNG& other) const 
{
    ImageNG newImage(*this);

    for (int x = 0; x < newImage.getDimension().getLargeur(); x++) 
    {
        for (int y = 0; y < newImage.getDimension().getHauteur(); y++) 
        {
            int niveauGris = newImage.getPixel(x, y) - other.getPixel(x, y);
            if(niveauGris<0){ niveauGris=0;}
            newImage.setPixel(x, y, niveauGris);
        }
    }
    return newImage;
}

bool ImageNG::operator<(const ImageNG& other) const 
{
    if(this->getDimension().getLargeur() != other.getDimension().getLargeur() && this->getDimension().getHauteur() != other.getDimension().getHauteur())
    {
        throw XYException("Dimension invalide !",'d');
    }
    else if(this->getDimension().getLargeur() != other.getDimension().getLargeur()){throw XYException("Dimension invalide !",'x');}
    else if(this->getDimension().getHauteur() != other.getDimension().getHauteur()){throw XYException("Dimension invalide !",'y');}
        
    ImageNG newImage(*this);
    int L_Image=0, R_Image=0;

    for (int x = 0; x < newImage.getDimension().getLargeur(); x++) 
    {
        for (int y = 0; y < newImage.getDimension().getHauteur(); y++) 
        {
            L_Image += newImage.getPixel(x, y) ;
            R_Image += other.getPixel(x, y);
        }
    }

    if(L_Image < R_Image ){return true;}
    else{return false;} 
}

bool ImageNG::operator>(const ImageNG& other) const 
{

    if((*this).getDimension().getLargeur() != other.getDimension().getLargeur() && (*this).getDimension().getHauteur() != other.getDimension().getHauteur())
    {
        throw XYException("Dimension invalide !",'d');
    }
    else if((*this).getDimension().getLargeur() != other.getDimension().getLargeur()){throw XYException("Dimension invalide !",'x');}
    else if((*this).getDimension().getHauteur() != other.getDimension().getHauteur()) {throw XYException("Dimension invalide !",'y');}

    ImageNG newImage(*this);
    int L_Image=0, R_Image=0;

    for (int x = 0; x < newImage.getDimension().getLargeur(); x++) 
    {
        for (int y = 0; y < newImage.getDimension().getHauteur(); y++) 
        {
            L_Image += newImage.getPixel(x, y) ;
            R_Image += other.getPixel(x, y);
        }
    }

    if(L_Image > R_Image ){return true;}
    else{return false;} 
}

bool ImageNG::operator==(const ImageNG& other) const 
{
    if((*this).getDimension().getLargeur() != other.getDimension().getLargeur() && (*this).getDimension().getHauteur() != other.getDimension().getHauteur())
    {
        throw XYException("Dimension invalide !",'d');
    }
    else if((*this).getDimension().getLargeur() != other.getDimension().getLargeur()){throw XYException("Dimension invalide !",'x');}
    else if((*this).getDimension().getHauteur() != other.getDimension().getHauteur()) {throw XYException("Dimension invalide !",'y');}


    ImageNG newImage(*this);
    int L_Image=0, R_Image=0;

    for (int x = 0; x < newImage.getDimension().getLargeur(); x++) 
    {
        for (int y = 0; y < newImage.getDimension().getHauteur(); y++) 
        {
            L_Image += newImage.getPixel(x, y) ;
            R_Image += other.getPixel(x, y);
        }
    }

    if(L_Image == R_Image ){return true;}
    else{return false;}  
}

void ImageNG::Save(ofstream & fichier) const
{
    Image::Save(fichier);


    for (int i = 0; i < dimension.getLargeur(); i++)
    {
        for (int j = 0; j < dimension.getHauteur(); j++)
        {
            fichier.write((char*)(&matrice[i][j]), sizeof(int));
        }
    }

    cout<< ">>>ImageNG : Save <<<"<<endl;
}

void ImageNG::Load(ifstream & fichier)
{
    if(!fichier)
  {
    cout<<"!!! ERREUR D'OUVERTURE FICHIER !!!"<<endl;
  }

  else
  {
    Image::Load(fichier);

    for (int i = 0; i < dimension.getLargeur(); i++)
    {
        for (int j = 0; j < dimension.getHauteur(); j++)
        {
            fichier.read((char*)(&matrice[i][j]), sizeof(int));
        }
    }

    cout<< ">>>ImageNG : Load <<<"<<endl;
  }

}