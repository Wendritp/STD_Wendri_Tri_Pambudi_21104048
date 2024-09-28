#include <iostream>
#include <string>

using namespace std;

int main() {
    int angka;
    string satuan[] = {"nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
    string belasan[] = {"sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", "enam belas",
                        "tujuh belas", "delapan belas", "sembilan belas"};
    string puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh", "lima puluh",
                        "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};

    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    //kondisional
    if (angka >= 0 && angka <= 100) {
        if (angka < 10) {
            cout << satuan[angka] << endl;
        } else if (angka < 20) {
            cout << belasan[angka - 11] << endl;
        } else if (angka == 100) {
            cout << "seratus" << endl;
        } else {
            int puluhanAngka = angka / 10;
            int satuanAngka = angka % 10;
            cout << puluhan[puluhanAngka];
            if (satuanAngka != 0) {
                cout << " " << satuan[satuanAngka];
            }
            cout << endl;
        }
    } else {
        cout << "Angka harus antara 0 hingga 100" << endl;
    }

    return 0;
}
