#include <iostream>
#include "monster.h"
#ifndef LIST_H
#define LIST_H

using namespace std;
class List 
{

	private:
	// Declare a structure for the list 
		struct ListNode
		{
			Monster monster; // The value in this node
			struct ListNode *next; // To point to the next node 
		};
		
		ListNode *head; // List head pointer

	public:
	// Constructor
		List()
			{ 	head = nullptr; }

 	// Destructor
		~List();

	// Linked list operations
		void add(Monster);
		Monster remove(int);
		void print() const;
};


void List::print() const {
    
    ListNode *nodePtr; // To move through the list
    // Position nodePtr at the head of the list. 
    nodePtr = head;
	// While nodePtr points to a node, traverse the list.
	int i = 0;
    while (nodePtr){
        cout << "========= ("<< i << ") =========" << endl;    
        // Display the value in this node. 
        nodePtr->monster.print();
        // Move to the next node.
		nodePtr = nodePtr->next;
		i++; 
    }
}  

List::~List()
{
	ListNode *nodePtr; // To traverse the list
	ListNode *nextNode; // To point to the next node

	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr is not at the end of the list...
	while (nodePtr != nullptr)
	{
		// Save a pointer to the next node.
		nextNode = nodePtr->next;

		// Delete the current node.
		delete nodePtr;

		// Position nodePtr at the next node.
		nodePtr = nextNode;
	}
}

Monster List::remove(int index)
{
	ListNode *nodePtr; // To traverse the list 
	ListNode *previousNode = nullptr; // The previous node
	Monster monster;
    // If there are no nodes in the list
    //make newNode the first node
	if (!head){
		return monster;
	}else{ 
		if(index == 0)
		{
			nodePtr = head->next;
			monster = head->monster;
			delete head;
			head = nodePtr;

			return monster;
		}
		else
		{
			// Initialize nodePtr to head of list
			nodePtr = head;
			
			// Skip all nodes whose value member is
			 // not equal to num.
			
			for(int i = 0; i < index; i++)
			{
				previousNode = nodePtr;
				nodePtr = nodePtr->next;
			}
	
			// If nodePtr is not at the end of the list,
			// link the previous node to the node after
			// nodePtr, then delete nodePtr.
			
			if (nodePtr)
			{	
				previousNode->next = nodePtr->next;
				monster = nodePtr->monster;
				
				delete nodePtr;
				
				return monster;
			}
		}
	}
	
	return monster;
}

void List::add(Monster monster)
{
	ListNode *newNode; 		// To point to a new node 
	ListNode *nodePtr; 		// To move through the list

	// Allocate a new node and store num there. 
	newNode = new ListNode;
	newNode->monster = monster;
	newNode->next = nullptr;
    // If there are no nodes in the list 
    // make newNode the first node.

    if (!head)
		head = newNode;
	else 	// Otherwise, insert newNode at end. 
	{
		// Initialize nodePtr to head of list. 
		nodePtr = head;
	
		// Find the last node in the list. 
		while (nodePtr->next)
			nodePtr = nodePtr->next;
		// Insert newNode as the last node.
		nodePtr->next = newNode;
	}
}  
#endif