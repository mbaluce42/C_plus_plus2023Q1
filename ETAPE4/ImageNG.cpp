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
    delMatriceVal();
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
    delMatriceVal();

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

ImageNG::ImageNG(const char* nomFichier)
{
    setId(0); 
    setNom(nomFichier);
    dimension.setHauteur(300);
    dimension.setLargeur(400);
    //setDimension(Dimension(dimension.getLargeur(), dimension.getHauteur())); 
    MyQT::ImportFromFile(*this, nomFichier);
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
    
    for(int x=0;x<=dimension.getLargeur(); x++)
    {
        for(int y=0; y<=dimension.getHauteur(); y++)
        {
            setPixel(x,y,val);
        }
    }
}

int ImageNG::getLuminance() const
{
    int somme=0;
    int nbrElem= dimension.getHauteur()*dimension.getLargeur();

    for(int x=0;x<=dimension.getLargeur(); x++)
    {
        for(int y=0; y<=dimension.getHauteur(); y++)
        {
            somme+= matrice[x][y];
        }
    }
    return (somme/nbrElem);
}

int ImageNG::getMinimum() const
{
    int min=matrice[0][0];
    for(int x=0;x<=dimension.getLargeur(); x++)
    {
        for(int y=1; y<=dimension.getHauteur(); y++)
        {
            if(matrice[x][y]<min){min=matrice[x][y]; }
        }
    }
    return min;
}

int ImageNG::getMaximun() const
{
    int max=matrice[0][0];
    for(int x=0;x<=dimension.getLargeur(); x++)
    {
        for(int y=1; y<=dimension.getHauteur(); y++)
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
    cout << "ID : " << id <<endl;
    cout << "Nom : " << nom <<endl;
    cout << "Hauteur : " << dimension.getHauteur()<<endl;
    cout << "Largeur: " << dimension.getLargeur()<<endl;
}

void ImageNG::delMatriceVal()
{
    for(int x=0;x<=dimension.getLargeur(); x++)
    {
        for(int y=0; y<=dimension.getHauteur(); y++)
        {
            matrice[x][y]=0;
        }
    }  
}

const ImageNG& ImageNG::operator=(const ImageNG& old)
{
    if(this == &old){return *this;}

    setId(old.id);
    setNom(old.nom);
    setDimension(old.dimension);
    delMatriceVal();

    for(int x=0;x<=dimension.getLargeur(); x++)
    {
        for(int y=0; y<=dimension.getHauteur(); y++)
        {
            matrice[x][y]=old.matrice[x][y];
        }
    } 

    return *this;
}

ostream& operator<<(ostream& os, const ImageNG& image) 
{
    os << "Id : "<< image.getId()<<endl
    <<"Nom :" <<image.getNom()<<endl
    << "Dimension: "<< endl<<"Hauteur: "<<image.getDimension().getHauteur()<<endl <<"Largeur: "<<image.getDimension().getLargeur() <<endl
    << "Luminance: "<< image.getLuminance()<<endl
    << "Contraste: "<< image.getContraste()<<endl;
    /*image.getMaximun;
    image.getMinimun;
    image.getPixel;*/
    return os;
}

ImageNG ImageNG::operator+(int valeur) const 
{
    ImageNG newImage(*this);
    for (int x = 0; x <  newImage.getDimension().getLargeur(); ++x) {
        for (int y = 0; y < newImage.getDimension().getHauteur(); ++y) {
            int niveauGris = newImage.getPixel(x, y);
            niveauGris += valeur;
            if(niveauGris > 255){ niveauGris=255;}
            newImage.setPixel( x,y, niveauGris);
        }
    }
    return newImage;
}

ImageNG ImageNG::operator+(int valeur,const ImageNG& i)
{
    return (i+ valeur);
}

ImageNG ImageNG::operator-(int valeur) const 
{
    ImageNG newImage(*this);
    for (int x = 0; x < newImage.getDimension().getLargeur(); ++x) 
    {
        for (int y = 0; y < newImage.getDimension().getHauteur(); ++y) 
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
    for (int x = 0; x < dimension.getLargeur(); ++x) {
        for (int y = 0; y < dimension.getHauteur(); ++y) {
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
    for (int x = 0; x < dimension.getLargeur(); ++x) 
    {
        for (int y = 0; y < dimension.getHauteur(); ++y) 
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

    for (int x = 0; x < newImage.getDimension().getLargeur(); ++x) 
    {
        for (int y = 0; y < newImage.getDimension().getHauteur(); ++y) 
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
    ImageNG newImage(*this);
    int L_Image=0, R_Image=0;

    for (int x = 0; x < newImage.getDimension().getLargeur(); ++x) 
    {
        for (int y = 0; y < newImage.getDimension().getHauteur(); ++y) 
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
    ImageNG newImage(*this);
    int L_Image=0, R_Image=0;

    for (int x = 0; x < newImage.getDimension().getLargeur(); ++x) 
    {
        for (int y = 0; y < newImage.getDimension().getHauteur(); ++y) 
        {
            L_Image += newImage.getPixel(x, y) ;
            R_Image += other.getPixel(x, y);

        }
    }

    if(L_Image > R_Image ){return true;}
    else{return false;} 
}

bool ImageNG::operator==(const ImageNG& other) const {
    ImageNG newImage(*this);
    int L_Image=0, R_Image=0;

    for (int x = 0; x < newImage.getDimension().getLargeur(); ++x) 
    {
        for (int y = 0; y < newImage.getDimension().getHauteur(); ++y) 
        {
            L_Image += newImage.getPixel(x, y) ;
            R_Image += other.getPixel(x, y);

        }
    }

    if(L_Image == R_Image ){return true;}
    else{return false;} 
    
}