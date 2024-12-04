#include "multilist.h"
#include <iostream>

using namespace std;

// Fungsi untuk memeriksa apakah list induk kosong
bool ListEmpty(listinduk L) {
    return first(L) == Nil;
}

// Fungsi untuk memeriksa apakah list anak kosong
bool ListEmptyAnak(listanak L) {
    return first(L) == Nil;
}

// Membuat list induk kosong
void CreateList(listinduk &L) {
    first(L) = Nil;
    last(L) = Nil;
}

// Membuat list anak kosong
void CreateListAnak(listanak &L) {
    first(L) = Nil;
    last(L) = Nil;
}

// Alokasi elemen induk
address alokasi(infotypeinduk P) {
    address newEl = new elemen_list_induk;
    if (newEl != Nil) {
        info(newEl) = P;
        next(newEl) = Nil;
        prev(newEl) = Nil;
        CreateListAnak(newEl->lanak); // Membuat list anak kosong
    }
    return newEl;
}

// Alokasi elemen anak
address_anak alokasiAnak(infotypeanak P) {
    address_anak newEl = new elemen_list_anak;
    if (newEl != Nil) {
        info(newEl) = P;
        next(newEl) = Nil;
        prev(newEl) = Nil;
    }
    return newEl;
}

// Dealokasi elemen induk
void dealokasi(address P) {
    delete P;
}

// Dealokasi elemen anak
void dealokasiAnak(address_anak P) {
    delete P;
}

// Menambahkan elemen di awal list induk
void insertFirst(listinduk &L, address P) {
    if (ListEmpty(L)) {
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

// Menambahkan elemen di akhir list induk
void insertLast(listinduk &L, address P) {
    if (ListEmpty(L)) {
        insertFirst(L, P);
    } else {
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}

// Menambahkan elemen di awal list anak
void insertFirstAnak(listanak &L, address_anak P) {
    if (ListEmptyAnak(L)) {
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

// Menambahkan elemen di akhir list anak
void insertLastAnak(listanak &L, address_anak P) {
    if (ListEmptyAnak(L)) {
        insertFirstAnak(L, P);
    } else {
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}

// Menampilkan isi list induk
void printInfo(listinduk L) {
    address P = first(L);
    while (P != Nil) {
        cout << "Induk: " << info(P) << endl;
        cout << "Anak-anak:" << endl;

        address_anak Q = first(P->lanak);
        while (Q != Nil) {
            cout << "- " << info(Q) << endl;
            Q = next(Q);
        }
        P = next(P);
    }
}
