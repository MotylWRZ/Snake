#pragma once


struct Node
{
	Node* next;
	int data;

};


class SinglyLinkedList
{
public:
	SinglyLinkedList();
	virtual ~SinglyLinkedList();

	void PushFront(Node* pHead, int pData); // push a new node at the front of the list
	void PushBack(Node* pHead, int pData); // push a new node at the end of the list
	int Length(Node* pHead); // get the lenght of the linked list

private:
	Node* m_head; // Head (first node)
	Node* m_tail; // Tail (the last node)
};

