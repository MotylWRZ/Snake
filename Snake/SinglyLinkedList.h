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
	SinglyLinkedList<T>(); //Default constructor. The created list will be empty
	SinglyLinkedList<T>(T pFirstNodeData); // Use this constructor to immidiately create a head node
	virtual ~SinglyLinkedList<T>();

	void PushFront(T pData); // push a new node at the front of the list
	void PushBack(T pData); // push a new node at the end of the list
	int Length(); // get the lenght of the linked list
	void PopBack(); // Delete the last element of the list
	void PopFront(); // Delete first element of the list

	//Accesors/Mutators
	Node<T>* GetHeadPtr() { return m_head; }; // Return a pointer to the head node
	Node<T>* GetEndPtr() { return m_end; }; //Return a pointer to the end node

private:
	Node<T>* m_head; // Head (first node)
	Node<T>* m_end; // End (the last node)
	


};



