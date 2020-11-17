#include "pilapt.h"
#include <iostream>

using namespace std;

int main(){
	Pilapt<int> p1, p2;
	int x;

	/* inserimento pila */
	x = 1;
	p1.push(x);//inserimento in testa
	x = 2;
	p1.push(x);
	x = 3;
	p1.push(x);
	x = 4;
	p1.push(x);

	/* stampa p1*/
	cout << "pila1 = " << p1;

	p1.pop();

	cout << "pila1 senza l'ultimo elemento = " << p1;

	x = 4;
	p2.push(x);//inserimento in testa
	x = 3;
	p2.push(x);
	x = 2;
	p2.push(x);
	x = 1;
	p2.push(x);

	cout << "pila2 = " << p2;
	/* copia di p1 in p2 */
	p2 = p1;

	/*stampa p2*/
	cout << "pila2 dopo la copia = " << p2;

	system("pause");
	return 0;
}

