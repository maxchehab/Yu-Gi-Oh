// Specification file for the DynIntStack class
#include "monster.h"

#ifndef STACK_H
#define STACK_H

class Stack {
	private:
	    // Structure for stack nodes 
		struct StackNode{
		    Monster monster; // Value in the node
		    StackNode *next; // Pointer to the next node 
		};
		StackNode *top;
	public:
	    // Constructor
		Stack(){ 
            top = nullptr; 
        }
	    // Destructor 
		~Stack();
	    // Stack operations 
		void push(Monster); 
		void pop(Monster &); 
		bool isEmpty();
};

/**************************************************
 * Destructor 
 * This function deletes every node in the list. 
 **************************************************/

Stack::~Stack(){
	StackNode *nodePtr = nullptr, *nextNode = nullptr;
	// Position nodePtr at the top of the stack.
 	nodePtr = top;

	// Traverse the list deleting each node.
	while (nodePtr != nullptr){
	    nextNode = nodePtr->next;
	 	delete nodePtr;
	 	nodePtr = nextNode;
	}
}

/**************************************************
 * Member function push pushes the argument onto 
 * the stack. 
 **************************************************/
void Stack::push(Monster monster){
	StackNode *newNode = nullptr; // Pointer to a new node

	// Allocate a new node and store monster there.
	newNode = new StackNode;
	newNode->monster = monster;
	 // If there are no nodes in the list
	 // make newNode the first node.
	if (isEmpty()){
		top = newNode;
		newNode->next = nullptr;
	}else{ // Otherwise, insert NewNode before top.
		newNode->next = top;
		top = newNode;
	}
}

/*****************************************************
 * Member function pop pops the value at the top 
 * of the stack off, and copies it into the variable 
 * passed as an argument. *
 *****************************************************/

void Stack::pop(Monster &monster){
	StackNode *temp = nullptr; // Temporary pointer
	// First make sure the stack isn't empty. 
	if (!isEmpty()){
		monster = top->monster;
		temp = top->next; delete top;
		top = temp; 
	}
}

/***************************************************** 
 * Member function isEmpty returns true if the stack 
 * is empty, or false otherwise. 
 *****************************************************/
bool Stack::isEmpty() {
	return !top; 
}

#endif
