#include "XYException.h"
#define DEBUG


/*constructeur par defaut*/
	XYException::XYException()
	{
		setCoordonne('d');
		#ifdef DEBUG
  		cout << "Je suis le contructeur par defaut XYException" << endl<<endl;
  		#endif
	}

	/* contructeur d'initialisation | parametre*/
	XYException::XYException(const string mess,const char coordonne) : Exception(mess)
	{
		setCoordonne(coordonne);
		#ifdef DEBUG
  		cout << "Je suis le contructeur d'initialisation XYException" << endl<<endl;
  		#endif
	}
	
	/*Constructeur de copie*/
	XYException::XYException(const XYException &old) : Exception(old)
	{
		setCoordonne(old.getCoordonne());
		#ifdef DEBUG
  		cout << "Je suis le Constructeur de copie XYException" << endl<<endl;
  		#endif
	}

	/*destructeur*/
	XYException::~XYException()
	{
		#ifdef DEBUG
  		cout << "Je suis le destructeur XYException" << endl<<endl;
  		#endif
	}


	void XYException::setCoordonne(const char coordonne)
	{
		this->coordonne= coordonne;
	}

	char XYException::getCoordonne()const
	{
 		return coordonne;
	}
