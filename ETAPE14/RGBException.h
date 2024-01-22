#ifndef RGBEXCEPTION_H
#define RGBEXCEPTION_H

#include "Exception.h"

#include <iostream>
#include <string>
using namespace std;


class RGBException : public Exception
{
protected:
	int valeur;
public:
	/*constructeur par defaut*/
	RGBException();

	/* contructeur d'initialisation | parametre*/
	RGBException(const string mess, const int val);

	/*Constructeur de copie*/
	RGBException(const RGBException &old);

	/*destructeur*/
	~RGBException();


	void setValeur(const int val);

	int getValeur()const;



};
#endif