#include <iostream>
#include "PhotoShop.h"
#include "Image.h"
#include "Iterateur.h"
using namespace std;

int PhotoShop::numCourant = 1;

PhotoShop::PhotoShop()
{
    images = ArrayList<Image*>();
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
    images= ArrayList<Image*>();// Vidage de la liste d'images
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
    Iterateur<Image*> it(images);

    while (!it.end())
    {
        Image* image = it;  // Obtenez l'image pointée par l'itérateur
        // Utilisez 'image' comme nécessaire, par exemple, affichez-le
        image->Affiche();

        it++;  // Passez à l'élément suivant
    }
}



void PhotoShop::dessineImages() const
{
    Iterateur<Image*> it(images);

    while (!it.end())
    {
        Image* image = it;  // Obtenez l'image pointée par l'itérateur
        // Utilisez 'image' comme nécessaire, par exemple, affichez-le
        image->Dessine();

        it++;  // Passez à l'élément suivant
    }
}


Image* PhotoShop::getImageParIndice(int indice)
{


}


Image* PhotoShop::getImageParId(int id)
{

}


void PhotoShop::supprimeImageParIndice(int ind)
{

}


void PhotoShop::supprimeImageParId(int id)
{

}