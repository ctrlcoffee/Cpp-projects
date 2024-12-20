#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

// Define the node's properties:
struct Node {
    int data;
    Node* right;
    Node* left;
};

// Function to create a new node:
Node* createNewNode(int data) {
    Node* newNode = new Node();
    newNode->right = nullptr;
    newNode->left = nullptr;
    newNode->data = data;
    return newNode;
}

// Function to insert a new node:
Node* insertNewNode(Node* root, int data) {
    if (root == nullptr) {
        return createNewNode(data);
    }
    if (data < root->data) {
        root->left = insertNewNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = insertNewNode(root->right, data);
    }
    return root;
}

// Function to search in the tree:
Node* searchKey(Node* root, int data) {
    if (root == nullptr || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return searchKey(root->left, data);
    }
    else {
        return searchKey(root->right, data);
    }
}

// Function to traverse the tree (inorder):
void traverseInorder(Node* root) {
    if (root != nullptr) {
        traverseInorder(root->left);
        cout << " " << root->data;
        traverseInorder(root->right);
    }
}

// Function to traverse the tree (preorder):
void traversePreorder(Node* root) {
    if (root != nullptr) {
        cout << " " << root->data;
        traversePreorder(root->left);
        traversePreorder(root->right);
    }
}

// Function to traverse the tree (postorder):
void traversePostorder(Node* root) {
    if (root != nullptr) {
        traversePostorder(root->left);
        traversePostorder(root->right);
        cout << " " << root->data;
    }
}



// Function to find inorder successor for deleting a node with two children:
Node* findSuccessor(Node* root) {
    while (root != nullptr && root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Function to delete a node:
Node* deleteNode(Node* root, int data) {
    if (root == nullptr) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findSuccessor(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    cout << "\n  ____   _____ _______   _______ _____  ______ ______  \n";
    cout << " |  _ \\ / ____|__   __| |__   __|  __ \\|  ____|  ____| \n";
    cout << " | |_) | (___    | |       | |  | |__) | |__  | |__    \n";
    cout << " |  _ < \\\___ \\   | |       | |  |  _  /|  __| |  __|   \n";
    cout << " | |_) |____) |  | |       | |  | | \\\\| |____| |____  \n";
    cout << " |____/|_____/   |_|       |_|  |_|  \\\\______|______| \n\n";

    Node* root = nullptr;
    int choice, data;

    while (true) {
        cout << "\nBinary Search Tree Operations:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Display Tree\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        if (choice < 1 || choice > 5) {
            cout << "Invalid choice. Please enter a number between 1 and 5.\n";
            continue;
        }

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> data;
            root = insertNewNode(root, data);
            cout << "Value inserted." << endl;
            break;

        case 2:
            cout << "Enter value to delete: ";
            cin >> data;
            root = deleteNode(root, data);
            cout << "Value deleted (if it existed)." << endl;
            break;

        case 3:
            cout << "Enter value to search: ";
            cin >> data;
            if (searchKey(root, data) != nullptr) {
                cout << "Value found in the tree." << endl;
            }
            else {
                cout << "Value not found in the tree." << endl;
            }
            break;

        case 4:
            cout << "\nTree as plain text (Inorder Traversal):";
            traverseInorder(root);
            cout << "\nPreorder Traversal:";
            traversePreorder(root);
            cout << "\nPostorder Traversal:";
            traversePostorder(root);
            cout << "\n";
            break;

        case 5:
            cout << "Exiting program." << endl;
            return 0;
        }
    }

    return 0;
}
