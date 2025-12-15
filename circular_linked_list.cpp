#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insert(int value) {
    Node* newNode = new Node();
    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* current = head;
        while (current->next != head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = head;
    }
}

void display() {
    if (head == NULL) {
        cout << "Empty" << endl;
        return;
    }

    Node* current = head;
    do {
        cout << current->data << " -> ";
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

