#pragma once


template<class T>
struct Node
{
	Node* next;
	T data;

};

template<class T>
class SinglyLinkedList
{
public:
	SinglyLinkedList<T>(T pFirstNodeData);
	virtual ~SinglyLinkedList<T>();

	void PushFront(T pData); // push a new node at the front of the list
	void PushBack(T pData); // push a new node at the end of the list
	int Length(); // get the lenght of the linked list

private:
	Node<T>* m_head; // Head (first node)
	Node<T>* m_end; // End (the last node)

};



