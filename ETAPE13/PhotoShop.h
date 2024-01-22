#ifndef PHOTOSHOP_H
#define PHOTOSHOP_H

#include "Image.h"
#include "ArrayList.h"

class PhotoShop 
{
public:
    static Image* operande1;
    static Image* operande2;
    static Image* resultat;
private:
    ArrayList<Image*> images;
    static int numCourant;
private:
    PhotoShop();
    static PhotoShop instance;
    PhotoShop(const PhotoShop& old);
    PhotoShop& operator=(const PhotoShop& old);
    


public:
    
    ~PhotoShop();
    static PhotoShop& getInstance();
    ArrayList<Image*>* getImages();

    void setNumCourant(int num);

    void reset();
    void ajouteImage(Image* pImage);

    void afficheImages() const;
    void dessineImages() const;

    Image* getImageParIndice(int indice);
    Image* getImageParId(int id);

    void supprimeImageParIndice(int ind);
    void supprimeImageParId(int id);

    int importeImages(string nomFichier);
};

#endif 
