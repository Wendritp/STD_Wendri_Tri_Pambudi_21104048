#ifndef MULTILIST_H_INCLUDED
#define MULTILIST_H_INCLUDED

#include <stdio.h>

#define Nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define first(L) ((L).first)
#define last(L) ((L).last)

typedef int infotypeanak;
typedef int infotypeinduk;

typedef struct elemen_list_induk *address;
typedef struct elemen_list_anak *address_anak;

/* Struct untuk elemen anak */
struct elemen_list_anak {
    infotypeanak info;
    address_anak next;
    address_anak prev;
};

/* Struct untuk list anak */
struct listanak {
    address_anak first;
    address_anak last;
};

/* Struct untuk elemen induk */
struct elemen_list_induk {
    infotypeinduk info;
    listanak lanak;
    address next;
    address prev;
};

/* Struct untuk list induk */
struct listinduk {
    address first;
    address last;
};

/* Pengecekan apakah list kosong */
bool ListEmpty(listinduk L);
/* Mengembalikan true jika list induk kosong */

bool ListEmptyAnak(listanak L);
/* Mengembalikan true jika list anak kosong */

/* Pembuatan list kosong */
void CreateList(listinduk &L);
/* Membuat list induk kosong */

void CreateListAnak(listanak &L);
/* Membuat list anak kosong */

/* Manajemen memori */
address alokasi(infotypeinduk P);
/* Mengirimkan address dari alokasi elemen induk */

address_anak alokasiAnak(infotypeanak P);
/* Mengirimkan address dari alokasi elemen anak */

void dealokasi(address P);
/* Mengembalikan memori elemen induk ke sistem */

void dealokasiAnak(address_anak P);
/* Mengembalikan memori elemen anak ke sistem */

/* Pencarian elemen list */
address findElm(listinduk L, infotypeinduk X);
/* Mencari elemen list dengan info(P) = X */

address_anak findElm(listanak Lanak, infotypeanak X);
/* Mencari elemen list anak dengan info(P) = X */

bool fFindElm(listinduk L, address P);
/* Mengecek apakah ada elemen list dengan alamat P */

bool fFindElmanak(listanak Lanak, address_anak P);
/* Mengecek apakah ada elemen list anak dengan alamat P */

address findBefore(listinduk L, address P);
/* Mengembalikan alamat elemen sebelum P */

address_anak findBeforeAnak(listanak Lanak, infotypeinduk X, address_anak P);
/* Mengembalikan alamat elemen anak sebelum P */

/* Penambahan elemen */
void insertFirst(listinduk &L, address P);
/* Menambahkan elemen di awal list induk */

void insertAfter(listinduk &L, address P, address Prec);
/* Menambahkan elemen setelah Prec di list induk */

void insertLast(listinduk &L, address P);
/* Menambahkan elemen di akhir list induk */

void insertFirstAnak(listanak &L, address_anak P);
/* Menambahkan elemen di awal list anak */

void insertAfterAnak(listanak &L, address_anak P, address_anak Prec);
/* Menambahkan elemen setelah Prec di list anak */

void insertLastAnak(listanak &L, address_anak P);
/* Menambahkan elemen di akhir list anak */

/* Penghapusan elemen */
void delFirst(listinduk &L, address &P);
/* Menghapus elemen pertama di list induk */

void delLast(listinduk &L, address &P);
/* Menghapus elemen terakhir di list induk */

void delAfter(listinduk &L, address &P, address Prec);
/* Menghapus elemen setelah Prec di list induk */

void delP(listinduk &L, infotypeinduk X);
/* Menghapus elemen dengan info(P) = X di list induk */

void delFirstAnak(listanak &L, address_anak &P);
/* Menghapus elemen pertama di list anak */

void delLastAnak(listanak &L, address_anak &P);
/* Menghapus elemen terakhir di list anak */

void delAfterAnak(listanak &L, address_anak &P, address_anak Prec);
/* Menghapus elemen setelah Prec di list anak */

void delPAnak(listanak &L, infotypeanak X);
/* Menghapus elemen dengan info(P) = X di list anak */

/* Proses semua elemen list */
void printInfo(listinduk L);
/* Menampilkan semua info di list induk */

int nbList(listinduk L);
/* Mengembalikan jumlah elemen di list induk */

void printInfoAnak(listanak Lanak);
/* Menampilkan semua info di list anak */

int nbListAnak(listanak Lanak);
/* Mengembalikan jumlah elemen di list anak */

/* Proses terhadap list */
void delAll(listinduk &L);
/* Menghapus semua elemen di list induk */

#endif
