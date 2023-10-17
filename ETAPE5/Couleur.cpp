#include "Couleur.h"



const Couleur Couleur::ROUGE(255, 0, 0);
const Couleur Couleur::VERT(0, 255, 0);
const Couleur Couleur::BLEU(0, 0, 255);
const Couleur Couleur::BLANC(255, 255, 255);
const Couleur Couleur::NOIR(0, 0, 0);

Couleur::Couleur() : Couleur(NOIR)
{

}

Couleur::Couleur(const int r,const int v,const int b)
{
    setRouge(r); setVert(v); setBleu(b);
}

Couleur::Couleur(const Couleur& c)
{
    setRouge(c.getRouge()); setVert(c.getVert()); setBleu(c.getBleu());
}

int Couleur::getRouge()const
{
    return rouge;
}

int Couleur::getVert() const
{
    return vert;
}

int Couleur::getBleu() const 
{
    return bleu;
}

void Couleur::setRouge(const int r)
{
    if(r>=0 || r<=255){ rouge=r;}
}

void Couleur::setVert(const int v)
{
    if(v>=0 || v<=255){ vert=v;}
}

void Couleur::setBleu(const int b) 
{
    if(b>=0 || b<=255){ bleu=b;}
}

void Couleur::Affiche() const 
{
    cout<< "Detail Couleur: "<<endl
    << "Rouge : "<<getRouge() <<endl
    <<"Vert : "<<getVert()<<endl
    <<"Bleu: "<<getBleu()<<endl;
}

ostream& operator<<(ostream& os, const Couleur& couleur) 
{
    os<< "Detail Couleur: "<<endl
    << "Rouge : "<<couleur.getRouge() <<endl
    <<"Vert : "<<couleur.getVert()<<endl
    <<"Bleu: "<<couleur.getBleu()<<endl;

    return os;
}

