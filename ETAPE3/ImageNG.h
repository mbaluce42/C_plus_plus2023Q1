#ifndef IMAGENG_H
#define IMAGENG_H
#include "Dimension.h"

class ImageNG {
private:
    int id;
    char* nom;
    Dimension dimension;
    int matrice[L_MAX][H_MAX];
    
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

    void setPixel(const int x, const int y, const int val);
    int getPixel(const int x,const int y) const;
    void setBackground(int val);

    static const int L_MAX = 500;
    static const int H_MAX = 500;

    
    void Affiche() const;

    void Dessiner() const;

};

#endif
