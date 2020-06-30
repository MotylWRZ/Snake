#include "SinglyLinkedList.h"
#include "SnakeBodyElem.h"
#include "SFML/Graphics.hpp"


template<typename T>
SinglyLinkedList<T>::SinglyLinkedList()
	:m_head(nullptr)
	,m_end(nullptr)
{

}

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList(T pFirstNodeData)
{
	Node<T>* newNodePtr = new Node<T>; // Create a new node (first node in the list)
	newNodePtr->data = pFirstNodeData;
	newNodePtr->next = nullptr; //There is only one element so far so set the pointer to the next node as a nullptr
	m_head = newNodePtr; //Set the first node as the list head		
	m_end = newNodePtr; //Set also the first node as the list tail (there is only one element so it is a tail and the head)
}

template<class T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
}

template<class T>
void SinglyLinkedList<T>::PushFront(T pData)
{
	Node<T>* newNodePtr = new Node<T>; // Create a new node
	newNodePtr->data = pData; //Assign data to the node
	newNodePtr->next = m_head; // set the next node of a ned node as a head node. Now it is NewNode->Head
	m_head = newNodePtr; // Set a new node as a head as it is a first element now
	if (this->Length() < 2)
	{
		m_end = m_head;
	}
}

template<class T>
void SinglyLinkedList<T>::PushBack(T pData)
{
	Node<T>* newNodePtr = new Node<T>; // Create a new node
	newNodePtr->data = pData; //Assign data to the node
	m_end->next = newNodePtr; // Set a next node as a new node
	m_end = newNodePtr; // Set a new node as a tail as it is the last element now
	m_end->next = nullptr; // Set the next node ptr as a nullptr as it is not pointing to anything->next = nullptr; // Set the next node ptr as a nullptr as it is not pointing to anything

	if (this->Length() < 2)
	{
		m_head = m_end;
	}
}

template<class T>
int SinglyLinkedList<T>::Length()
{
	Node<T>* currentNodePtr = m_head; // current node ptr
	int count = 0;
	while (currentNodePtr != nullptr)
	{
		count++;
		currentNodePtr = currentNodePtr->next; // point to the next node
	}
	return count;
}

template<class T>
void SinglyLinkedList<T>::PopBack()
{
	Node<T>* tCurrentNodePtr = m_head;
	while (tCurrentNodePtr->next != m_end)
	{
		tCurrentNodePtr = tCurrentNodePtr->next; // Traverse the linked list in order top find the last elem
	}
	if (tCurrentNodePtr->next == m_end) 
	{
		delete m_end; //Delete the last element by using a delete keyword
		m_end = tCurrentNodePtr; // point to the new last node (the node before the previous last node)
		m_end->next = nullptr; // Set the pointer to the next node as a nullptr
	}
	
}

template<class T>
void SinglyLinkedList<T>::PopFront()
{
	Node<T>* tNewHeadPtr = m_head->next; // Temorary pointer pointing at the next node from the head
	delete m_head; // Deallocate the memory used by the head node
	m_head = tNewHeadPtr; // Point to the new head node
}

//Explicit Instantiation
//Only types used here in <> brackets will be available to used in this linked list
template class SinglyLinkedList<int>;
template class SinglyLinkedList<float>;
template class SinglyLinkedList<char>;
template class SinglyLinkedList <sf::RectangleShape>;
template class SinglyLinkedList<SnakeBodyElem>; 
// Here only int, float, char, sf::RectangleShape and SnakeBodyElem can be used. More types can be added here (including custom Classes)