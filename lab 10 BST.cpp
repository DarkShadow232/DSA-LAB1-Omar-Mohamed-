#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int val) {
        data = val;
        left = right = NULL;
    }
};

class BST {
public:
    node* root;

    BST() {
        root = NULL;
    }

    node* insert(node* currentNode, int value) {
        if (currentNode == NULL) {
            currentNode = new node(value);
        }
        else if (value < currentNode->data) {
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

    void preorder(node* currentNode) {
        if (currentNode == NULL) return;

        cout << currentNode->data << "\t";
        preorder(currentNode->left);
        preorder(currentNode->right);
    }

    void inorder(node* currentNode) {
        if (currentNode == NULL) return;

        inorder(currentNode->left);
        cout << currentNode->data << "\t";
        inorder(currentNode->right);
    }

    void postorder(node* currentNode) {
        if (currentNode == NULL) return;

        postorder(currentNode->left);
        postorder(currentNode->right);
        cout << currentNode->data << "\t";
    }

    node* Search(node* currentNode, int targetValue) {
        if (currentNode == NULL || currentNode->data == targetValue)
            return currentNode;

        if (targetValue < currentNode->data)
            return Search(currentNode->left, targetValue);

        return Search(currentNode->right, targetValue);
    }

    bool search(int targetValue) {
        node* result = Search(root, targetValue);
        return result != NULL;
    }

    node* FindMin(node* currentNode) {
        if (currentNode == NULL) return NULL;
        else if (currentNode->left == NULL)
            return currentNode;
        else
            return FindMin(currentNode->left);
    }

    node* deleteNode(node* currentNode, int targetValue) {
        if (currentNode == NULL) return currentNode;

        if (targetValue < currentNode->data)
            currentNode->left = deleteNode(currentNode->left, targetValue);
        else if (targetValue > currentNode->data)
            currentNode->right = deleteNode(currentNode->right, targetValue);
        else {
            if (currentNode->left == NULL) {
                node* temp = currentNode->right;
                delete currentNode;
                return temp;
            }
            else if (currentNode->right == NULL) {
                node* temp = currentNode->left;
                delete currentNode;
                return temp;
            }
            node* successor = FindMin(currentNode->right);
            currentNode->data = successor->data;
            currentNode->right = deleteNode(currentNode->right, successor->data);
        }
        return currentNode;
    }

    void deleteNode(int targetValue) {
        root = deleteNode(root, targetValue);
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

    cout << "Preorder traversal: ";
    tree.preorder(tree.root);
    cout << endl;

    cout << "Inorder traversal: ";
    tree.inorder(tree.root);
    cout << endl;

    cout << "Postorder traversal: ";
    tree.postorder(tree.root);
    cout << endl;

    int key = 40;
    if (tree.search(key))
        cout << key << " found in the tree." << endl;
    else
        cout << key << " not found in the tree." << endl;

    tree.deleteNode(20);
    cout << "Inorder traversal after deleting 20: ";
    tree.inorder(tree.root);
    cout << endl;

    tree.deleteNode(30);
    cout << "Inorder traversal after deleting 30: ";
    tree.inorder(tree.root);
    cout << endl;

    tree.deleteNode(50);
    cout << "Inorder traversal after deleting 50: ";
    tree.inorder(tree.root);
    cout << endl;

    return 0;
}
