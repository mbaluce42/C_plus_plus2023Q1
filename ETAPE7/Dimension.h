#ifndef DIMENSION_H
#define DIMENSION_H

#include <iostream>
#include <ostream>
#include <cstring>
#include <string>
using namespace std;

class Dimension {
private:
    int hauteur;
    int largeur;

public:
    // Constructeurs
    Dimension();
    Dimension(int larg, int haut);
    Dimension(const Dimension& d); // Constructeur de copie
    
    // Destructeur
    ~Dimension();

    // Getters et Setters
    void setLargeur(int larg) ;
    int getLargeur() const;
    void setHauteur(int haut) ;
    int getHauteur() const;

    static const Dimension VGA;
    static const Dimension HD;
    static const Dimension FULL_HD;

    friend ostream& operator<<(ostream& os, const Dimension& dimension);
    friend istream& operator>>(istream& is, Dimension& dimension);

    bool operator==(const Dimension& other) const ;
    bool operator!=(const Dimension& other) const;


    
    void Affiche() const;
};

#endif
