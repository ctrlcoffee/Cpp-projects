#include <iostream>
using namespace std;
struct Node {
	int data;
	Node* left;
	Node* right;

	Node(int value) {
		data = value;
		left = right=nullptr;

	}
};

class BST {
public:
	Node* root;

	BST() {
		root = nullptr;
	}

	void insert(int value) {
		root = insertRec(root, value);

	}

	bool search(int value) {
		return searchRec(root, value);

	}
	void inOrder() {
		inOrderRec(root);
		cout << endl;
	}

private:
	Node* insertRec(Node* node, int value) {
		if (node == nullptr) {
			return new Node(value);
		}

		if (value < node->data) {
			node->left = insertRec(node->left, value);
		}
		else if (value > node->data) {
			node->right = insertRec(node->right, value);
		}
		return node;

	}

	bool searchRec(Node* node, int value) {
		if (node == nullptr) {
			return false;
		}
		if (value == node->data) {
			return true;
		}
		else if (value < node->data) {
			return searchRec(node->left, value);
		}
		else {
			return searchRec(node->right, value);
		}
	}


	void inOrderRec(Node* node) {
		if (node == nullptr) {
			return;
		}

		inOrderRec(node->left);
		cout << node->data << " ";
		inOrderRec(node->right);
	}
};



int main() {
	BST tree;
	tree.insert(50);
	tree.insert(30);
	tree.insert(20);
	tree.insert(40);
	tree.insert(70);
	tree.insert(60);
	tree.insert(80);
	cout << "In-order traversal: ";
	tree.inOrder();


	int searchValue = 40;
	if (tree.search(searchValue)) {
		cout << searchValue << " found in the tree." << endl;
	}
	else {
		cout << searchValue << " not found in the tree." << endl;
	}

	return 0;
}
