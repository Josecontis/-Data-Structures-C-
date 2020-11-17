#ifndef QUEUEPT_H
#define QUEUEPT_H

#include <iostream>

using namespace std;

template <class T>
class Coda;

template <class T>
class Nodo{
public:
	friend class Coda<T>;
	Nodo(){
		next=nullptr;
	}
	Nodo(Nodo<T>&n){
		value=n.value;
		next=nullptr;
	}
	template<class K>
	friend ostream& operator<<(ostream& os, const Coda<K>& q);

private:
	Nodo *next;
	T value;
};

template <class T>
class Coda{
public:
	Coda();
	Coda(const Coda<T>& q);
	~Coda();
	bool codaVuota();
	int dimensione();
	void inCoda(T v);
	void fuoriCoda();
	T leggiCoda();

	Coda<T>& operator=(const Coda<T>&);

	template<class K>
	friend ostream& operator<<(ostream& os, const Coda<K>& q);

private:
	Nodo <T>* testa;
	Nodo <T>* coda;
	int s;
};

template <class T>
Coda<T>::Coda(){
	testa = nullptr;
	coda = nullptr;
	s = 0;
}

template <class T>
Coda<T>::Coda(const Coda<T>& q){

	testa=coda=nullptr;
	s=0;
	Nodo<T>*tmp=q.testa;

	while(tmp!=nullptr){

		push(tmp->value);
		tmp=tmp->next;
	}
}

template <class T>
Coda<T>::~Coda(){
	while(!codaVuota())
		fuoriCoda();
}

template <class T>
bool Coda<T>::codaVuota(){
	return (testa == nullptr);
}

template <class T>
int Coda<T>::dimensione(){
	return s;
}

template <class T>
void Coda<T>::inCoda(T v){
	Nodo<T> *tmp = new Nodo<T>;

	if (codaVuota()){

		testa = coda = tmp;

	}else{

		coda->next = tmp;

	}

	tmp->next = nullptr;
	tmp->value = v;
	coda = tmp;
	s++;

}

template <class T>
void Coda<T>::fuoriCoda(){

	Nodo<T> *tmp = testa;
	testa = testa->next;
	delete tmp;
	s--;

}

template <class T>
T Coda<T>::leggiCoda(){
	return testa->value;
}


template <class T>
Coda<T>& Coda<T>::operator=(const Coda<T>&q){

	if (this==&q) return *this;

	while(!codaVuota()){
		fuoriCoda();
	}
	Nodo<T>* tmp = q.testa;
	while(tmp!=nullptr){
		push(tmp->value);
		tmp=tmp->next;
	}
	return *this;
}

template<class K>
ostream& operator<<(ostream& os, const Coda<K>& q){

	Nodo<K>* tmp = q.testa;
	int i=0;
	while(tmp!=nullptr){
		os<<i<<" :["<<tmp->value<<"]"<<endl;
		tmp=tmp->next;
		i++;
	}

	return os;
}

#endif
