#include <iostream>
#include <stack>
using namespace std;

void reverseSentence(const string &sentence) {
    stack<char> charStack;

    // Menyimpan setiap karakter dalam stack
    for (char ch : sentence) {
        charStack.push(ch);
    }

    cout << "Data setelah pembalikan: ";
    // Mengeluarkan karakter dari stack untuk membalikkan urutan
    while (!charStack.empty()) {
        cout << charStack.top(); // Menampilkan karakter teratas
        charStack.pop(); // Menghapus karakter teratas
    }
    cout << endl;
}

int main() {
    string input;

    cout << "Masukkan kalimat : ";
    getline(cin, input); // Membaca kalimat dari pengguna

    // Memastikan input tidak kosong
    if (input.empty()) {
        cout << "Kalimat tidak boleh kosong." << endl;
        return 1;
    }

    reverseSentence(input); // Memanggil fungsi untuk membalikkan kalimat

    return 0;
}
