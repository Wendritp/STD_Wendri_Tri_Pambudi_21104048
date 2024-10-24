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

// Fungsi untuk mencari elemen dalam list
void searchElement(Node* head, int value) {
    Node* current = head;
    int position = 1;
    
    while (current != NULL) {
        if (current->data == value) {
            cout << "Elemen " << value << " ditemukan di alamat " << current << " pada urutan ke-" << position << "." << endl;
            return;
        }
        current = current->next;
        position++;
    }
    
    cout << "Elemen " << value << " tidak ditemukan dalam list." << endl;
}

int main() {
    Node* head = NULL;

    cout << "Masukkan 6 elemen ke dalam list:" << endl;
    for (int i = 0; i < 6; i++) {
        int value;
        cout << "Elemen " << i+1 << ": ";
        cin >> value;
        insertNode(head, value);
    }

    int cari;
    cout << "Masukkan elemen yang ingin dicari: ";
    cin >> cari;

    searchElement(head, cari);

    return 0;
}
