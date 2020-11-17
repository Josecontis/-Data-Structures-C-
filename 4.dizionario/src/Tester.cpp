#include <iostream>
#include "hash.h"
using namespace std;

int main() {

	hash_table<int, int> h(2);
	h.insert(1, 2);
	h.insert(2, 3);

	h.print();

	system("pause");
	return 0;
}
