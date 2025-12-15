#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* root = NULL;

Node* insert(Node* currentNode, int value) {
    if (currentNode == NULL) {
        return new Node(value);
    }
    
    if (value < currentNode->data) {
        currentNode->left = insert(currentNode->left, value);
    }
    else {
        currentNode->right = insert(currentNode->right, value);
    }
    
    return currentNode;
}

void insert(int value) {
    root = insert(root, value);
}

Node* search(Node* currentNode, int targetValue) {
    if (currentNode == NULL || currentNode->data == targetValue) {
        return currentNode;
    }
    
    if (targetValue < currentNode->data) {
        return search(currentNode->left, targetValue);
    }
    
    return search(currentNode->right, targetValue);
}

bool search(int targetValue) {
    return search(root, targetValue) != NULL;
}

void inorder(Node* currentNode) {
    if (currentNode == NULL) return;
    inorder(currentNode->left);
    cout << currentNode->data << " ";
    inorder(currentNode->right);
}

int main() {
    insert(50);
    insert(30);
    insert(70);
    insert(20);
    insert(40);
    
    cout << "Tree values: ";
    inorder(root);
    cout << endl;
    
    cout << "\nTime Complexity:" << endl;
    cout << "----------------" << endl;
    cout << "Insert: O(log n) if balanced, O(n) if skewed" << endl;
    cout << "Search: O(log n) if balanced, O(n) if skewed" << endl;
    cout << "Delete: O(log n) if balanced, O(n) if skewed" << endl;
    cout << "Traverse: O(n) - visit all nodes" << endl;
    
    return 0;
}
