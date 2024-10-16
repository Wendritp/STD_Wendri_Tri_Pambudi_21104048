#include <iostream>
#include "list.h"
using namespace std;

void createList (List &L) {
    first(L)= NULL;
}

address allocate(infotype x){
    address p = new elmlist;
    info(p) = x;
    next(p) = NULL;

    return p; 
}

void insertFirst(List &L, address P){
    next(P) = first(L);
    first(L) = P;
}

void printInfo (List L){
    address p = first(L);
    while (p != NULL){
        cout << info(p) << ", ";
        p = next(p);
    } 
    cout << endl;
}


void insertLast(List &L, address P) {
    if (first(L) == NULL) {
        first(L) = P;
    } else {
        address last = first(L);
        while (next(last) != NULL) {
            last = next(last);
        }
        next(last) = P;
    }
}

//tambahan procedure
void insertAfter(address Prec, address P) {
    if (Prec != NULL) {
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

void deleteLast(List &L, address &P) {
    if (first(L) == NULL) {
        P = NULL;
    } else if (next(first(L)) == NULL) { 
        P = first(L);
        first(L) = NULL;
    } else {
        address last = first(L);
        address prevLast = NULL;
        while (next(last) != NULL) {
            prevLast = last;
            last = next(last);
        }
        P = last;
        next(prevLast) = NULL;
    }
}

void deleteAfter(address Prec, address &P) {
    if (Prec != NULL && next(Prec) != NULL) {
        P = next(Prec);
        next(Prec) = next(next(Prec));
    }
}

address searchInfo(List L, infotype x) {
    address p = first(L);
    while (p != NULL) {
        if (info(p) == x) {
            return p;
        }
        p = next(p);
    }
    return NULL; 
}


// int main() {
//     List L;
//     createList(L);  // 1. Panggil createList

//     int input; // Variabel untuk input angka dari user
//     address p;
    
//     // 2. Menanyakan angka pertama dari user
//     cout << "Masukkan angka pertama: ";
//     cin >> input;
//     // 3. Panggil fungsi allocate agar data tersebut disajikan elemen
//     p = allocate(input);
//     // 4. Panggil prosedur insertFirst untuk memasukkan elemen ke list
//     insertFirst(L, p);
//     // 5. Panggil prosedur printInfo untuk menampilkan isi list
//     printInfo(L);

//     // 6. Menanyakan angka kedua dari user
//     cout << "Masukkan angka kedua: ";
//     cin >> input;
//     p = allocate(input);
//     insertFirst(L, p);
//     printInfo(L);

//     // 7. Menanyakan angka ketiga dari user
//     cout << "Masukkan angka ketiga: ";
//     cin >> input;
//     p = allocate(input);
//     insertFirst(L, p);
//     printInfo(L);

//     return 0;
// }

//SESI HAVE FUN
int main() {
    List L;
    createList(L);

    int digit;
    address p;
    cout << "Masukkan NIM perdigit\n";

    for (int i = 1; i <= 10; i++) {
        cout << "Digit " << i << ": ";
        cin >> digit;

        p = allocate(digit);

        insertLast(L, p);
    }

    cout << "Isi list : ";
    printInfo(L);

    return 0;
}