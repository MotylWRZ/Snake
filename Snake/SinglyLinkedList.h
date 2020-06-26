#pragma once


struct Node
{
	Node* next;
	int data;

};


class SinglyLinkedList
{
public:
	SinglyLinkedList(Node* pFirstNode);
	virtual ~SinglyLinkedList();

	void PushFront(int pData); // push a new node at the front of the list
	void PushBack(int pData); // push a new node at the end of the list
	int Length(); // get the lenght of the linked list

private:
	Node* m_head; // Head (first node)
	Node* m_tail; // Tail (the last node)
};

