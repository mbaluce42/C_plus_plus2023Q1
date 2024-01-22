#include <iostream>
#include "PhotoShop.h"
#include "Image.h"
#include "ImageNG.h"
#include "ImageRGB.h"
#include "ImageB.h"
#include "Iterateur.h"
#include <fstream>
#include <sstream>
#include <string>
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

void PhotoShop::setNumCourant(int num)
{
    numCourant=num;
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

int PhotoShop::importeImages(string nomFichier)
{
  ifstream fichier(nomFichier);
  if (!fichier)
  {
    // impossible d'ouvrir le fichier
    return 0;
  }

  string ligne;
  int cpt = 0;

  while (getline(fichier, ligne))
  {
    // separe les champs de la ligne ';'
    stringstream ss(ligne);
    string typeImage, nomFichierImage, nomImage;
    getline(ss, typeImage, ';');
    getline(ss, nomFichierImage, ';');
    getline(ss, nomImage, ';');

    // cree l'objet image en fonction du type
    Image* image = NULL;
    if (typeImage == "NG")
    {
      image = new ImageNG(nomFichierImage.c_str());
      image->setNom(nomImage);
    }
    else if (typeImage == "RGB")
    {
      image = new ImageRGB(nomFichierImage.c_str());
      image->setNom(nomImage);
    }

    // ajout l'image dans la liste(bibliothèque)
    if (image != NULL)
    {
      instance.ajouteImage(image);
      cpt++;
    }
  }

  return cpt;
}

void PhotoShop::Save()
{
    ofstream file("sauvegarde.dat", ios::binary);

    file.write((char *)&numCourant, sizeof(int));

   
    ImageB::couleurTrue.Save(file);
    ImageB::couleurFalse.Save(file);

    int numImages = images.getNombreElements();
    file.write((char *)&numImages, sizeof(int));

    // Écrire chaque image
    Iterateur<Image*> it(images);
    while (!it.end())
    {
        Image* image = (Image*)it; // Obtenez l'image pointée par l'itérateur    

        int type = 0;
        if(dynamic_cast<ImageNG*>(image) != NULL)
        {
            type = 1;
            file.write((char*)&type, sizeof(int));
            ImageNG* imageNG = dynamic_cast<ImageNG*>(image);
            imageNG->Save(file);
        }
        else if(dynamic_cast<ImageRGB*>(image)!= NULL)
        {
            type = 2;
            file.write((char*)&type, sizeof(int));
            ImageRGB* imageRGB = dynamic_cast<ImageRGB*>(image);
            imageRGB->Save(file);
        }
        else if(dynamic_cast<ImageB*>(image)!= NULL)
        {
            type = 3;
            file.write((char*)&type, sizeof(int));
            ImageB* imageB = dynamic_cast<ImageB*>(image);
            imageB->Save(file);
        }
        ++it;
    }
    file.close();
    cout<< ">>>PhotoShop : Save <<<"<<endl;
}

void PhotoShop::Load()
{
    std::ifstream file("sauvegarde.dat", ios::binary);

    if (file.peek() == std::ifstream::traits_type::eof())
    {
        // Le fichier est vide
        cout << "Le fichier est vide." << endl;
        return;
    }

    file.read((char*)&numCourant, sizeof(int));

    ImageB::couleurTrue.Load(file);
    ImageB::couleurFalse.Load(file);

    int numImages;
    file.read((char*)&numImages, sizeof(int));

    // Lire chaque image
    for(int i = 0; i < numImages; i++)
    {
        // Lire le type d'image
        int type;
        file.read((char*)&type, sizeof(int));

        // Crée et lit l'image
        Image* image;
        ImageNG imgNG;  ImageRGB imgRGB;  ImageB imgB;
        switch(type)
        {
            case 1:
                imgNG.Load(file);
                image = new ImageNG(imgNG);
                break;
            case 2:
                imgRGB.Load(file);
                image = new ImageRGB(imgRGB);
                break;
            case 3:
                
                imgB.Load(file);
                image = new ImageB(imgB);
                break;
        }
        images.insereElement(image);
    }
    file.close();
    cout<< ">>>PhotoShop : Load <<<"<<endl;
}