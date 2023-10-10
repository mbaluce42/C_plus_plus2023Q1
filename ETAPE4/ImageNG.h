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

    ImageNG(const char* nomFichier);

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
    int getLuminance() const;
    int getMinimun() const;
    int getMaximun() const;
    float getContraste() const;
    
    void Affiche() const;
    void delMatriceVal();
    

    void Dessine() const;
    void importFromFile(const char* fichier);
    void exportToFile(const char* fichier,const char* format)const ;

    const ImageNG& operator=(const ImageNG& old);
    friend ostream& operator<<(ostream& os, const ImageNG& image);
    ImageNG operator+(int valeur) const;
    ImageNG operator-(int valeur) const;
    ImageNG& operator++(); // Pré-incrémentation
    ImageNG operator++(int); // Post-incrémentation
    ImageNG& operator--(); // Pré-décrémentation
    ImageNG operator--(int); // Post-décrémentation

    ImageNG operator-(const ImageNG& other) const;

    bool operator<(const ImageNG& other) const;
    bool operator>(const ImageNG& other) const;
    bool operator==(const ImageNG& other) const;





};

#endif
