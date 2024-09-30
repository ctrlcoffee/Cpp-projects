#include <iostream>
using namespace std;



struct Node {
	int data;
	Node* next;
};


class LinkedList {
private:
	Node* head;// which points to the first node in the list.

public://constructor to initialize an empty list
	LinkedList() {
		head = nullptr;
	}


	void insertAtBeginning(int value) {
		Node* newNode = new Node();//creating a node
		newNode->data = value; // set data
		newNode -> next = head;//point the new node to the current head
		head = newNode; //update the head to the new node
	}

	void insertAtEnd(int value) {
		Node* newNode = new Node();
		newNode->data = value;
		newNode->next = nullptr;

		if (head == nullptr) { //if list is empty
			head = newNode;
		}
		else {
			Node* temp = head;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			temp->next = newNode;
		}

	}
		//function to delete a node by value
		void deleteNode(int value) {
			if (head == nullptr) {//if list is empty
				cout << "list is empty." << endl;
				return;
			}
			//if the node to delete is the head
			if (head->data == value) {
				Node* temp = head;
				head = head->next;
				delete temp;
				return;
			}

			//if the node to delete is in middle or end

			Node* temp = head;
			while (temp->next != nullptr && temp->next->data != value) {
				temp = temp->next;
			}


			if (temp->next == nullptr) {
				cout << "Value not found..";
				return;
			}

			Node* nodeToDelete = temp->next;
			temp->next = temp->next->next;
			delete nodeToDelete;
		}

		void display() {
			if (head == nullptr) {
				cout << "list is empty" << endl;
				return;
			}

			Node* temp = head;
			while (temp != nullptr) {
				cout << temp->data << " -> ";
				temp = temp->next;
			}
			cout << "NULL" << endl;
		}


		//destructor
		~LinkedList() {
			Node* temp;
			while (head != nullptr) {
				temp = head;
				head = head->next;
				delete temp;
			}
		}
};







int main() {
	LinkedList list;  // Create a linked list

	// Insert some nodes
	list.insertAtBeginning(10);
	list.insertAtBeginning(20);
	list.insertAtEnd(30);
	list.insertAtEnd(40);

	// Display the list
	cout << "Linked list after insertions: " << endl;
	list.display();

	// Delete a node
	list.deleteNode(20);
	cout << "Linked list after deleting 20: " << endl;
	list.display();

	// Try deleting a node that doesn't exist
	list.deleteNode(50);

	return 0;
}
