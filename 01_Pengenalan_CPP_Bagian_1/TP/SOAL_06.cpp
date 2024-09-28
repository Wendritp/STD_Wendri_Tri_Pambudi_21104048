#include <iostream>

using namespace std;

int main() {
    int a, b;

    cout << "Masukkan batas bawah: ";
    cin >> a;

    cout << "Masukkan batas atas: ";
    cin >> b;

    for (int bilangan = a; bilangan <= b; bilangan++) {
        cout << "Bilangan " << bilangan << endl;
    }

    return 0;
}