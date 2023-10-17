#include "Exception.h"
#define DEBUG


/*constructeur par defaut*/
Exception::Exception()
{
	  setMessage("ERREUR");
  	#ifdef DEBUG
  	cout << "Je suis le contructeur par defaut Exception" << endl<<endl;
  	#endif
}

/* contructeur d'initialisation | parametre*/
Exception::Exception(const string mess)
{
	setMessage(mess);

  	#ifdef DEBUG
  	/*comme le contructeur par defaut sauf qu'il est parametre*/
  	cout << "Je suis le contructeur d'initialisation Exception" << endl<<endl;
  	#endif
}

/*Constructeur de copie*/
Exception::Exception(const Exception &excep)
{
    setMessage(excep.getMessage());
    
    #ifdef DEBUG
    /*comme le contructeur par defaut sauf qu'il est parametre*/
    cout << "Je suis le contructeur de copie Exception" << endl<<endl;
    #endif
}

/*destructeur*/
Exception::~Exception()
{
  #ifdef DEBUG
  cout << "Je suis le destructeur Exception" << endl<<endl;
  #endif
}


void Exception::setMessage(const string mess)
{
  message= mess;
}

string Exception::getMessage()const
{
  return message;
}

