#ifndef CIRCULARLIST_H_INCLUDED
#define CIRCULARLIST_H_INCLUDED

#include <string>
using namespace std;

struct infotype {
    string nama;
    string nim;
    char jenis_kelamin;
    float ipk;
};

struct ElmList {
    infotype info;
    ElmList *next; // Pointer ke elemen berikutnya
    ElmList *prev; // Pointer ke elemen sebelumnya
};

typedef struct ElmList *address;

struct List {
    address first;
};

/* Prototipe fungsi/prosedur */
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertFirst(List &L, address P);
void insertAfter(List &L, address Prec, address P);
void insertLast(List &L, address P);
void deleteFirst(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
void deleteLast(List &L, address &P);
address findElm(List L, infotype x);
void printInfo(List L);

address createData(string nama, string nim, char jenis_kelamin, float ipk);

#endif
