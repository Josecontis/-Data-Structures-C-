#include "linked_list.h"
#include <iostream>

using namespace std;

int main(){
	Linked_list<int> list1, list2;
	Linked_list<int>::position iter;
	int x;

	x = 1;
	list1.insert(x, list1.begin()); //inserimento in testa
	x = 5;
	list1.insert(x, list1.begin());
	x = 7;
	list1.insert(x, list1.begin());
	x = 4;
	list1.insert(x, list1.begin());

	/* stampa list1 */
	cout << "list1=" << list1;

	int n=7;
	iter=list1.search(n);
	cout << "la posizione dell'elemento in list1: " << list1.read(iter)<<endl;

	/* copia */
	list2 = list1;
	/* stampa list2 */
	cout << "Dopo la copia, list2="<< list2;
	cout << "list1=" << list1;
	cout << "list2=" << list2;
	/* confronto tra list1 e list2 */
	if (list1 == list2)
		cout << "list1 == list2" << endl;
	else
		cout << "list1 != list2" << endl;

	list1.sort();
	cout << "After sorting list1=" << list1;
	/* elimina il primo elemento da list2 */
	list2.erase(list2.begin());
	/* stampa list2 */
	cout << "Dopo aver eliminato il primo elemento, list2=" << list2 <<endl;
	/* confronto tra list1 e list2 */
	if (list1 == list2)
		cout << "list1 == list2" << endl;
	else
		cout << "list1 != list2" << endl;

	system("pause");
	return 0;
}

