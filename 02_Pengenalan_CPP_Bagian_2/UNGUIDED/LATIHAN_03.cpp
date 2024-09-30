#include <iostream>

using namespace std;

int main() {
    int n, pilihan;
    float max, min, sum = 0, rata_rata;

    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    float arr[n];

    cout << "Masukkan nilai-nilai elemen array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    do {
        cout << "\nMenu:\n";
        cout << "1. Cari nilai maksimum\n";
        cout << "2. Cari nilai minimum\n";
        cout << "3. Hitung rata-rata\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                // Mencari nilai maksimum
                max = arr[0];
                for (int i = 1; i < n; i++) {
                    if (arr[i] > max) {
                        max = arr[i];
                    }
                }
                cout << "Nilai maksimum: " << max << endl;
                break;

            case 2:
                // Mencari nilai minimum
                min = arr[0];
                for (int i = 1; i < n; i++) {
                    if (arr[i] < min) {
                        min = arr[i];
                    }
                }
                cout << "Nilai minimum: " << min << endl;
                break;

            case 3:
                // Menghitung rata-rata
                for (int i = 0; i < n; i++) {
                    sum += arr[i];
                }
                rata_rata = sum / n;
                cout << "Nilai rata-rata: " << rata_rata << endl;
                break;

            case 4:
                cout << "Terima kasih!" << endl;
                break;

            default:
                cout << "Pilihan tidak valid. Silakan pilih menu yang tersedia." << endl;
        }
    } while (pilihan != 4);

    return 0;
}