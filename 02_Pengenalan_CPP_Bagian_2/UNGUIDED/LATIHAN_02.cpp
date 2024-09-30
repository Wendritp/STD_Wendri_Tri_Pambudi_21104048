#include <iostream>

using namespace std;

int main() {
    int dimensi1, dimensi2, dimensi3;

    cout << "Masukkan dimensi pertama: ";
    cin >> dimensi1;
    cout << "Masukkan dimensi kedua: ";
    cin >> dimensi2;
    cout << "Masukkan dimensi ketiga: ";
    cin >> dimensi3;

    int array3D[dimensi1][dimensi2][dimensi3];

    cout << "Masukkan nilai-nilai elemen array:\n";
    for (int i = 0; i < dimensi1; i++) {
        for (int j = 0; j < dimensi2; j++) {
            for (int k = 0; k < dimensi3; k++) {
                cout << "Elemen [" << i << "][" << j << "][" << k << "]: ";
                cin >> array3D[i][j][k];
            }
        }
    }

    // Menampilkan semua elemen array
    cout << "\nElemen-elemen array:\n";
    for (int i = 0; i < dimensi1; i++) {
        for (int j = 0; j < dimensi2; j++) {
            for (int k = 0; k < dimensi3; k++) {
                cout << array3D[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}