#include <iostream>
#include <conio.h>

using namespace std;

// Prototipe fungsi untuk menukar nilai dua variabel
void tukar(int &x, int &y);

int main() {
    system("cls"); // Membersihkan layar
    int a = 4, b = 6;

    cout << "Kondisi sebelum ditukar:\n";
    cout << "a = " << a << " b = " << b << endl;

    tukar(a, b); // Memanggil fungsi tukar untuk menukar nilai a dan b

    cout << "Kondisi setelah ditukar:\n";
    cout << "a = " << a << " b = " << b << endl;

    getch(); // Menunggu input dari pengguna
    return 0;
}

// Fungsi untuk menukar nilai dua variabel
void tukar(int &x, int &y) {
    int temp;

    temp = x;
    x = y;
    y = temp;

    cout << "Nilai akhir pada fungsi tukar:\n";
    cout << "x = " << x << " y = " << y << endl;
}