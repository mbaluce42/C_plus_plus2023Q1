#ifndef XYEXCEPTION_H
#define XYEXCEPTION_H

#include "Exception.h"

#include <iostream>
#include <string>
using namespace std;


class XYException : public Exception
{
protected:
	char coordonne;
public:
	/*constructeur par defaut*/
	XYException();

	/* contructeur d'initialisation | parametre*/
	XYException(const string mess, const char coordonne);

	/*Constructeur de copie*/
	XYException(const XYException &old);

	/*destructeur*/
	~XYException();


	void setCoordonne(const char coordonne);

	char getCoordonne()const;



};
#endif