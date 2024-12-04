#include "circularlist.h"
#include <iostream>

using namespace std;

// Membuat list kosong
void CreateList(List &L) {
    L.first = nullptr;
}

// Alokasi elemen list
address alokasi(infotype x) {
    address P = new ElmList;
    if (P != nullptr) {
        P->info = x;
        P->next = nullptr;
    }
    return P;
}

// Dealokasi elemen list
void dealokasi(address P) {
    delete P;
}

// Menambahkan elemen di awal list
void insertFirst(List &L, address P) {
    if (L.first == nullptr) {
        P->next = P; // Circular
        L.first = P;
    } else {
        address last = L.first;
        while (last->next != L.first) {
            last = last->next;
        }
        P->next = L.first;
        last->next = P;
        L.first = P;
    }
}

// Menambahkan elemen di akhir list
void insertLast(List &L, address P) {
    if (L.first == nullptr) {
        insertFirst(L, P);
    } else {
        address last = L.first;
        while (last->next != L.first) {
            last = last->next;
        }
        last->next = P;
        P->next = L.first;
    }
}

// Menambahkan elemen setelah elemen tertentu
void insertAfter(List &L, address Prec, address P) {
    if (Prec != nullptr) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

// Menghapus elemen pertama
void deleteFirst(List &L, address &P) {
    if (L.first != nullptr) {
        P = L.first;
        if (P->next == L.first) {
            L.first = nullptr;
        } else {
            address last = L.first;
            while (last->next != L.first) {
                last = last->next;
            }
            L.first = P->next;
            last->next = L.first;
        }
        P->next = nullptr;
    }
}

// Menghapus elemen terakhir
void deleteLast(List &L, address &P) {
    if (L.first != nullptr) {
        address prev = nullptr;
        P = L.first;
        while (P->next != L.first) {
            prev = P;
            P = P->next;
        }
        if (prev == nullptr) { // Hanya satu elemen
            L.first = nullptr;
        } else {
            prev->next = L.first;
        }
        P->next = nullptr;
    }
}

// Menghapus elemen setelah elemen tertentu
void deleteAfter(List &L, address Prec, address &P) {
    if (Prec != nullptr && Prec->next != L.first) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = nullptr;
    }
}

// Mencari elemen dengan nilai tertentu
address findElm(List L, infotype x) {
    address P = L.first;
    if (P != nullptr) {
        do {
            if (P->info.nim == x.nim) {
                return P;
            }
            P = P->next;
        } while (P != L.first);
    }
    return nullptr;
}

// Menampilkan informasi elemen pada list
void printInfo(List L) {
    address P = L.first;
    if (P != nullptr) {
        do {
            cout << "Nama: " << P->info.nama << ", "
                 << "NIM: " << P->info.nim << ", "
                 << "Jenis Kelamin: " << P->info.jenis_kelamin << ", "
                 << "IPK: " << P->info.ipk << endl;
            P = P->next;
        } while (P != L.first);
    } else {
        cout << "List kosong." << endl;
    }
}
