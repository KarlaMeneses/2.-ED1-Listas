#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
//added
#include <iostream>
#include "UListavector.h"
#include "UListapuntero.h"
#include "UListamemoria.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{   /*  VECTORES
	ListaV* lista= new ListaV();
	lista->inserta(0,10);
	lista->inserta(0,20);
	lista->inserta(0,30);
	lista->inserta_primero(555);
	lista->inserta_ultimo(25);
	int x = lista->recupera(0);
	int y = lista->primero();
	int z = lista->fin();
	int l = lista->longuitud();
	int k = lista->siguiente(6);
	int p = lista->anterior(4);
	lista->mostrar();
	lista->modifica(8,789);
	//cout<<" la posicion anterior es:  "<<p<<endl;
	//cout<<"La siguiente posicion es:  "<<k<<endl;
	//lista->mostrar();
	//lista->suprime(-1);
	lista->mostrar();
	//cout<<"El valor de la posicion 0 es: "<<x<<endl;
	//cout<<"La primera posicion es: "<<y<<endl;
	//cout<<"La ultima posicion es: "<<z<<endl;
	cout<<"La longitud es:  "<<l<<endl;   */

	/*PUNTEROS
	ListaP* lista=new ListaP();
	lista->inserta(lista->primero(),10);
	lista->inserta(lista->primero(),11);
	lista->inserta(lista->primero(),12);
	cout<<lista->mostrar()<<endl;
	lista->inserta_ultimo(25);
	lista->inserta_primero(555);
	cout<<lista->mostrar()<<endl;
	lista->suprime(lista->primero());//se envia un puntero
	cout<<lista->mostrar()<<endl;
	lista->modifica(lista->anterior(lista->fin()),29);
	cout<<lista->mostrar()<<endl;   */


	ListaP* lista = new ListaP();
	lista->inserta_ultimo(1);
	lista->inserta_ultimo(2);
	lista->inserta_ultimo(2);
	lista->inserta_ultimo(4);
	lista->inserta_ultimo(8);
    cout<<lista->mostrar()<<endl;
	lista->suprime(lista->primero());
	//cout<<lista->IsPalindrome()<<endl;
	lista->DeleteRepetidos();
	cout<<lista->mostrar()<<endl;
	system("pause");
	return 0;
}
