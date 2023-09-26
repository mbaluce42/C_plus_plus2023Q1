#ifndef IMAGENG_H
#define IMAGENG_H
#include "Dimension.h"

class ImageNG {
private:
    int id;
    char* nom;
    Dimension dimension;

public:
    // Constructeurs
    ImageNG();
    ImageNG(int id, const char* nom);
    ImageNG(int id, const char* nom, const Dimension& dimension);
    ImageNG(const ImageNG& img);
    

    // Destructeur
    ~ImageNG();

    // Getters et Setters
    void setId(int id);
    int getId() const;
    void setNom(const char* nom);
    const char* getNom() const;
    void setDimension(const Dimension& dimension); 
    const Dimension& getDimension() const;

    
    void Affiche() const;
};

#endif
