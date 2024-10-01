// we can implement stacks with either arrays or linked lists

//linked list implementation :
#include <iostream>
class StackNode {
public:
	int data;
	StackNode* next;
};

//create a new node
StackNode* newNode(int data) {
	StackNode* stackNode = new StackNode();
	stackNode->data = data;
	stackNode->next = nullptr;
	return stackNode;
}

class Stack {
private:
	StackNode* top;
public:
	Stack() {
		top = nullptr;
	}

	bool isEmpty() {//function to check if the stack is empty
		return !top;
	}


	//fucntion to push an element onto the stack
	void push(int data) {
		StackNode* stacknode = newNode(data);
		stacknode->next = top;
		top = stacknode;
		std::cout << data << " pushed to stack\n";

	}

	//function to pop an element from the stack
	 int pop() {
		if (isEmpty()) {
			std::cout << "Stack underflow\n";
			return 0;
		}


		StackNode* temp = top;
		top= top->next;
		int popped = temp->data;
		delete temp;
		return popped;
	}


	 int peek() {//function to return the top element;
		 if (isEmpty()) {
			 std::cout << "Stack is empty\n";
			 return 0;
		 }
		 return top->data;
	 }

};



// Main function to test the stack
int main() {
	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);

	std::cout << s.pop() << " popped from stack\n";
	std::cout << "Top element is " << s.peek() << std::endl;
	std::cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << std::endl;

	return 0;
}
