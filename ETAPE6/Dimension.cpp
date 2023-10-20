#include "Dimension.h"
#include "XYException.h"



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
    else{ throw  XYException("Dimension invalide !" ,'x');}

}

void Dimension::setHauteur(int haut)
{
    if(haut >0){this->hauteur= haut;}
    else{ throw  XYException("Dimension invalide !" ,'y');}

}

ostream& operator<<(ostream& os, const Dimension& dimension) 
{
    os<< "Detail Dimension: "<<endl
    << "Largeur : "<<dimension.getLargeur() <<endl
    <<"Hauteur : "<<dimension.getHauteur()<<endl;
    return os;
}

istream& operator>>(istream& is, Dimension& dimension) 
{
    int larg, haut;
    cout<<"Saisissez les dimension de la matrice: "<<endl;
    cout<<"Largeur: ";
    is >> larg;
    cout<<"Hauteur: ";
    is >> haut;
    dimension.setLargeur(larg);
    dimension.setHauteur(haut);
    return is;
}


bool Dimension::operator==(const Dimension& other) const 
{
    if ((*this).largeur == other.largeur && (*this).hauteur == other.hauteur) 
    {
        return true;
    } 
    else 
    {
        return false;
    }
}


bool Dimension::operator!=(const Dimension& other) const 
{
    if ((*this).largeur != other.largeur || (*this).hauteur != other.hauteur) 
    {
        return true;
    } 
    else {return false;}
}



void Dimension::Affiche() const 
{
    cout<< "Detail Dimension: "<<endl
    << "Largeur : " << largeur<<endl
    << "Hauteur : " << hauteur<<endl;
}