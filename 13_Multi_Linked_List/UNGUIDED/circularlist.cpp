#include "circularlist.h"
#include <iostream>
using namespace std;

void createList(List &L) {
    L.first = nullptr;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = nullptr;
}

void insertFirst(List &L, address P) {
    if (L.first == nullptr) {
        L.first = P;
        P->next = P;
        P->prev = P;
    } else {
        address last = L.first->prev;
        P->next = L.first;
        P->prev = last;
        last->next = P;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLast(List &L, address P) {
    if (L.first == nullptr) {
        insertFirst(L, P);
    } else {
        address last = L.first->prev;
        P->next = L.first;
        P->prev = last;
        last->next = P;
        L.first->prev = P;
    }
}

void insertAfter(List &L, address Prec, address P) {
    if (Prec != nullptr) {
        P->next = Prec->next;
        P->prev = Prec;
        Prec->next->prev = P;
        Prec->next = P;
    }
}

void printInfo(List L) {
    address P = L.first;
    if (P != nullptr) {
        do {
            cout << "Nama: " << P->info.nama
                 << ", NIM: " << P->info.nim
                 << ", Jenis Kelamin: " << P->info.jenis_kelamin
                 << ", IPK: " << P->info.ipk << endl;
            P = P->next;
        } while (P != L.first);
    } else {
        cout << "List kosong." << endl;
    }
}

address createData(string nama, string nim, char jenis_kelamin, float ipk) {
    infotype x;
    x.nama = nama;
    x.nim = nim;
    x.jenis_kelamin = jenis_kelamin;
    x.ipk = ipk;
    return alokasi(x);
}
