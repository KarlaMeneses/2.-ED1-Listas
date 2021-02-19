//---------------------------------------------------------------------------

#pragma hdrstop

#include "UListavector.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//added
#include <iostream>
ListaV::ListaV(){
	longitud=0;

}

direccion ListaV::fin(){
	if (!vacia()) {
		return longitud-1;
	}
	else{
		cout << "Error: La lista esta vacia\n";
	}
}

direccion ListaV::primero(){
	if (!vacia()) {
		return 0;
	}
	else{
		cout << "Error: La lista esta vacia\n";
	}
}

direccion ListaV::siguiente(direccion dir){
	if (vacia()) {
		cout << "Error: La lista esta vacia\n";
	}
	else{
		if (dir<longitud-1) {//si esta en la ultima casilla
			return dir+1;

		}
		else{
			cout << "Error de direccion sigiente "<<dir <<" no es parte del vector\n";
			return -1;
		}
	}
}

direccion ListaV::anterior(direccion dir){
	if (vacia()) {
		cout << "Error: La lista esta vacia\n";
	}
	else{
		if (dir>0 && dir<=longitud-1) {//si esta en la ultima casilla
			return dir-1;
		}
		else{
			cout << "Error de direccion anterior "<<dir<<" no es parte del vector";
			return -1;
		}
	}
}

bool ListaV::vacia(){
	return longitud==0;
}

int ListaV::recupera(direccion dir){
	if (vacia()) {
		cout << "Error: La lista esta vacia\n";

	}
	else{
		if (dir>=0 && dir<=longitud-1) {
			return elementos[dir];
		}
		else{
			cout << "Error de direccion\n";
		}
	}
}

int ListaV::longuitud(){
	return longitud;
}

void ListaV::inserta(direccion dir, int element ){
	if (longitud==MAXVE) {
		cout << "Error: La lista esta llena\n";
		return; //added
	}
	if (vacia()) {//caso 0
		elementos[0]=element;
		longitud++;
		return; //added
	}
	if (dir>=0 && dir<=longitud-1) {  //[55][1][2][3]
		for (int i = longitud; i > dir; i--) {
			elementos[i]=elementos[i-1];
		}
		elementos[dir]=element;
		longitud++;//check! if it isn't at the beginning of all.
	}              //aumentar la cajita al vector para mover todo luego.
	else{
		cout << "Error de direccion\n";
	}
}

void ListaV::inserta_primero(int element){
	if (longitud==MAXVE) {
		cout << "Error: La lista esta llena\n";
		return; //added
	}
	for (int i = longitud; i > 0; i--) {
		elementos[i]=elementos[i-1];
	}
	elementos[0]=element;
	longitud++;//check! if it isn't at the beginning.
			  //aumentar la cajita al vector para mover todo luego.
}

void ListaV::inserta_ultimo(int element){
	if (longitud==MAXVE) {
		cout << "Error: La lista esta llena\n";
		return; //added
	}
	else{
		elementos[longitud]=element;
		longitud++; //at the beginning verificar si es 0 o 1???
	}
}

void ListaV::suprime(direccion dir){
	if (longitud==0) {
		cout << "Error: La lista esta vacia\n";
		return; //added
	}
	else{
		if (dir>=0 && dir<=longitud-1) {
			for (int i =dir; i < longitud-1; i++) {
				elementos[i]=elementos[i+1];
			}
			longitud--;
		}
		else{
			cout << "Error de direccion no se puede suprimir\n";
		}
	}
}

void ListaV::modifica(direccion dir, int element){
	if (longitud==0) {
		cout << "Error: La lista esta vacia\n";
		return; //added
	}
	else{
		if (dir>=0 && dir<=longitud-1) {
			elementos[dir]=element;
		}
		else{
			cout << "Error de direccion no pertenece al vector\n";
		}
	}
}

void ListaV::mostrar(){
	string lista;
	cout <<'<';
	for (int i = 0; i < longitud; i++) {
		int a=elementos[i];
		cout<<a;
		if (i<longitud-1) {
			cout << ',';
		}
	}
	cout<<'>'<<endl;
}

direccion ListaV::localiza(int element){  //posicion de element
	for (int i = 0; i < longitud; i++) {
		if (elementos[i]==element) {
			return i;
		}
	}
	return -1;
}

void ListaV::eliminaDato(int element){
	for (int i = 0; i < longitud; i++) {
		if (elementos[i]==element) {
			suprime(i);
		}
	}
	return;//added
}

void ListaV::anula(){
	longitud=0;
}
