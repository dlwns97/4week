#include "LinkedList.h"

template <typename U>
class Stack : public LinkedList<U>
{
public:
	Stack(): LinkedList<U>(){}
	virtual bool Delete(U&element){
	if(LinkedList<U>::first==0)
		return false;
	Node<U>* rmptr;
	rmptr = LinkedList<U>::first;
	LinkedList<U>::first = LinkedList<U>::first->link;
	element = rmptr->data;
	delete rmptr;
	LinkedList<U>::current_size--;

	return true;
	}
};
