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

void deleteFirst(Node* &head) {
    if (head == NULL) {
        cout << "List kosong, tidak bisa menghapus." << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    delete temp;
}

void deleteLast(Node* &head) {
    if (head == NULL) {
        cout << "List kosong, tidak bisa menghapus." << endl;
        return;
    }

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    delete temp;
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
    cout << "Masukkan elemen kedua di akhir: ";
    cin >> secondElement;
    insertLast(head, secondElement);
    printList(head);

    int thirdElement;
    cout << "Masukkan elemen ketiga di akhir: ";
    cin >> thirdElement;
    insertLast(head, thirdElement);
    printList(head);
    cout << "===========================" << endl;
    cout << "Menghapus elemen pertama dan terakhir:" << endl;
    deleteFirst(head);
    deleteLast(head);
    cout << "List setelah dihapus: ";
    printList(head);

    return 0;
}
