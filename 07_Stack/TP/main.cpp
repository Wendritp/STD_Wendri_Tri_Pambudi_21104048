#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    stack S;
    createStack(S);

    int digitTerakhirNIM = 8;
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
