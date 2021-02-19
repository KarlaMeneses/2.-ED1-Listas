//---------------------------------------------------------------------------

#ifndef UListavectorH
#define UListavectorH
//---------------------------------------------------------------------------
//added
#include<string>     //without this it makes an error in type string!
using namespace std; //without this it makes an error in type string!

const int MAXVE=100;
const int NULOVE=0;

typedef int direccion;

class ListaV{
	private:
		int elementos[MAXVE]; //guarda dato
		int longitud;
	public:
		ListaV();//
		direccion fin();//
		direccion primero();//
		direccion siguiente(direccion dir);//
		direccion anterior(direccion dir);//
		bool vacia();//
		int recupera(direccion dir);// devuelve el valor de la posicion
		int longuitud();//
		void inserta(direccion dir, int element );//
		void inserta_primero(int element);//
		void inserta_ultimo(int element);//
		void suprime(direccion dir);//
		void modifica(direccion dir, int element);//
		void mostrar();//
		/////
		direccion localiza(int element);//
		void eliminaDato(int element);//
		void anula();//
};
#endif
