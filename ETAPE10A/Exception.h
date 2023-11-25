#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
#include <string>
using namespace std;


class Exception
{
protected:
	string message;
public:

	/*constructeur par defaut*/
	Exception();

	/* contructeur d'initialisation | parametre*/
	Exception(const string mess);

	/*Constructeur de copie*/
	Exception(const Exception &excep);

	/*destructeur*/
	~Exception();


	void setMessage(const string mess);

	string getMessage()const;

};
#endif