#ifndef DIMENSION_H
#define DIMENSION_H

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
    
    void Affiche() const;
};

#endif
