#include "Traitements.h"
#include "SortedArrayList.h"
#include <algorithm>


ImageB Traitements::Seuillage(const ImageNG& imageIn, int seuil)
{
    ImageB imageOut(imageIn.getId(), imageIn.getNom() +"-seuil" + to_string(seuil) , imageIn.getDimension() );
    
    for(int x=0; x< imageIn.getDimension().getLargeur();x++)
    {
        for(int y=0; y<imageIn.getDimension().getHauteur();y++)
        {
            int InNiveauGris= imageIn.getPixel(x,y);
            bool newOutPixel;
            if(InNiveauGris> seuil)
            {
                newOutPixel= true;
                imageOut.setPixel(x,y,newOutPixel);//met le nouveau pixel 
            }
            else if(InNiveauGris< seuil)
            {
                newOutPixel= false;
                imageOut.setPixel(x,y,newOutPixel);//met le nouveau pixel 
            }
        }
    }
    return imageOut;
}

ImageNG Traitements::FiltreMoyenneur(const ImageNG& imageIn, int taille)
{

    if(taille % 2 == 0 ){ cout<<"La Taille n'est pas impaire !!!"<<endl;}
    else
    {
        int reculer= taille/2.0;
        int nbrPixelMoy;// pour le nombre de pixel a moyenner
        ImageNG imageOut(imageIn.getId(), imageIn.getNom() +"-moyenne" + to_string(taille) , imageIn.getDimension() );
        for(int x=0; x< imageIn.getDimension().getLargeur();x++)
        {
            for(int y=0; y<imageIn.getDimension().getHauteur();y++)
            {
                //cout <<endl<<"reculer= "<< reculer<<endl;
                int sum=0;
                int nbrPixelMoy=0;
                //y=4 x=2
                for(int i=x-reculer; i<(x-reculer+taille);i++)
                {
                    for(int j=y-reculer; j<(y-reculer+taille);j++)
                    {
                        if(i < 0 || i >= imageIn.getDimension().getLargeur()  || j < 0 || j >= imageIn.getDimension().getHauteur())
                        {
                            // Le point est en dehors de la matrice
                            //sum+=0;
                        }
                        else 
                        {
                            // Le point est dans la matrice
                            sum+=imageIn.getPixel(i,j);
                            nbrPixelMoy+=1;
                        }
                    }
                }
                //set new pixel moyenner a imageOut
                imageOut.setPixel(x,y,(int)(sum/(double)(nbrPixelMoy)));
            }
        }
        return imageOut;
    }
}

ImageNG Traitements::FiltreMedian(const ImageNG& imageIn, int taille)
{

    if(taille % 2 == 0 ){ cout<<"La Taille n'est pas impaire !!!"<<endl;}
    else
    {
        int reculer= taille/2.0;
        ImageNG imageOut(imageIn.getId(), imageIn.getNom() +"-median" + to_string(taille) , imageIn.getDimension() );
        for(int x=0; x< imageIn.getDimension().getLargeur();x++)
        {
            for(int y=0; y<imageIn.getDimension().getHauteur();y++)
            {
                SortedArrayList<int> liste;
                //y=4 x=2
                for(int i=x-reculer; i<(x-reculer+taille);i++)
                {
                    for(int j=y-reculer; j<(y-reculer+taille);j++)
                    {
                        if(i < 0 || i >= imageIn.getDimension().getLargeur()  || j < 0 || j >= imageIn.getDimension().getHauteur())
                        {
                            // Le point est en dehors de la matrice
                        }
                        else 
                        {
                            // Le point est dans la matrice
                            liste.insereElement(imageIn.getPixel(i,j));
                        }
                    }
                }
                //set new pixel moyenner a imageOut
                int moyenne = (int)((double)liste.getNombreElements()/ 2.0);
                imageOut.setPixel(x,y,liste.getElement(moyenne));
            }
        }
        return imageOut;
    }
}

ImageNG Traitements::Erosion(const ImageNG& imageIn, int taille)
{

    if(taille % 2 == 0 ){ cout<<"La Taille n'est pas impaire !!!"<<endl;}
    else
    {
        int reculer= taille/2.0;
        ImageNG imageOut(imageIn.getId(), imageIn.getNom() +"-erode" + to_string(taille) , imageIn.getDimension() );
        for(int x=0; x< imageIn.getDimension().getLargeur();x++)
        {
            for(int y=0; y<imageIn.getDimension().getHauteur();y++)
            {
                SortedArrayList<int> liste;
                //y=4 x=2
                for(int i=x-reculer; i<(x-reculer+taille);i++)
                {
                    for(int j=y-reculer; j<(y-reculer+taille);j++)
                    {
                        if(i < 0 || i >= imageIn.getDimension().getLargeur()  || j < 0 || j >= imageIn.getDimension().getHauteur())
                        {
                            // Le point est en dehors de la matrice
                        }
                        else 
                        {
                            // Le point est dans la matrice
                            liste.insereElement(imageIn.getPixel(i,j));
                            
                        }
                    }
                }
                //set new pixel moyenner a imageOut
                Iterateur<int> it(liste);
                int *min = min_element(&liste.getElement(0),&liste.getElement(liste.getNombreElements()-1) ) ;
                imageOut.setPixel(x,y,liste.getElement(*min));
            }
        }
        return imageOut;
    }
}

ImageNG Traitements::Dilatation(const ImageNG& imageIn, int taille) 
{

    if(taille % 2 == 0 ){ cout<<"La Taille n'est pas impaire !!!"<<endl;}
    else
    {
        int reculer= taille/2.0;
        ImageNG imageOut(imageIn.getId(), imageIn.getNom() +"-erode" + to_string(taille) , imageIn.getDimension() );
        for(int x=0; x< imageIn.getDimension().getLargeur();x++)
        {
            for(int y=0; y<imageIn.getDimension().getHauteur();y++)
            {
                SortedArrayList<int> liste;
                //y=4 x=2
                for(int i=x-reculer; i<(x-reculer+taille);i++)
                {
                    for(int j=y-reculer; j<(y-reculer+taille);j++)
                    {
                        if(i < 0 || i >= imageIn.getDimension().getLargeur()  || j < 0 || j >= imageIn.getDimension().getHauteur())
                        {
                            // Le point est en dehors de la matrice
                        }
                        else 
                        {
                            // Le point est dans la matrice
                            liste.insereElement(imageIn.getPixel(i,j));
                        }
                    }
                }
                //set new pixel moyenner a imageOut
                int *max = max_element(&liste.getElement(0),&liste.getElement(liste.getNombreElements()-1) );
                imageOut.setPixel(x,y,liste.getElement(*max));
            }
        }
        return imageOut;
    }
}