#ifndef COULEUR_H
#define COULEUR_H

#include <iostream>
#include <cstring>
#include <string>

using namespace std;


class Couleur 
{
private:
    int rouge;
    int vert;
    int bleu;

public:
    //coonstructeur
    Couleur();
    Couleur(const int r, const int v, const int b);
    Couleur(const Couleur& c);
    //Set et get
    int getRouge()const ;
    int getVert() const ;
    int getBleu() const ;

    void setRouge(const int r);
    void setVert(const int v);
    void setBleu(const int b);

    void Affiche() const;

    friend ostream& operator<<(ostream& os, const Couleur& couleur);


    static const Couleur ROUGE;
    static const Couleur VERT;
    static const Couleur BLEU;
    static const Couleur BLANC;
    static const Couleur NOIR;
};

#endif









