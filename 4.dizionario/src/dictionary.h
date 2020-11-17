#ifndef DICTIONARY_H_
#define DICTIONARY_H_

#include "linked_list.h"

template<class K, class E>
struct mypair {
	// data member
	K first; //key
	E second; //value

	// methods
	mypair(){}
	mypair(mypair<K,E>& the_pair){
		first = the_pair.first;
		second = the_pair.second;
	}
	mypair(const K& k, const E& e){
		first=k;
		second=e;
	}
};

template <class K, class E>
class dictionary
{

public:
	virtual ~dictionary() {}

	virtual void create() = 0;
	// create an empty dictionary
	virtual bool empty() const = 0;
	// return true iff the dictionary is empty
	virtual int size() const = 0;
	// return the number of pairs in the dictionary
	virtual mypair< K, E>* find(const K& k) const = 0;
	// return the pair with key k
	virtual void insert( mypair< K, E>& p) = 0;
	// insert the pair p into the dictionary
	virtual void erase(const K& k) = 0;
	// delete the pair with key k
	virtual void modify(const K& k, const E& e) = 0;
	// modify the value of the pair with key k to e
	virtual bool contains(const K& the_key) const = 0;
	//true if dictiionary contains the keys
	virtual Linked_list<K> keys() const= 0;
	//return list of keys
	virtual Linked_list<E> values() const= 0;
	//return list of values
};

#endif /* DICTIONARY_H_ */
