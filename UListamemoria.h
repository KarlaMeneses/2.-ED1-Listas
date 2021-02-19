//---------------------------------------------------------------------------

#ifndef UListamemoriaH
#define UListamemoriaH
//---------------------------------------------------------------------------
//added
#include <iostream>
#include <string>
#include "Umemoria.h"
using namespace std; //para el string

const string datoL= "elemento,sig";
const string elementL="->elemento";
const string sigL="->sig";

class ListaSM{
	private:
		int PtrElementos;
		int longitud;
		CSMemoria* mem;
	public:
		ListaSM();
		int fin();
		int primero();
		int siguiente(int dir);
		int anterior(int dir);
		bool vacia();
		int recupera(int dir);
		int longuitud ();
		void inserta(int dir,int element);
		void inserta_primero(int element);
		void inserta_ultimo(int element);
		void suprime(int dir);
		void modifica(int dir,int element);		string mostrar();        int localiza(int e);		void elimina_dato(int e);
		void anula();};
#endif
