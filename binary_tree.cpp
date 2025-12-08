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

void LNR(Node* node) {
    if (node == NULL) return;
    LNR(node->left);
    cout << node->data << " ";
    LNR(node->right);
}

void NLR(Node* node) {
    if (node == NULL) return;
    cout << node->data << " ";
    NLR(node->left);
    NLR(node->right);
}

void LRN(Node* node) {
    if (node == NULL) return;
    LRN(node->left);
    LRN(node->right);
    cout << node->data << " ";
}

int main() {
    insert(50);
    insert(30);
    insert(70);
    insert(20);
    insert(40);

    cout << "LNR: ";
    LNR(root);
    cout << endl;

    cout << "NLR: ";
    NLR(root);
    cout << endl;

    cout << "LRN: ";
    LRN(root);
    cout << endl;

    return 0;
}

