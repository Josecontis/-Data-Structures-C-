//============================================================================
// Name        : AlberoBinarioVect.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "bintree_vect.h"
#include "bintree.h"
using namespace std;

int main() {
	/*ogni qualvolta si vuole aggiungere un nodo, bisogna ritornare alla radice (n=Tree.root())
	  e scendere lungo l'albero selezionado il nodo sinistro o destro con Tree.sx(n) o Tree.dx(n). */

	bintree_vect<int> Tree;
	bintree_vect<int>::Nodo n;
	Tree.ins_root(n);

	//primo sottoalbero (10,5,13)
	n=Tree.root();
	Tree.write(n, 10);
	Tree.ins_sx(n, 5);
	Tree.ins_dx(n, 13);

	//secondo sottoalbero a sinistra(5,3,7)
	n=Tree.root();
	n=Tree.sx(n);
	Tree.ins_sx(n, 3);
	Tree.ins_dx(n, 7);

	//terzo sottoalbero a destra(12, nil, 20)
	n=Tree.root();
	n=Tree.dx(n);
	Tree.ins_dx(n, 20);

	n=Tree.root();
	n=Tree.sx(n);
	n=Tree.sx(n);
	Tree.ins_sx(n, 99);


	/*bintree_vect<int> A;
	bintree_vect<int> B;

	bintree_vect<int>::Nodo u;
	bintree_vect<int>::Nodo v;

	A.ins_root(u);
	B.ins_root(v);

	u = A.root();
	v = B.root();

	A.write(u, 5);
	B.write(v, 8);

	A.ins_sx(u, 7);
	//B.ins_sx(v, 9);

	//A.ins_dx(v, 11);
	//B.ins_dx(v, 13);

	cout<<A<<endl;
	cout<<B<<endl;


	//A.mutation(A, B, u, v);

	cout<<"albero A: "<<A<<endl;
	cout<<"albero B: "<<B<<endl;

	//cout<<Tree<<endl;

	A.mutation(A, B, u, v);

	cout<<"albero A: "<<A<<endl;
	cout<<"albero B: "<<B<<endl;

	cout<<A.depth(u)<<endl;
	cout<<A.width(u)<<endl;
	 */
	Tree.printSubTree(Tree.root());
	cout<<"\n";
	cout<<Tree.getLivello(Tree.sx(Tree.sx(Tree.root())))<<endl;

	system("pause");
	return 0;
}

