#include <iostream>

using namespace std;

int main() {
    float bilangan1, bilangan2;
    float hasil_penjumlahan, hasil_pengurangan, hasil_perkalian, hasil_pembagian;

    // Inputan
    cout << "Masukkan bilangan pertama: ";
    cin >> bilangan1;

    cout << "Masukkan bilangan kedua: ";
    cin >> bilangan2;

    // Rumus aritmatika
    hasil_penjumlahan = bilangan1 + bilangan2;
    hasil_pengurangan = bilangan1 - bilangan2;
    hasil_perkalian = bilangan1 * bilangan2;
    hasil_pembagian = bilangan1 / bilangan2;

    // Mencetak hasil
    cout << "Hasil penjumlahan: " << hasil_penjumlahan << endl;
    cout << "Hasil pengurangan: " << hasil_pengurangan << endl;
    cout << "Hasil perkalian: " << hasil_perkalian << endl;
    cout << "Hasil pembagian: " << hasil_pembagian << endl;

    return 0;
}
