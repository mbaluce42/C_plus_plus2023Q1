#ifndef IMAGENG_H
#define IMAGENG_H

class ImageNG {
private:
    int id;
    char* nom;

public:
    // Constructeurs
    ImageNG();
    ImageNG(int id, const char* nom);
    ImageNG(const ImageNG& other); // Constructeur de copie

    // Destructeur
    ~ImageNG();

    // Getters et Setters
    void setId(int id);
    int getId() const;
    void setNom(const char* nom);
    const char* getNom() const;
    
    
    void Affiche() const;
};

#endif
