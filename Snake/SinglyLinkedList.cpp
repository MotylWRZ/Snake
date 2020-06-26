#include "SinglyLinkedList.h"



SinglyLinkedList::SinglyLinkedList(Node* pFirstNode)
	: m_head(pFirstNode)
	, m_tail(pFirstNode)
{
	m_head->next = nullptr;
	m_tail->next = nullptr;
}


SinglyLinkedList::~SinglyLinkedList()
{
}

void SinglyLinkedList::PushFront(int pData)
{
	Node* newNodePtr = new Node; // Create a new node
	newNodePtr->data = pData; //Assign data to the node
	newNodePtr->next = m_head; // set the next node of a ned node as a head node. Now it is NewNode->Head
	m_head = newNodePtr; // Set a new node as a head as it is a first element now
}

void SinglyLinkedList::PushBack(int pData)
{
	Node* newNodePtr = new Node; // Create a new node
	newNodePtr->data = pData; //Assign data to the node
	m_tail->next = newNodePtr; // Set a next node as a new node
	m_tail = newNodePtr; // Set a new node as a tail as it is the last element now
	m_tail->next = nullptr; // Set the next node ptr as a nullptr as it is not pointing to anything
}

int SinglyLinkedList::Length()
{
	Node* currentNodePtr = m_head; // current node ptr
	int count = 0;
	while (currentNodePtr != nullptr)
	{
		count++;
		currentNodePtr = currentNodePtr->next; // point to the next node
	}
	return count;
}
