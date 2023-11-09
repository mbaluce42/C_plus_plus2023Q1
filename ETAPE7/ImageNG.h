#ifndef IMAGENG_H
#define IMAGENG_H
#include "Image.h"




class ImageNG : public Image
{
protected:

    int matrice[L_MAX][H_MAX];
    
public:
    // Constructeurs
    ImageNG();
    ImageNG(int id, const string& nom);
    ImageNG(int id, const string& nom, const Dimension& dimension);
    ImageNG(const ImageNG& old);

    ImageNG(const char* nomFichier);

    // Destructeur
    ~ImageNG();

// Getter pour l'ID
    void setPixel(int x, int y, int val);
    int getPixel(const int x,const int y) const;
    void setBackground(int val);
    int getLuminance() const;
    int getMinimum() const;
    int getMaximun() const;
    float getContraste() const;
    
    void Affiche() const;
    

    void Dessine() const;
    void importFromFile(const char* fichier);
    void exportToFile(const char* fichier,const char* format)const ;

    const ImageNG& operator=(const ImageNG& old);
    friend ostream& operator<<(ostream& os, const ImageNG& image);
    friend ostream& operator<<(ostream& os, const ImageNG& image);
    ImageNG operator+(int valeurn) const;
    friend ImageNG operator+(int valeur,const ImageNG& i);
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