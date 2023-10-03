#ifndef IMAGENG_H
#define IMAGENG_H
#include "Dimension.h"


class ImageNG {
public:
    static const int L_MAX = 700;
    static const int H_MAX = 700;

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

    void setPixel(int x, int y, int val);
    int getPixel(const int x,const int y) const;
    void setBackground(int val);
    
    void Affiche() const;

    void Dessine() const;
    void importFromFile(const char* fichier);
    void exportToFile(const char* fichier,const char* format)const ;

};

#endif
