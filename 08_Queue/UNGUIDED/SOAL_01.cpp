// 1.	Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list
// 2.	Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa
// 3.	Modifikasi program pada soal 1 sehingga mahasiswa dapat diprioritaskan berdasarkan NIM (NIM yang lebih kecil didahulukan pada saat output). 

#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    int nim;
    Mahasiswa* next;
};

Mahasiswa* front = nullptr;
Mahasiswa* back = nullptr;

// Cek apakah queue kosong
bool isEmpty() {
    return front == nullptr;
}

// Menambahkan elemen ke queue dengan prioritas berdasarkan NIM
void enqueueAntrian(string nama, int nim) {
    Mahasiswa* newMahasiswa = new Mahasiswa();
    newMahasiswa->nama = nama;
    newMahasiswa->nim = nim;
    newMahasiswa->next = nullptr;

    if (isEmpty()) {
        front = newMahasiswa;
        back = newMahasiswa;
    } else {
        // Prioritaskan mahasiswa dengan NIM lebih kecil
        if (nim < front->nim) {
            newMahasiswa->next = front;
            front = newMahasiswa;
        } else {
            Mahasiswa* temp = front;
            while (temp->next != nullptr && temp->next->nim <= nim) {
                temp = temp->next;
            }
            newMahasiswa->next = temp->next;
            temp->next = newMahasiswa;
            if (newMahasiswa->next == nullptr) {
                back = newMahasiswa;
            }
        }
    }
}

// Menampilkan isi queue
void viewQueue() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        Mahasiswa* temp = front;
        int i = 1;
        while (temp != nullptr) {
            cout << "Antrian ke-" << i << " : Nama = " << temp->nama << ", NIM = " << temp->nim << endl;
            temp = temp->next;
            i++;
        }
    }
}

// Menghapus elemen dari queue
void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        Mahasiswa* temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            back = nullptr;
        }
    }
}

// Menghitung jumlah elemen dalam queue
int countQueue() {
    int count = 0;
    Mahasiswa* temp = front;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Mengosongkan queue
void clearQueue() {
    while (!isEmpty()) {
        dequeueAntrian();
    }
    cout << "Antrian dikosongkan" << endl;
}

int main() {
    int pilihan;
    do {
        cout << "\nMenu Antrian Mahasiswa:" << endl;
        cout << "1. Tambah Mahasiswa ke Antrian" << endl;
        cout << "2. Lihat Antrian" << endl;
        cout << "3. Hapus Mahasiswa dari Antrian" << endl;
        cout << "4. Kosongkan Antrian" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                string nama;
                int nim;
                cout << "Masukkan Nama Mahasiswa: ";
                cin >> nama;
                cout << "Masukkan NIM Mahasiswa: ";
                cin >> nim;
                enqueueAntrian(nama, nim);
                break;
            }
            case 2:
                viewQueue();
                break;
            case 3:
                dequeueAntrian();
                break;
            case 4:
                clearQueue();
                break;
            case 5:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih kembali." << endl;
        }
    } while (pilihan != 5);

    return 0;
}
