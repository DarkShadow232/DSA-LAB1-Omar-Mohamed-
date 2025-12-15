#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = NULL;

void insert(int value) {
    Node* newNode = new Node();
    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        Node* lastNode = head->prev;
        lastNode->next = newNode;
        newNode->prev = lastNode;
        newNode->next = head;
        head->prev = newNode;
    }
}

void display() {
    if (head == NULL) {
        cout << "Empty" << endl;
        return;
    }

    Node* current = head;
    do {
        cout << current->data << " <-> ";
        current = current->next;
    } while (current != head);
    cout << "..." << endl;
}

int main() {
    insert(10);
    insert(20);
    insert(30);

    display();

    return 0;
}

