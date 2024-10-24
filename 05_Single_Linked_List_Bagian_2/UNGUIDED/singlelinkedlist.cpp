#include <iostream>
#include <string>
using namespace std;

// Struktur node untuk menyimpan data mahasiswa
struct Node {
    int NIM;    
    string nama;      
    Node* next;      
};


void tambahMahasiswa(Node*& head, int nim, string nama) {
    // Membuat node baru
    Node* newNode = new Node;
    newNode->NIM = nim;
    newNode->nama = nama;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    cout << "Mahasiswa dengan NIM " << nim << " berhasil ditambahkan.\n";
}

// Fungsi untuk mencari mahasiswa berdasarkan NIM
void cariMahasiswa(Node* head, int nim) {
    Node* temp = head;

    while (temp != nullptr) {
        if (temp->NIM == nim) {
            cout << "Mahasiswa ditemukan: " << temp->nama << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan.\n";
}

// Fungsi untuk menampilkan semua data mahasiswa dalam linked list
void tampilkanSemuaMahasiswa(Node* head) {
    Node* temp = head;
    if (temp == nullptr) {
        cout << "Tidak ada data mahasiswa." << endl;
        return;
    }

    cout << "Daftar Mahasiswa: " << endl;
    while (temp != nullptr) {
        cout << "NIM: " << temp->NIM << ", Nama: " << temp->nama << endl;
        temp = temp->next;
    }
}

void tampilkanMenu() {
    cout << "\nMenu:\n";
    cout << "1. Tambah Mahasiswa\n";
    cout << "2. Cari Mahasiswa\n";
    cout << "3. Tampilkan Semua Mahasiswa\n";
    cout << "4. Keluar\n";
    cout << "Pilih menu (1-4): ";
}

int main() {
    Node* head = nullptr; 
    int pilihan;

    do {
        tampilkanMenu();
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                // Menambahkan data mahasiswa
                int nim;
                string nama;
                cout << "Masukkan NIM: ";
                cin >> nim;
                cin.ignore();
                cout << "Masukkan Nama: ";
                getline(cin, nama);
                tambahMahasiswa(head, nim, nama);
                break;
            }
            case 2: {
                // Mencari mahasiswa berdasarkan NIM
                int cariNIM;
                cout << "Masukkan NIM mahasiswa yang ingin dicari: ";
                cin >> cariNIM;
                cariMahasiswa(head, cariNIM);
                break;
            }
            case 3: {
                // Menampilkan semua mahasiswa
                tampilkanSemuaMahasiswa(head);
                break;
            }
            case 4: {
                // Keluar dari program
                cout << "Keluar dari program.\n";
                break;
            }
            default:
                cout << "Pilihan tidak valid. Silakan pilih menu yang benar.\n";
        }

    } while (pilihan != 4);

    return 0;
}
