#ifndef IMAGENG_H
#define IMAGENG_H
#include "Dimension.h"


class Image 
{

protected:
    int id;
    string nom;
    Dimension dimension;
    
public:
    // Constructeurs
    Image();
    Image(int id, const string& nom);
    Image(int id, const string& nom, const Dimension& dimension);
    Image(const Image& old);

    Image(const char* nomFichier);

    // Destructeur
    ~Image();

    // Getters et Setters
    void setId(int id);
    int getId() const;
    void setNom(const string& nom);
    const string& getNom() const;
    void setDimension(const Dimension& dimension); 
    const Dimension& getDimension() const;
    
    // methode virtuelle pure
    virtual void Affiche() const=0;
    virtual void Dessine() const=0;
    virtual void exportToFile(const char* fichier,const char* format)const =0;
};

#endif






