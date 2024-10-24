#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void insertFirst(Node* &head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}

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

void printList(Node* head) {
    Node* temp = head;
    cout << "DAFTAR ANGGOTA LIST: ";
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) {
            cout << " <-> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    int firstElement;
    cout << "Masukkan elemen pertama: ";
    cin >> firstElement;
    insertLast(head, firstElement);
    printList(head);

    int secondElement;
    cout << "Masukkan elemen kedua di awal: ";
    cin >> secondElement;
    insertFirst(head, secondElement);
    printList(head);

    int thirdElement;
    cout << "Masukkan elemen ketiga di akhir: ";
    cin >> thirdElement;
    insertLast(head, thirdElement);
    printList(head);

    return 0;
}
