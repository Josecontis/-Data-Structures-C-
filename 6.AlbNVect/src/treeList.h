#ifndef TREELIST_H_
#define TREELIST_H_

#include "list_vector.h"
#include "tree.h"

#define MAXNODES 100

template<class I>
class TreeList : public Tree<I, int> {
public:
	typedef I item;
	typedef int node;

	TreeList(){create();}
	virtual void create ();
	virtual bool empty () const {return(numNodes == 0);}
	virtual void insRoot (node) ;
	virtual node root () const {return _root;}
	virtual node parent (node) const ;
	virtual bool leaf (node n) const {return(nodes[n].childs.empty());}
	virtual node firstChild (node n) const{
		if (!leaf(n))
			return(nodes[n].childs.read(nodes[n].childs.begin()));
	}
	virtual bool lastSibling (node) const ;
	virtual node nextSibling (node) const ;
	// DA IMPLEMENTARE
	//	virtual void insFirstSubTree (node, TreeList &) ;
	//	virtual void insSubTree (node, TreeList &) ;
	virtual void removeSubTree (node) ;
	void insFirst(node, item);
	void ins(node, item);
	virtual void writeNode (node n, item el) {nodes[n].e = el;}
	virtual item readNode (node n) const {return(nodes[n].e);}
	void print() const;

private:

	struct Record {
		item e;
		bool used;
		List_vector<int> childs;
	};

	typedef List_vector<int>::position position_list;
	///////////////////////////////////////////////////////////////
	Record nodes[MAXNODES];
	node _root;
	int numNodes;
};

template <class I>
void TreeList<I>::print() const{
	cout << "\n{";
	for (int i=0; i < MAXNODES;i++){
		if (nodes[i].used==true){
			cout << "\n  " << readNode(i) << ":  ";
			if (!leaf(i)){
				position_list child = nodes[i].childs.begin();
				while (!nodes[i].childs.end(child)){
					cout << readNode(nodes[i].childs.read(child)) << " ";
					child = nodes[i].childs.next(child);
				}
			}
		}
	}
	cout << "\n}\n";
}

template <class I>
void TreeList<I>::create(){
	numNodes = 0;
	for (int i=0; i< MAXNODES;i++){
		nodes[i].used = false;
		nodes[i].childs.create();
	}
}

template <class I>
void TreeList<I>::insRoot (node n){
	if (empty()){
		_root = 0;
		nodes[0].used = true;
		numNodes++;
	}
}

template <class I>
typename TreeList<I>::node TreeList<I>::parent (node n) const{
	position_list child;
	int p;
	for (int i=0; i < MAXNODES; i++){
		if (!nodes[i].childs.empty()){
			child = nodes[i].childs.begin();
			bool found = false;
			while (!nodes[i].childs.end(child) && !found){
				if (nodes[i].childs.read(child) == n){
					found = true;
					p = i;
				}
				child = nodes[i].childs.next(child);
			}
			if (found)
				return(i);
		}
	}
}

template <class I>
bool TreeList<I>::lastSibling (node n) const {
	position_list c;
	node p = parent(n);
	c = nodes[p].childs.begin();
	while (!nodes[p].childs.end(c))
		c = nodes[p].childs.next(c);
	return (n == nodes[p].childs.read(c));
}

template <class I>
typename TreeList<I>::node TreeList<I>::nextSibling (node n) const{
	if (!lastSibling(n)){
		position_list c;
		node p = parent(n);
		c = nodes[p].childs.begin();
		while (!nodes[p].childs.end(c)){
			if (nodes[p].childs.read(c) == n)
				return (nodes[p].childs.read(nodes[p].childs.next(c)));
			c = nodes[p].childs.next(c);
		}
	}
}

template <class I>
void TreeList<I>::insFirst(node n, item el){
	int k;
	for (k=0; k < MAXNODES && nodes[k].used == true; k++);
	if (k<MAXNODES){
		nodes[k].used = true;
		nodes[k].e = el;
		nodes[n].childs.insert(k, nodes[n].childs.begin());
	}
}


template <class I>
void TreeList<I>::ins(node n, item el){				// inserisce un node come fratello di n
	int k;
	for (k=0; k < MAXNODES && nodes[k].used == true; k++);
	if (k<MAXNODES){
		nodes[k].used = true;
		nodes[k].e = el;
		node p = parent(n);
		position_list child = nodes[p].childs.begin();
		bool found = false;
		while (!nodes[p].childs.end(child) && !found){
			if (nodes[p].childs.read(child) == n)
				found = true;
			child = nodes[p].childs.next(child);
		}
		nodes[p].childs.insert(k, child);
	}
}


template <class I>
void TreeList<I>::removeSubTree (node n){
	position_list c;
	if (!leaf(n)){
		while (!nodes[n].childs.empty()){
			removeSubTree(nodes[n].childs.read(nodes[n].childs.begin()));
		}
	}
	node p = parent(n);
	c = nodes[p].childs.begin();
	while(nodes[p].childs.read(c) != n)
		c = nodes[p].childs.next(c);
	nodes[p].childs.erase(c);
	nodes[n].used = false;
}

#endif /* TREELIST_H_ */
