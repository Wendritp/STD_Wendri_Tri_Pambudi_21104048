#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

void insertFront(Node*& head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

void insertBack(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteNodeByValue(Node*& head, int value) {
    if (head == nullptr) {
        cout << "Linked list kosong. Tidak ada node yang bisa dihapus." << endl;
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;

    if (temp != nullptr && temp->data == value) {
        head = temp->next;
        delete temp;
        return;
    }

    while (temp != nullptr && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Node dengan nilai " << value << " tidak ditemukan." << endl;
        return;
    }

    prev->next = temp->next;
    delete temp;
}

void printList(Node* head) {
    if (head == nullptr) {
        cout << "Linked list kosong." << endl;
    } else {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }
}

int main() {
    Node* head = nullptr;

    insertFront(head, 10);
    insertBack(head, 20);
    insertFront(head, 5);

    cout << "Isi linked list sebelum penghapusan: ";
    printList(head);

    int valueToDelete = 10;
    cout << "Menghapus node dengan nilai: " << valueToDelete << endl;
    deleteNodeByValue(head, valueToDelete);

    cout << "Isi linked list setelah penghapusan: ";
    printList(head);

    return 0;
}
