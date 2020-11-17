#include <iostream>
using namespace std;
#include "bintree_list.h"
#include "bintree.h"
#include "queuept.h"
#include <ctime>

void inserimento(bintree_list<int> &);


int main() {

	bintree_list<int> prova;
	int n=0;

	inserimento(prova);
	cout<<"Albero: "<<prova;

	cout<<"il livello del nodo "<<prova.read(prova.sx(prova.sx(prova.root())))<<" e': "<<prova.getLivello(prova.sx(prova.sx(prova.root())))<<endl;

	system("pause");
	return 0;
}

void inserimento(bintree_list<int> &A){
	srand(time(NULL));
	int numNodi = 4, conta = 0;

	Coda<bintree_list<int>::Nodo> tmp;
	A.ins_root(rand()%10);

	bintree_list<int>::Nodo p = A.root();
	tmp.inCoda(p);

	while(!tmp.codaVuota() && conta< numNodi-1){
		p=tmp.leggiCoda();
		tmp.fuoriCoda();

		A.ins_sx(p, rand()%10);
		conta++;

		A.ins_dx(p, rand()%10);
		conta++;

		if(!A.sx_empty(p))
			tmp.inCoda(A.sx(p));
		if(!A.dx_empty(p))
			tmp.inCoda(A.dx(p));
	}




}
