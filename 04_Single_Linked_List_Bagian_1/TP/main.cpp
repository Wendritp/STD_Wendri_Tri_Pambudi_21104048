#include <iostream>
#include "list.h"
using namespace std;

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