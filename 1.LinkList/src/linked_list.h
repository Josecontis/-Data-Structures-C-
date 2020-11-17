#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include "linear_list.h"

template<class T>
class Linked_list;

template< class T >								// NODO
class List_node{
	friend class Linked_list<T>;
private:
	T _value;
	List_node<T> * _pPrev;
	List_node<T> * _pNext;
};

template< class T >
class Linked_list :
		public Linear_list<T, List_node<T>*>
{
public:
	typedef typename Linear_list<T, List_node<T>*>::value_type value_type;
	typedef typename Linear_list<T, List_node<T>*>::position position;

	Linked_list();								// costruttori
	Linked_list(int);
	Linked_list(const Linked_list<T>& );		// costruttore per copia
	~Linked_list();

	void create();
	bool empty() const;
	value_type read(position p ) const;
	void write(const value_type &a, position p );
	position begin() const;
	position last() const;
	bool end(position p) const;
	position next(position p) const;
	position previous(position p) const;
	void insert(const value_type &, position);
	void erase(position);
	int size() const;
	void clear();
	List_node<T> *find(T v) const;
	void pushBack(T v);
	void pushFront(T v);
	void popBack();
	void popFront();
	void print() const;
	// sovraccarico di operatori
	Linked_list<T>& operator=(const Linked_list<T>&);
	bool operator==(const Linked_list<T> &) const;

private:
	List_node<T> * _pHead;
	List_node<T> * _pTail;
	int _length;
};

template< class T >
Linked_list< T >::Linked_list() {
	_pHead = new List_node<T>;
	_pHead->_pNext = _pHead;
	_pHead->_pPrev = _pHead;
	_length = 0;
}

template< class T >
Linked_list< T >::Linked_list(const Linked_list<T>& L) {		//costruttore di copia
	_length = L.size();
	_pHead = new List_node<T>;
	_pHead->_pNext = _pHead;
	_pHead->_pPrev = _pHead;

	if (!L.empty()){
		position p = L.last();
		for (int i=0; i <= L._length; i++){
			insert(L.read(p), begin());
			p = L.previous(p);
		}
	}
}

template< class T >
Linked_list< T >::~Linked_list(){
	while(!empty())		erase(begin());
	delete _pHead;
}

template< class T >
void Linked_list< T >::create(){
	if (empty())
		_length = 0;
}

template< class T >
bool Linked_list< T >::empty() const{
	return(_pHead == _pHead->_pNext);
}

template< class T >
typename Linked_list< T >::value_type Linked_list< T >::read(position p ) const{
	if (!end(p))
		return(p->_value);
}

template< class T >
void Linked_list< T >::write(const value_type &a, position p ){
	if (!end(p))
		p->_value = a;
}

template< class T >
typename Linked_list< T >::position Linked_list< T >::begin() const{
	return (_pHead->_pNext);
}

template< class T >
typename Linked_list< T >::position Linked_list< T >::last() const{
	return (_pHead->_pPrev);
}

template< class T >
bool Linked_list< T >::end(position p) const {
	return(p == _pHead);
}

template< class T >
typename Linked_list< T >::position Linked_list< T >::next(position p) const{
	return(p->_pNext);
}

template< class T >
typename Linked_list< T >::position Linked_list< T >::previous(position p) const{
	if (p != _pHead)
		return(p->_pPrev);
}

template< class T >
void Linked_list< T >::insert(const value_type &a, position p){
	position t = new List_node<T>;
	t->_value = a;

	t->_pNext = p;			//algoritmo di inserimento
	t->_pPrev = p->_pPrev;
	p->_pPrev->_pNext = t;
	p->_pPrev = t;

	_length++;
}

template< class T >
void Linked_list< T >::erase(position p){
	if (!empty() && !end(p)){
		p->_pPrev->_pNext = p->_pNext;
		p->_pNext->_pPrev = p->_pPrev;
		delete p;
	}
}

template< class T >
int Linked_list< T >::size() const {
	return _length;
}


template <class T>
void Linked_list<T>::clear(){

	while(!end(begin())){

		erase(begin());

	}
	delete _pHead;
	_length=0;

}

template<class T>
List_node<T> *Linked_list<T>::find(T v) const{
	List_node<T> *tmp = begin();

	while(!end(tmp)){
		if(tmp->_value == v)
			return tmp;
		tmp = tmp->_pNext;
	}
	return nullptr;
}

template<typename T>
void Linked_list<T>::pushBack(T v)
{
	List_node<T> *node = new List_node<T>;
	node->_value = v;
	node->_pNext = nullptr;

	if(empty())
	{
		_pHead = node;
		node->_pPrev = nullptr;
	}
	else
	{
		_pTail->_pNext = node;
		node->_pPrev= _pTail;
	}

	_pTail = node;

	_length++;
}

template<typename T>
void Linked_list<T>::pushFront(T v)
{
	List_node<T> *node = new List_node<T>;
	node->_value = v;
	node->_pPrev = nullptr;

	if(empty())
	{
		_pTail = node;
		node->_pNext= nullptr;
	}
	else
	{
		_pTail->_pPrev = node;
		node->_pNext = _pHead;
	}

	_pHead = node;

	_length++;
}

template<typename T>
void Linked_list<T>::popBack()
{
	if(empty())
		throw "list is empty";

	if(_pHead == _pTail)
	{
		delete _pHead;
		_pHead = nullptr;
	}
	else
	{
		List_node<T> *tmp = _pTail;
		_pTail->_pPrev->_pNext = nullptr;
		_pTail = _pTail->_pPrev;
		delete tmp;
	}

	_length--;
}

template<typename T>
void Linked_list<T>::popFront()
{
	if(empty())
		throw "list is empty";

	List_node<T> *tmp = _pHead;
	_pHead= _pHead->_pNext;
	delete tmp;

	_length--;
}

template <class T>
void Linked_list<T>::print() const{
	List_node<T>* tmp=begin();
	while(!end(tmp)){
		cout << "[" << read(tmp) << "] ";
		tmp=next(tmp);
	}
	cout << endl;
}

template<class T>
Linked_list<T>& Linked_list<T>::operator=(const Linked_list<T>& l){

	if (this != &l){
		_length = l.size();

		_pHead = new List_node<T>;
		_pHead->_pNext = _pHead;
		_pHead->_pPrev = _pHead;

		if (!l.empty()){
			position p = l.last();
			for (int i=0; i < l.size(); i++){
				insert(l.read(p), begin());
				p = l.previous(p);
			}
		}
	}
	return *this;
}


template<class T>
bool Linked_list<T>::operator==(const Linked_list<T> &L) const{

	position p, pL;
	p = begin();
	pL = L.begin();
	while (!end(p)){
		if (p->_value != pL->_value)
			return false;
		p = p->_pNext;
		pL = pL->_pNext;
	}
	return true;
}

#endif // _LINKED_LIST_H

