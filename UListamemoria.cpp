//---------------------------------------------------------------------------

#pragma hdrstop

#include "UListamemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ListaSM::ListaSM(){
	PtrElementos=NULO;
	longitud=0;
	mem = new CSMemoria();
}

int ListaSM::fin(){
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else {
		int x = PtrElementos;
		int PtrFin;
		while (x != NULO) {
			PtrFin = x;
			x = mem->obtener_dato(x, sigL); // x->sig;
		}
		return PtrFin;
	}
}

int ListaSM::primero(){
	if (!vacia())
		return PtrElementos;
	else
		cout << "ERROR: LISTA VACIA\n";
}

int ListaSM::siguiente(int dir){
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else {
		if (dir == fin())
			cout << "ERROR: DIRECCION ERRONEA\n";
		else
			return mem->obtener_dato(dir, sigL); // d->sig;
	}
}

int ListaSM::anterior(int dir){
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else {
		if (dir == primero())
			cout << "ERROR: DIRECCION ERRONEA\n";
		else {
			int x = PtrElementos;
			int ant = NULO;
			while (x != NULO) {
				if (x == dir)
					return ant;
				ant = x;
				x = mem->obtener_dato(x, sigL); // x->sig;
			}
			return NULO;
		}
	}
}

bool ListaSM::vacia(){
	return longitud==0;
}

int ListaSM::recupera(int dir){
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else
		return mem->obtener_dato(dir, elementL); // d->elemento;
}

int ListaSM::longuitud (){
	return longitud;
}

// new Nodo; mem->new_espacio("elemento,sig"); mem->new_espacio(datosNL);
void ListaSM::inserta(int dir,int element){
	int x= mem->new_espacio(datoL); // NodoL* x = new NodoL; //creacion de un nuevo nodo es distinto a null
	if (x!=NULO) {
		mem->poner_dato(x, elementL, element); // x->elemento = e;
		mem->poner_dato(x, sigL, NULO); // x->sig = NULL;
		if (vacia()) {
			PtrElementos=x;
			longitud=1;
		}
		else{
			longitud++;
			if (dir==primero()) {
				mem->poner_dato(x, sigL, dir); // x->sig = d;
				PtrElementos=x;//variable apunta al primer elemento
			}
			else{
				int ant=anterior(dir); //nodo anterior del ingresado
				mem->poner_dato(ant, sigL, x); // ant->sig = x;
				mem->poner_dato(x, sigL, dir); // x->sig = d;
			}
		}
	}
	else{
		cout << "Error: No exite espacio en la memoria\n";
	}

}
void ListaSM::inserta_primero(int element){
	int x=mem->new_espacio(datoL); // NodoL* x = new NodoL;
	if (x!=NULO) {
		mem->poner_dato(x, elementL, element); // x->elemento = e;
		mem->poner_dato(x, sigL, PtrElementos); // x->sig = ptr_elementos
		longitud++;
		PtrElementos=x;
	}
	else{
		cout << "Error: No existe espacio en la memoria\n";
	}
}
void ListaSM::inserta_ultimo(int element){
	int x = mem->new_espacio(datoL); // NodoL* x = new NodoL;
	if (x!=NULO) {
		mem->poner_dato(x, elementL, element); // x->elemento = e;
		mem->poner_dato(x, sigL, NULO); // x->sig = NULL;
		if (longitud==0) {//al principio
			PtrElementos=x;
		}
		else{
			mem->poner_dato(fin(), sigL, x); // fin()->sig = x;
		}
		longitud++;
	}
	else{
		cout << "Error: No exite espacio en la memoria\n";
	}
}

// delete(x)     ->  mem->delete_espacio(x);
void ListaSM::suprime(int dir){
	if (longitud==0) {
		cout << "Error: La lista esta vacia\n";
	}
	else{
		if (dir==PtrElementos) { //primer nodo
			int x=PtrElementos;
			PtrElementos=mem->obtener_dato(PtrElementos, sigL);
			// ptr_elementos->sig;
			mem->delete_espacio(x); // delete(x);
		}
		else{
			int ant=anterior(dir);
			mem->poner_dato(ant, sigL, mem->obtener_dato(dir, sigL));
			// ant->sig = d->sig;
			mem->delete_espacio(dir); // delete(d);
		}
	}
	longitud--;
}

void ListaSM::modifica(int dir,int element){	if (vacia()){		cout << "Error: La lista esta vacia\n";
	}	else{		mem->poner_dato(dir, elementL, element); // d->elemento = e;//modificar elemento que tiene por otro
	}}string ListaSM::mostrar(){
	mem->mostrar_memoria();
	string s = "[";
	int aux = PtrElementos;
	while (aux != NULO){
		int el = mem->obtener_dato(aux, elementL); // aux->elemento
		s += to_string(el);
		aux = mem->obtener_dato(aux, sigL); // aux->sig;
		if (aux != NULO)
			s += ",";
	}
	return s + "]";
}

int ListaSM::localiza(int e){
	int aux = PtrElementos;
	while (aux != NULO){
		if (mem->obtener_dato(aux, elementL) == e)
			return aux;
		aux = mem->obtener_dato(aux, sigL); // aux->sig;
	}
	return NULO;
}

void ListaSM::elimina_dato(int e){
	int aux = PtrElementos;
	while (aux != NULO){
		if (mem->obtener_dato(aux, elementL) == e){
			int sup = aux;
			aux = mem->obtener_dato(aux, sigL); // aux->sig;
			suprime(sup);
		}
		else
			aux = mem->obtener_dato(aux, sigL); // aux->sig;
	}
}

void ListaSM::anula(){
	while (!vacia())
		suprime(primero());
}
