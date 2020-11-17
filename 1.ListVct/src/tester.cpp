#include "list_vector.h"
#include <iostream>

using namespace std;

int main(){
	List_vector<int> list1, list2;
	List_vector<int>::position iter;

	int x;
	x = 1;
	list1.insert(x, list1.begin());//inserimento in testa
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
	cout << "la posizione dell'elemento "<<n<<" in list1 e': " << iter <<endl;

	int p;
	cout << "inserisci la posizione:" <<endl;
	cin >> p;
	cout << "elemento in posizione " <<p<< " e': "<< list1.read(p) << endl;

	/* copia */
	list2 = list1;
	/* stampa list2 */
	cout << "After copy, list1="<< list1;
	cout << "After copy, list2="<< list2;

	/* confronto tra list1 e list2 */
	if (list1 == list2)
		cout << "list1 == list2" << endl;
	else
		cout << "list1 != list2" << endl;

	/* elimina il primo elemento da list2 */
	list2.erase(list2.begin());
	/* stampa list2 */
	cout << "After erasing the first element, list2=" << list2;
	/* confronto tra list1 e list2 */
	if (list1 != list2)
		cout << "list1 != list2" << endl;
	else
		cout << "list1 == list2" << endl;

	int p1=1;
	int p2=5;
	cout << "list1 have "<< list1.num_elements(p1,p2)<<" elements between position: "<<p1<<" and "<<p2<<endl;


	list1.sort();
	cout << "After order list1="<< list1 <<endl;

	cout << "Before delete list2="<< list2 <<endl;
	list2.clear();
	list1.clear();
	cout << "After delete list1="<< list1 <<endl;
	cout << "After delete list2="<< list2 <<endl;

	system("pause");
	return 0;
}

