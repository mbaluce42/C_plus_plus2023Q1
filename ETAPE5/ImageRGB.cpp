#include "ImageRGB.h"

ImageRGB::ImageRGB()
{

}

ImageRGB::ImageRGB(int largeur, int hauteur) 
{
    
}

ImageRGB::ImageRGB(const ImageRGB& autre) 
{

}

ImageRGB::~ImageRGB() 
{

}

void ImageRGB::setBackground(const Couleur& couleur) 
{

}

void ImageRGB::setPixel(int x, int y, const Couleur& couleur) 
{

}

Couleur ImageRGB::getPixel(int x, int y) const {
 
    return matrice[x][y];
}

void ImageRGB::importFromFile(const char* fichier) 
{

}

void ImageRGB::exportToFile(const char* fichier, const char* format) const 
{

}

ImageRGB& ImageRGB::operator=(const ImageRGB& autre) 
{

}

ostream& operator<<(ostream& os, const ImageRGB& image) 
{

    return os;
}

void ImageRGB::Affiche() const 
{
 
}

void ImageRGB::Dessine() const 
{

}
