#include <iostream>
#include "PhotoShop.h"
#include "Image.h"
#include "Iterateur.h"
using namespace std;

int PhotoShop::numCourant = 1;
Image* PhotoShop::operande1=NULL;
Image* PhotoShop::operande2=NULL;
Image* PhotoShop::resultat=NULL;

PhotoShop PhotoShop::instance = PhotoShop();

PhotoShop& PhotoShop::getInstance()
{
    return instance;
}

ArrayList<Image*>* PhotoShop::getImages() 
{ return &images; }


PhotoShop::PhotoShop():images()
{
    #ifdef DEBUG
    cout << "Je suis le constructeur par defaut de PhotoShop" << endl<<endl;
    #endif
}

PhotoShop::~PhotoShop()
{
    reset();

    #ifdef DEBUG
    cout << "Je suis le destructeur de PhotoShop" << endl<<endl;
    #endif
}

void PhotoShop::reset()
{
    images= ArrayList<Image *>();// Vidage de la liste d'images
    numCourant = 1; // Remise à 1 de la variable statique
}

void PhotoShop::ajouteImage(Image* pImage)
{
    pImage->setId(numCourant);
    images.insereElement(pImage);
    numCourant++;
}

void PhotoShop::afficheImages() const
{
    Iterateur<Image *> it(images);

    while (!it.end())
    {
        Image* image = (Image*)it;  // Obtenez l'image pointée par l'itérateur
        // Utilisez 'image' comme nécessaire, par exemple, affichez-le
        image->Affiche();

        it++;  // Passez à l'élément suivant
    }
}

void PhotoShop::dessineImages() const
{
    Iterateur<Image *> it(images);

    while (!it.end())
    {
        Image* image = (Image*)it;  // Obtenez l'image pointée par l'itérateur
    
        image->Dessine();

        it++;  // Passez à l'élément suivant
    }
}


Image* PhotoShop::getImageParIndice(int indice)
{
   return images.getElement(indice);
}


Image* PhotoShop::getImageParId(int id)
{
    Iterateur<Image *> it(images);
    while (!it.end())
    {
        Image* image = (Image*)it;  // Obtenez l'image pointée par l'itérateur    
        if(image->getId()==id)
        {
            return &(*image);
        }
        it++;  // Passez à l'élément suivant
    }
    return NULL;
}


void PhotoShop::supprimeImageParIndice(int ind)
{
    images.retireElement(ind);

}


void PhotoShop::supprimeImageParId(int id)
{
    Iterateur<Image *> it(images);
    int cpt=0;

    while (!it.end())
    {
        Image* image = (Image*)it;  // Obtenez l'image pointée par l'itérateur    
        if(image->getId()==id)
        {
            images.retireElement(cpt);
            //delete image;

            break;
        }
        cpt++;
        it++;  // Passez à l'élément suivant
    }
}