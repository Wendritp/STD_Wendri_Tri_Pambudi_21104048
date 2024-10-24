#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertNode(Node* &head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
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

void bubbleSortList(Node* head) {
    if (head == NULL) return;

    bool swapped;
    Node* current;
    Node* lastSorted = NULL;

    do {
        swapped = false;
        current = head;

        while (current->next != lastSorted) {
            if (current->data > current->next->data) {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
        lastSorted = current;
    } while (swapped);
}

int main() {
    Node* head = NULL; 

    cout << "Masukkan 5 elemen ke dalam list:" << endl;
    for (int i = 0; i < 5; i++) {
        int value;
        cout << "Elemen " << i+1 << ": ";
        cin >> value;
        insertNode(head, value);
    }

    cout << "List sebelum diurutkan: ";
    printList(head);

    bubbleSortList(head);

    cout << "List setelah diurutkan: ";
    printList(head);

    return 0;
}
