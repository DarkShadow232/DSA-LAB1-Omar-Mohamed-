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

    node* insert(node* r, int item) {
        if (r == NULL) {
            r = new node(item);
        }
        else if (item < r->data) {
            r->left = insert(r->left, item);
        }
        else {
            r->right = insert(r->right, item);
        }
        return r;
    }

    void insert(int item) {
        root = insert(root, item);
    }

    void preorder(node* r) {
        if (r == NULL) return;

        cout << r->data << "\t";
        preorder(r->left);
        preorder(r->right);
    }

    void inorder(node* r) {
        if (r == NULL) return;

        inorder(r->left);
        cout << r->data << "\t";
        inorder(r->right);
    }

    void postorder(node* r) {
        if (r == NULL) return;

        postorder(r->left);
        postorder(r->right);
        cout << r->data << "\t";
    }

    node* Search(node* r, int key) {
        if (r == NULL || r->data == key)
            return r;

        if (key < r->data)
            return Search(r->left, key);

        return Search(r->right, key);
    }

    bool search(int key) {
        node* result = Search(root, key);
        return result != NULL;
    }

    node* FindMin(node* r) {
        if (r == NULL) return NULL;
        else if (r->left == NULL)
            return r;
        else
            return FindMin(r->left);
    }

    node* deleteNode(node* r, int key) {
        if (r == NULL) return r;

        if (key < r->data)
            r->left = deleteNode(r->left, key);
        else if (key > r->data)
            r->right = deleteNode(r->right, key);
        else {
            if (r->left == NULL) {
                node* temp = r->right;
                delete r;
                return temp;
            }
            else if (r->right == NULL) {
                node* temp = r->left;
                delete r;
                return temp;
            }
            node* temp = FindMin(r->right);
            r->data = temp->data;
            r->right = deleteNode(r->right, temp->data);
        }
        return r;
    }

    void deleteNode(int key) {
        root = deleteNode(root, key);
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
