#include <iostream>
#include <conio.h>

#define MAX 5

using namespace std;

int main() {
    int i, j;
    float nilai[MAX], nilai_total, rata_rata;

    // Inisialisasi array dua dimensi secara statis
    static int nilai_tahun[MAX][MAX] = {
        {0, 2, 2, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 3, 3, 3, 0},
        {4, 4, 0, 0, 4},
        {5, 0, 0, 0, 5}
    };

    // Memasukkan nilai ke dalam array satu dimensi
    cout << "Masukkan nilai siswa:\n";
    for (i = 0; i < MAX; i++) {
        cout << "Nilai ke-" << i + 1 << ": ";
        cin >> nilai[i];
    }

    // Menampilkan nilai siswa
    cout << "\nData nilai siswa:\n";
    for (i = 0; i < MAX; i++) {
        cout << "Nilai ke-" << i + 1 << ": " << nilai[i] << endl;
    }

    // Menampilkan nilai tahunan (array dua dimensi)
    cout << "\nNilai tahunan:\n";
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            cout << nilai_tahun[i][j] << " ";
        }
        cout << endl;
    }

    getch();
    return 0;
}