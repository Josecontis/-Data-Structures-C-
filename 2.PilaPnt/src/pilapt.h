#ifndef PILAPT_H
#define PILAPT_H
#include <iostream>

using namespace std;

template <class T>	// dichiarazione di pilapt template
class Pilapt;

template <class T>
class cell{
public:
	friend class Pilapt<T>;
	cell(){
		prec=nullptr;
	}
	template <class K>
	friend ostream& operator<<(ostream& os, const Pilapt<K> &p);
private:
	T value;
	cell *prec;
};

template <class T>
class Pilapt
{
public:
	typedef T tipoelem;

	Pilapt();
	Pilapt(const Pilapt<T>&);
	~Pilapt();
	void create();
	bool empty() const;
	tipoelem top() const;
	void pop();
	void push(tipoelem);
	Pilapt<T>& operator=(const Pilapt<T>&);

	template <class K>
	friend ostream& operator<<(ostream& os, const Pilapt<K> &p);
private:
	cell<T>* head;
};

template <class T>
Pilapt<T>::Pilapt()
{
	head = nullptr;
}

template <class T>
Pilapt<T>::Pilapt(const Pilapt<T>& p){ //copia p in head

	if(!p.empty()){
		head=new cell<T>();
		head->value=p.head->value;

		cell<T>* elsucc=p.head->prec;
		cell<T>* tmp=head;

		while(elsucc!=nullptr){
			tmp->prec=elsucc->value;
			elsucc=elsucc->prec;
			tmp=tmp->prec;
		}
	}
	else
		cout << "copia fallita pila vuota!" << endl;
}


template <class T>
Pilapt<T>::~Pilapt()
{
	while (!empty())
		pop();
};

template <class T>
void Pilapt<T>::create()
{
	head=nullptr;
}

template <class T>
bool Pilapt<T>::empty() const
{
	return head==nullptr;
}

template <class T>
T Pilapt<T>::top() const
{
	return head->value;
}

template <class T>
void Pilapt<T>::pop()
{
	if (!empty())
	{
		//cell<T> *tmp = head;
		cout << "ciao" <<endl;
		head = head->prec;
		//delete tmp;
	}
}

template <class T>
void Pilapt<T>::push(tipoelem el)
{
	cell<T> *tmp = new cell<T>();
	tmp->value = el;
	tmp->prec = head;
	head = tmp;
}

template <class K>
ostream& operator<<(ostream& os, const Pilapt<K> &p){
	os<<"TOP[";

	if(!p.empty()){
		cell<K>* tmp=p.head;

		while(tmp->prec!=nullptr) {
			os<<tmp->value<<"|";
			tmp=tmp->prec;
		}
		os<<tmp->value;
	}

	os<<"]BOT"<<endl;

	return os;
}

template <class T>
Pilapt<T>& Pilapt<T>::operator=(const Pilapt<T>&p){

	if(this==&p) return *this;

	if(!p.empty()){
		while (!empty())
			pop();

		head=new cell<T>();
		head->value=p.head->value;

		cell<T>* tocpy=p.head->prec;
		cell<T>* whcpy=head;

		while(tocpy!=nullptr){

			cell<T>*tmp=new cell<T>();
			tmp->value=tocpy->value;

			whcpy->prec=tmp;

			tocpy=tocpy->prec;
			whcpy=whcpy->prec;
		}
	}
	else
		cout << "copia fallita pila vuota!" << endl;
	return *this;
}

#endif // _PILAVT_H
