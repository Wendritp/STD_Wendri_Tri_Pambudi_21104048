#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertSorted(Node* &head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL || head->data >= value) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != NULL && current->next->data < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    cout << "Masukkan 4 elemen (secara terurut):" << endl;
    for (int i = 0; i < 4; i++) {
        int value;
        cout << "Elemen " << i+1 << ": ";
        cin >> value;
        insertSorted(head, value);
    }

    cout << "List setelah memasukkan 4 elemen: ";
    printList(head);

    int additionalValue;
    cout << "Masukkan elemen tambahan yang ingin ditambahkan: ";
    cin >> additionalValue;

    insertSorted(head, additionalValue);

    cout << "List setelah menambahkan elemen baru: ";
    printList(head);

    return 0;
}
