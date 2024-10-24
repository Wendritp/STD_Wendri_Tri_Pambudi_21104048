#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void insertLast(Node* &head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void printListForward(Node* head) {
    Node* temp = head;
    cout << "Daftar elemen dari depan ke belakang: ";
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) {
            cout << " <-> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

void printListBackward(Node* head) {
    if (head == NULL) return;

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    cout << "Daftar elemen dari belakang ke depan: ";
    while (temp != NULL) {
        cout << temp->data;
        if (temp->prev != NULL) {
            cout << " <-> ";
        }
        temp = temp->prev;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    int value;
    for (int i = 1; i <= 4; i++) {
        cout << "Masukkan elemen ke-" << i << ": ";
        cin >> value;
        insertLast(head, value);
    }

    printListForward(head);
    printListBackward(head);

    return 0;
}
