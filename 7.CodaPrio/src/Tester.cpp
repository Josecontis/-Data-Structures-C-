#include <iostream>
#include "pqueue.h"

using namespace std;

int main(int argc, char *argv[])
{
	PQueue<int> queue;
	queue.push(2);
	queue.push(5);
	queue.push(3);
	queue.push(0);
	queue.push(4);
	queue.push(1);
	queue.push(6);

	cout<<"coda: "<<queue<<endl;
	int k=4;
	cout<<"la coda contiene l'elemento "<<k<<"? "<<queue.contains(k)<<endl;

	queue.pop();
	queue.pop();

	cout<<"il valore minimo e': "<<queue.min()<<endl;

	queue.clear();
	cout<<"coda vuota: "<<queue<<endl;

	system("pause");
	return 0;
}

