#include <iostream>
#include "stack.h"

using namespace std;

// Prosedur untuk membuat stack
void createStack(stack &S) {
    S.Top = 0; // Stack kosong
}

// Fungsi untuk memeriksa apakah stack kosong
bool isEmpty(stack S) {
    return (S.Top == 0); // Jika Top = 0, maka stack kosong
}

// Fungsi untuk memeriksa apakah stack penuh
bool isFull(stack S) {
    return (S.Top == MAX_SIZE); // Jika Top sama dengan ukuran maksimum, maka stack penuh
}

// Prosedur untuk menambahkan elemen ke dalam stack
void push(stack &S, infotype x) {
    if (isFull(S)) {
        cout << "Stack Penuh! Tidak dapat menambahkan elemen." << endl;
    } else {
        S.info[S.Top] = x; // Menyimpan elemen pada indeks Top
        S.Top++; // Menaikkan nilai Top
        cout << "Elemen " << x << " berhasil ditambahkan ke dalam stack." << endl;
    }
}

// Fungsi untuk mengeluarkan elemen dari stack
infotype pop(stack &S) {
    if (isEmpty(S)) {
        cout << "Stack Kosong! Tidak ada elemen untuk dikeluarkan." << endl;
        return 0; // Mengembalikan karakter null jika stack kosong
    } else {
        S.Top--; // Menurunkan nilai Top
        return S.info[S.Top]; // Mengembalikan elemen yang diambil
    }
}

// Prosedur untuk mencetak semua informasi di dalam stack
void printInfo(stack S) {
    if (isEmpty(S)) {
        cout << "Stack Kosong!" << endl;
    } else {
        for (int i = S.Top - 1; i >= 0; i--) { // Mulai dari elemen paling atas ke bawah
            cout << S.info[i] << " "; 
        }
        cout << endl;
    }
}

int main() {
    stack S;
    createStack(S);

    int digitTerakhirNIM = 8; // Ubah sesuai digit terakhir NIM yang diinginkan (0, 1, 2, atau 3)
    string input;

    // Memilih isi stack berdasarkan digit terakhir NIM MOD 4
    switch (digitTerakhirNIM % 4) {
        case 0:
            input = "IFLABJAYA";
            cout << "Output:" << endl;
            break;
        case 1:
            input = "HALOBANDUNG";
            cout << "Output:" << endl;
            break;
        case 2:
            input = "PERCAYADIRI";
            cout << "Output:" << endl;
            break;
        case 3:
            input = "STRUKTURDATA";
            cout << "Output:" << endl;
            break;
        default:
            cout << "Digit terakhir NIM tidak valid." << endl;
            return 0;
    }

    for (int i = input.length() - 1; i >= 0; i--) {
        push(S, input[i]);
    }

    // Menampilkan isi stack awal
    cout << "Isi stack awal: ";
    printInfo(S);

    // Pop beberapa elemen hingga mencapai bagian akhir yang diminta
    int jumlahPop = input.length() - 4;
    for (int i = 0; i < jumlahPop; i++) {
        pop(S);
    }

    // Menampilkan isi stack setelah beberapa elemen di-pop
    cout << "Isi stack sesudah pop: ";
    printInfo(S);

    return 0;
}
