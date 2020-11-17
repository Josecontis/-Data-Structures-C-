#ifndef LINEAR_LIST_H
#define LINEAR_LIST_H
/////////////////////////////////////INTERFACCIA///////////////////////////////////
#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

template< class T, class P >
class Linear_list{
public:
	typedef T value_type;
	typedef P position;
	// operatori
	virtual void create() = 0;
	virtual bool empty() const = 0;
	virtual value_type read(position) const = 0;
	virtual void write(const value_type &, position) = 0;
	virtual position begin() const = 0;
	virtual bool end(position) const = 0;
	virtual	position next(position) const = 0;
	virtual position previous(position) const = 0;
	virtual void insert(const value_type &, position) = 0;
	virtual void erase(position pos) = 0;
	virtual void pushBack(T v) = 0;
	virtual void pushFront(T v) = 0;
	virtual	void popBack() = 0;
	virtual void popFront() = 0;
	//virtual 	position search(const value_type&)const;
	virtual void sort();
	virtual	void removeDuplicate();
	virtual void invert();

	/* Altre funzioni di servizio implementabili */
	/*
		virtual	 	int size() const; 										// returns the size of the list
		virtual 	void push_front(const value_type &); 					// insert a new element at the beginning
		virtual 	void push_back(const value_type &); 					// insert a new element at the end
		virtual 	void pop_front(); 										// removes the first element
		virtual 	void pop_back(); 										// removes the last element
		virtual 	void clear();											// erases all the elements
	 */
};

/* sovraccarica <<. Attenzione se il tipo restituito da read non è primitivo, allora
 *  anche per questo tipo bisogna sovraccaricare l'operatore <<
 */

template< class T, class P >
ostream& operator<<(ostream& os, const Linear_list<T,P> &l){
	typename Linear_list<T,P>::position p;
	p = l.begin();
	os << "[";
	while (!l.end(p)){
		if (p != l.begin())
			os << ", " << l.read(p);
		else
			os << l.read(p);
		p = l.next(p);
	}
	os << "]" << endl;
	return os;
}

template<class T, class P>
void Linear_list<T, P>::sort()
{
	P p = begin();

	while(!end(p))
	{
		P q = p;

		P pmin = p;
		T min = read(p);

		while(!end(q))
		{
			if(read(q) < min)
			{
				min = read(q);
				pmin = q;
			}

			q = next(q);
		}

		T tmp = read(p);
		write(min, p);
		write(tmp, pmin);

		p = next(p);
	}
}

template<class T, class P>
void Linear_list<T, P>::removeDuplicate(){
	P p = begin();
	while(!end(p)){
		P q=next(p);
		while(!end(q)){
			if(read(p)==read(q)){
				erase(p);
			}
			q=next(q);
		}
		p=next(p);
	}
}

template<class T, class P>
void Linear_list<T, P>::invert()
{
	if(empty())
		return;

	T tmp;

	P p1 = begin();
	P p2 = begin();

	while(!end(next(p2)))
		p2 = next(p2);

	while(p1 != p2 && previous(p1) != p2)
	{
		tmp = read(p1);
		write(read(p2), p1);
		write(tmp, p2);

		p1 = next(p1);
		p2 = previous(p2);
	}
}

#endif // LINEAR_LIST_H

