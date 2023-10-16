#ifndef IMAGERGB_H
#define IMAGERGB_H

#include "Image.h"
#include "Couleur.h"

class ImageRGB : public Image 
{
private:
Couleur matrice[L_MAX][H_MAX];

public:
    
    ImageRGB();
    ImageRGB(int largeur, int hauteur);
    ImageRGB(const ImageRGB& autre);
    ~ImageRGB();
    
    void setBackground(const Couleur& couleur);
    void setPixel(int x, int y, const Couleur& couleur);
    Couleur getPixel(int x, int y) const;
    
    void importFromFile(const char* fichier);
    void exportToFile(const char* fichier, const char* format) const;
    
    ImageRGB& operator=(const ImageRGB& autre);
    
    friend ostream& operator<<(ostream& os, const ImageRGB& image);

    void Affiche() const;
    void Dessine() const;

};

#endif
