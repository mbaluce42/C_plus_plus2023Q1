#include "RGBException.h"
#define DEBUG


/*constructeur par defaut*/
	RGBException::RGBException()
	{
		setValeur(0);
		#ifdef DEBUG
  		cout << "Je suis le contructeur par defaut RGBException" << endl<<endl;
  		#endif
	}

	/* contructeur d'initialisation | parametre*/
	RGBException::RGBException(const string mess,const int val) : Exception(mess)
	{
		setValeur(val);
		#ifdef DEBUG
  		cout << "Je suis le contructeur d'initialisation RGBException" << endl<<endl;
  		#endif
	}
	
	/*Constructeur de copie*/
	RGBException::RGBException(const RGBException &old) : Exception(old)
	{
		setValeur(old.getValeur());
		#ifdef DEBUG
  		cout << "Je suis le Constructeur de copie RGBException" << endl<<endl;
  		#endif
	}

	/*destructeur*/
	RGBException::~RGBException()
	{
		#ifdef DEBUG
  		cout << "Je suis le destructeur RGBException" << endl<<endl;
  		#endif
	}


	void RGBException::setValeur(const int val)
	{
		valeur= val;
	}

	int RGBException::getValeur()const
	{
 		return valeur;
	}
