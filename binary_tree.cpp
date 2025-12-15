#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* root = NULL;

void insert(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    if (root == NULL) {
        root = newNode;
        return;
    }

    Node* current = root;
    while (true) {
        if (value < current->data) {
            if (current->left == NULL) {
                current->left = newNode;
                break;
            }
            current = current->left;
        } else {
            if (current->right == NULL) {
                current->right = newNode;
                break;
            }
            current = current->right;
        }
    }
}

void inorderTraversal(Node* node) {
    if (node == NULL) return;
    inorderTraversal(node->left);
    cout << node->data << " ";
    inorderTraversal(node->right);
}

void preorderTraversal(Node* node) {
    if (node == NULL) return;
    cout << node->data << " ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

void postorderTraversal(Node* node) {
    if (node == NULL) return;
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->data << " ";
}

Node* findMinimumNode(Node* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

Node* deleteNode(Node* node, int value) {
    if (node == NULL) {
        return NULL;
    }

    if (value < node->data) {
        node->left = deleteNode(node->left, value);
    }
    else if (value > node->data) {
        node->right = deleteNode(node->right, value);
    }
    else {
        if (node->left == NULL && node->right == NULL) {
            delete node;
            return NULL;
        }
        
        if (node->left == NULL) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == NULL) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        
        Node* successor = findMinimumNode(node->right);
        node->data = successor->data;
        node->right = deleteNode(node->right, successor->data);
    }
    
    return node;
}

void deleteValue(int value) {
    root = deleteNode(root, value);
}

int main() {
    insert(50);
    insert(30);
    insert(70);
    insert(20);
    insert(40);

    cout << "Before deletion:" << endl;
    cout << "Inorder: ";
    inorderTraversal(root);
    cout << endl;

    cout << "\nDeleting 30..." << endl;
    deleteValue(30);
    
    cout << "After deletion:" << endl;
    cout << "Inorder: ";
    inorderTraversal(root);
    cout << endl;

    cout << "\nPreorder: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Postorder: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}

