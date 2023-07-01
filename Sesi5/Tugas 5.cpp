#include <iostream>

using namespace std;

// Struktur Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Fungsi untuk membuat Node baru
Node* createNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Error dalam membuat Node." << endl;
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Fungsi untuk memasukkan bilangan ke dalam tree
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }
    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);
    return root;
}

// Fungsi untuk mencetak Node secara pre-order
void preOrderTraversal(Node* root) {
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// Fungsi untuk mencetak Node secara in-order
void inOrderTraversal(Node* root) {
    if (root == NULL)
        return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

// Fungsi untuk mencetak Node secara post-order
void postOrderTraversal(Node* root) {
    if (root == NULL)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = NULL;
    int numbers[] = {12, 16, 20, 24, 32};

    // Memasukkan bilangan ke dalam tree
    for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++)
        root = insertNode(root, numbers[i]);

    cout << "Traversal Pre-order: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "Traversal In-order: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Traversal Post-order: ";
    postOrderTraversal(root);
    cout << endl;

    return 0;
