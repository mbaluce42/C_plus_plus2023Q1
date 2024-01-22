#ifndef IMAGERGB_H
#define IMAGERGB_H

#include "Image.h"
#include "Couleur.h"

class ImageRGB : public Image 
{
protected:
Couleur matrice[L_MAX][H_MAX];

public:
    
    // Constructeurs
    ImageRGB();
    ImageRGB(int id, const string& nom);
    ImageRGB(int id, const string& nom, const Dimension& dimension);
    ImageRGB(const ImageRGB& old);
    ImageRGB(const char* nomFichier);
    // Destructeur
    ~ImageRGB();

    void setBackground(const Couleur& couleur);
    void setPixel(int x, int y, const Couleur& couleur);
    Couleur getPixel(int x, int y) const;
    
    void importFromFile(const char* fichier);
    void exportToFile(const char* fichier, const char* format) const;
    
    ImageRGB& operator=(const ImageRGB& old);
    
    friend ostream& operator<<(ostream& os, const ImageRGB& image);

    void Affiche() const;
    void Dessine() const;

    void Save(ofstream & fichier) const;
    void Load(ifstream & fichier);

};

#endif
