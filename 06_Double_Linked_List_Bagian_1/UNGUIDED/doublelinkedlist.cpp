#include <iostream>
using namespace std;

// Definisi struktur Node
struct Node {
    int idBuku;
    string judulBuku;
    string penulisBuku;
    Node* prev;
    Node* next;
};

// Fungsi untuk membuat node buku baru
Node* createNode(int id, string judul, string penulis) {
    Node* newNode = new Node();
    newNode->idBuku = id;
    newNode->judulBuku = judul;
    newNode->penulisBuku = penulis;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Fungsi untuk menambahkan buku di akhir linked list
void tambahBuku(Node* &head, int id, string judul, string penulis) {
    Node* newNode = createNode(id, judul, penulis);
    
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    cout << "Buku '" << judul << "' oleh " << penulis << " berhasil ditambahkan." << endl;
}

// Fungsi untuk menampilkan buku dari awal ke akhir
void tampilkanDariAwal(Node* head) {
    if (head == NULL) {
        cout << "Daftar buku kosong." << endl;
        return;
    }
    Node* temp = head;
    cout << "\nDaftar Buku dari Awal ke Akhir:" << endl;
    while (temp != NULL) {
        cout << "ID Buku: " << temp->idBuku << ", Judul: " << temp->judulBuku 
             << ", Penulis: " << temp->penulisBuku << endl;
        temp = temp->next;
    }
}

// Fungsi untuk menampilkan buku dari akhir ke awal
void tampilkanDariAkhir(Node* head) {
    if (head == NULL) {
        cout << "Daftar buku kosong." << endl;
        return;
    }
    Node* temp = head;
    
    while (temp->next != NULL) {
        temp = temp->next;
    }

    cout << "\nDaftar Buku dari Akhir ke Awal:" << endl;
    while (temp != NULL) {
        cout << "ID Buku: " << temp->idBuku << ", Judul: " << temp->judulBuku 
             << ", Penulis: " << temp->penulisBuku << endl;
        temp = temp->prev;
    }
}

// Fungsi utama
int main() {
    Node* head = NULL;

    tambahBuku(head, 1, "Pemrograman C++", "Budi Santoso");
    tambahBuku(head, 2, "Algoritma Pemrograman", "Ani Setiawati");
    tambahBuku(head, 3, "Struktur Data", "Susi Widyaningrum");

    tampilkanDariAwal(head);

    tampilkanDariAkhir(head);

    return 0;
}
