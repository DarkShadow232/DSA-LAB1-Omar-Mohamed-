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

Node* insert(Node* node, int val) {
    if (node == NULL) {
        return new Node(val);
    }
    
    if (val < node->data) {
        node->left = insert(node->left, val);
    }
    else {
        node->right = insert(node->right, val);
    }
    
    return node;
}

void insert(int val) {
    root = insert(root, val);
}

Node* search(Node* node, int key) {
    if (node == NULL || node->data == key) {
        return node;
    }
    
    if (key < node->data) {
        return search(node->left, key);
    }
    
    return search(node->right, key);
}

bool search(int key) {
    return search(root, key) != NULL;
}

void inorder(Node* node) {
    if (node == NULL) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
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
