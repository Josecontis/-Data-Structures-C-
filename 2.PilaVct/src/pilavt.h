#ifndef PILAVT_H
#define PILAVT_H

#include <iostream>

using namespace std;

template <class Elemento>
class Pila{
public:
	typedef Elemento tipoelem;

	Pila();
	Pila(int N);
	~Pila();
	void creaPila();
	bool pilaVuota() const;
	tipoelem leggiPila() const;
	void fuoriPila();
	void rimuoviDuplicati();
	void inPila(tipoelem el);
	template <class k>
	friend ostream& operator<<(ostream& os, const Pila<k> &p);
	Pila<Elemento>& operator=(const Pila<Elemento> &p);

private:
	tipoelem *elementi;
	int MAXLUNGH;
	int testa;
};

template <class Elemento>
Pila<Elemento>::Pila(){
	elementi = new tipoelem[100];
	MAXLUNGH = 100;
	creaPila();
}

template <class Elemento>
Pila<Elemento>::Pila(int N){
	elementi = new tipoelem[N];
	MAXLUNGH = N;
	creaPila();
}

template <class Elemento>
Pila<Elemento>::~Pila(){
	delete[] elementi;
}

template <class Elemento>
void Pila<Elemento>::creaPila(){
	testa=0;
}

template <class Elemento>
bool Pila<Elemento>::pilaVuota() const{
	return testa==0;
}

template <class Elemento>
typename Pila<Elemento>::tipoelem Pila<Elemento>::leggiPila() const{
	return elementi[testa-1];
}

template <class Elemento>
void Pila<Elemento>::fuoriPila(){
	if (!pilaVuota())
		testa-=1;
	else
		cout<<"Pila vuota"<<endl;
}

template <class Elemento>
void Pila<Elemento>::rimuoviDuplicati()
{
	for(int i=2; i<testa; i++)
	{
		while(elementi[testa-1]==elementi[testa-i])
		{
			fuoriPila();
		}
	}
}

template <class Elemento>
void Pila<Elemento>::inPila(tipoelem el){
	if (testa==MAXLUNGH)
		cout<<"raggiunta capacità  massima della pila"<<endl;
	else{
		elementi[testa]=el;
		testa++;
	}
}

template <class k>
ostream& operator<<(ostream& os, const Pila<k> &p){
	os << "TOP[";
	int i=p.testa-1;
	if (!p.pilaVuota()){
		while (0<i)
		{
			os << p.elementi[i] << "|";
			i--;
		}
		os << p.elementi[i];
	}
	os << "]BOT" << endl;
	return os;
}

template <class Elemento>
Pila<Elemento>& Pila<Elemento>::operator=(const Pila<Elemento> &p){
	if (this == &p)
		return *this;
	if (MAXLUNGH!=p.MAXLUNGH)
	{
		delete[]elementi;
		MAXLUNGH=p.MAXLUNGH;
	}
	elementi = new tipoelem[MAXLUNGH];
	testa=p.testa;
	for (int i=0; i<testa; i++){
		elementi[i] = p.elementi[i];
	}
	return *this;
}

#endif // _PILAVT_H
