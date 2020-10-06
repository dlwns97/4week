#ifndef __List__
#define __List__

#include <iostream>
#include <string>
using namespace std;

//LinkedList node
template <typename T>
class Node{
public:
	T  data;
	Node<T>* link;
	Node(T element)
	{
		data = element;
		link = NULL;
	}
};
// Linked List Class
template <typename T>
class LinkedList{
protected:
	Node<T>* first;
	int current_size;
public:
	LinkedList(){
		first = 0;
		current_size = 0;
	}
	int GetSize() { return current_size; }
	void Insert(T element)
	{		
		Node<T>* newnode = new Node<T>(element);
		newnode->link = first;
		first = newnode;
		current_size++;
	}
	virtual bool Delete(T& element)
	{
		if(first==0)
			return false;
		Node<T>* current = first;
		Node<T>* previous = NULL;
		while(1){
			if(current->link==0){
				if(previous)
					previous->link = current->link;
				else
					first=first->link;
				break;
			}
			previous = current;
			current = current->link;
		}
		element = current->data;
		delete current;
		current_size--;
	
		return true;	
	}
	void Print(){
		int i;
		Node<T>* ptr = first;
		for(i=1;i<=current_size;i++)
		{
			cout<<'['<<i<<'|'<<ptr->data<<']';
			if(i!=current_size)
				cout<<"->";
			ptr = ptr->link;
		}
		cout<<endl;
	}
};
#endif
