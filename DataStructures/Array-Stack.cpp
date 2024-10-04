#include <iostream>
#define MAX 1000

class Stack {
private:
	int top;
	int arr[MAX];
public:
	Stack() {//constructor to initialize stack;
		top = -1;
	}


	//function to push and element onto the stack
	bool push(int x) {
		if (top >= (MAX - 1)) {
			std::cout << "Stack overflow\n";
			return false;
		}
		else {
			arr[++top] = x;
			std::cout << " pushed into stack\n";
			return true;
		}

	}

	//function to pop an element from the stack
	int pop() {
		if (top < 0) {
			std::cout << "Stack underflow \n";
			return 0;
		}
		else {
			int x = arr[top--];
			return x;
		}
	}

	int peek() {
		if (top < 0) {
			std::cout<<"Stack Empty\n";
			return 0;
		}
		else {
			return arr[top];
		}
	}

	bool isEmpty() {
		return (top < 0);
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
