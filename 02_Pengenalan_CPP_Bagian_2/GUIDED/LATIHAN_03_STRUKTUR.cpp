#include <conio.h>
#include <iostream>

using namespace std;

// Mendefinisikan prototipe fungsi maks3
int maks3(int a, int b, int c);

int main() {
    system("cls"); // Membersihkan layar
    int x, y, z;

    cout << "Masukkan nilai bilangan ke-1: ";
    cin >> x;
    cout << "Masukkan nilai bilangan ke-2: ";
    cin >> y;
    cout << "Masukkan nilai bilangan ke-3: ";
    cin >> z;

    cout << "Nilai maksimumnya adalah: " << maks3(x, y, z) << endl;

    getch(); // Menunggu input dari pengguna
    return 0;
}

// Fungsi untuk mencari nilai maksimum dari tiga bilangan
int maks3(int a, int b, int c) {
    int temp_max = a; // Asumsikan a adalah nilai maksimum sementara

    if (b > temp_max) {
        temp_max = b;
    }
    if (c > temp_max) {
        temp_max = c;
    }

    return temp_max;
}