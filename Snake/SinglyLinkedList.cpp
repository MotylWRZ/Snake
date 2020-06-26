#include "SinglyLinkedList.h"



SinglyLinkedList::SinglyLinkedList()
{
}


SinglyLinkedList::~SinglyLinkedList()
{
}

void SinglyLinkedList::PushFront(Node* pHead, int pData)
{

}

void SinglyLinkedList::PushBack(Node* pHead, int pData)
{

}

int SinglyLinkedList::Length(Node* pHead)
{
	Node* currentNodePtr = pHead; // current node ptr
	int count = 0;
	while (currentNodePtr != nullptr)
	{
		count++;
		currentNodePtr = currentNodePtr->next; // point to the next node
	}
	return count;
}
