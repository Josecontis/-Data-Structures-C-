#include <iostream>
using namespace std;
#include "linked_ord_list.h"

int main() {

	Linked_ord_list<int> l;
	l.write(2);
	l.write(3);
	l.write(1);
	cout<<l<<endl;

	system("pause");
	return 0;
}
