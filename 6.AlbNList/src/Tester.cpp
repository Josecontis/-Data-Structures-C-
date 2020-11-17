#include <iostream>
using namespace std;
#include "tree.h"

int main() {

	Tree<int> T;
	TNode<int>*p1, *p2;

	p1 = T.insertRoot(1);
	T.addChild(p1, 2);
	T.addChild(p1, 6);

	p2 = T.addChild(p1, 4);
	T.addChild(p2, 3);
	T.addChild(p2, 5);
	T.addChild(p2, 7);

	cout<<T<<endl;

	//T.clear();
	T.BST();

	cout<<T.depth()<<endl;
	cout<<T.parent(p2)<<endl;
	cout<<T.size()<<endl;
	cout<<T.width()<<endl;

	system("pause");
	return 0;
}
