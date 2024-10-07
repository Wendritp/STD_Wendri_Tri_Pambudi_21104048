#include <iostream>
#include "pelajaran.h"

int main() {
    string namaMapel, kodeMapel;

    cout << "Masukkan nama mata pelajaran: ";
    getline(cin, namaMapel);
    cout << "Masukkan kode mata pelajaran: ";
    getline(cin, kodeMapel);

    Pelajaran pel = create_pelajaran(namaMapel, kodeMapel);

    cout << "\nData Mata Pelajaran:" << endl;
    tampil_pelajaran(pel);

    return 0;
}
