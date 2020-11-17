#include "pilavt.h"
#include <iostream>

using namespace std;

int main(){
	Pila<int> p1, p2;
	int x;

	/* inserimento pila */
	x = 1;
	p1.inPila(x);//inserimento in testa
	x = 2;
	p1.inPila(x);
	x = 3;
	p1.inPila(x);
	x = 4;
	p1.inPila(x);

	/* stampa p1 */
	cout << "pila1 = " << p1;

	/* elimina top p1*/
	p1.fuoriPila();

	cout << "pila1 senza l'ultimo elemento = " << p1;

	x = 3;
	p2.inPila(x);//inserimento in testa
	x = 2;
	p2.inPila(x);
	x = 2;
	p2.inPila(x);
	x = 1;
	p2.inPila(x);

	cout << "pila2 = " << p2;
	/* copia di p1 in p2 */
	//p2 = p1;
	//cout << "pila2 dopo la copia = " << p2;

	/*rimuove gli elementi duplicati nella pila p2*/
	p2.rimuoviDuplicati();
	cout << "pila2 dopo rimuovi dulicati se uguali al top = " << p2;

	system("pause");
	return 0;
}

