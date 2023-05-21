#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    if (newNode == NULL) {
        cout << "Error creating node!" << endl;
        exit(1);
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int value) {
    if (root == NULL) {
        root = createNode(value);
        return root;
    }
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    }
    else {
        root->right = insertNode(root->right, value);
    }
    return root;
}

void preOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main() {
    Node* root = NULL;

    // Menambahkan bilangan ke dalam tree
    root = insertNode(root, 12);
    root = insertNode(root, 16);
    root = insertNode(root, 20);
    root = insertNode(root, 24);
    root = insertNode(root, 32);

    // Menampilkan tree secara pre-order
    cout << "Pre-order traversal: ";
    preOrderTraversal(root);
    cout << endl;

    return 0;
}
