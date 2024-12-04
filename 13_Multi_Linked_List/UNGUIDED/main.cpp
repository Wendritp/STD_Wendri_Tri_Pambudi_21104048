#include "circularlist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    createList(L); // Membuat list kosong

    cout << "Coba insert first, last, dan after" << endl;

    // Menambahkan elemen ke dalam list
    address P1 = createData("Danu", "04", 'L', 4.0f);
    insertFirst(L, P1);

    P1 = createData("Fahmi", "06", 'L', 3.45f);
    insertLast(L, P1);

    P1 = createData("Bobi", "02", 'L', 3.71f);
    insertFirst(L, P1);

    P1 = createData("Ali", "01", 'L', 3.3f);
    insertFirst(L, P1);

    P1 = createData("Gita", "07", 'P', 3.75f);
    insertLast(L, P1);

    // Menambahkan elemen menggunakan insertAfter
    infotype x;
    x.nim = "07";
    P1 = findElm(L, x);
    address P2 = createData("Cindi", "03", 'P', 3.5f);
    insertAfter(L, P1, P2);

    x.nim = "02";
    P1 = findElm(L, x);
    P2 = createData("Hilmi", "08", 'P', 3.3f);
    insertAfter(L, P1, P2);

    x.nim = "04";
    P1 = findElm(L, x);
    P2 = createData("Eli", "05", 'P', 3.4f);
    insertAfter(L, P1, P2);

    // Menampilkan elemen-elemen di dalam list
    printInfo(L);

    return 0;
}
