#ifndef IMAGEB_H
#define IMAGEB_H

#include "Image.h"
#include "Couleur.h"

class ImageB : public Image 
{
public:
static Couleur couleurTrue;
static Couleur couleurFalse;

protected:

bool matrice[L_MAX][H_MAX];

public:
    
    // Constructeurs
    ImageB();
    ImageB(int id, const string& nom);
    ImageB(int id, const string& nom, const Dimension& dimension);
    ImageB(const ImageB& old);
    // Destructeur
    ~ImageB();

    void setBackground(const bool valeur);
    void setPixel(int x, int y, const bool valeur);
    bool getPixel(int x, int y) const;
    
    void exportToFile(const char* fichier, const char* format) const;
    
    ImageB& operator=(const ImageB& old);
    
    friend ostream& operator<<(ostream& os, const ImageB& image);

    void Affiche() const;
    void Dessine() const;

    void Save(ofstream & fichier) const;
    void Load(ifstream & fichier);

};

#endif
