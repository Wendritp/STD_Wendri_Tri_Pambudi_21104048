#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

bool isPalindrome(const string &input) {
    stack<char> charStack;
    string cleanedInput;

    // Membersihkan kalimat dengan mengabaikan spasi dan tanda baca
    for (char ch : input) {
        if (isalnum(ch)) { // Memeriksa apakah karakter adalah alfanumerik
            cleanedInput += tolower(ch); // Menambahkan ke cleanedInput dalam huruf kecil
            charStack.push(tolower(ch)); // Menyimpan karakter dalam stack
        }
    }

    // Membandingkan karakter dalam stack dengan cleanedInput
    int index = 0;
    while (!charStack.empty()) {
        if (charStack.top() != cleanedInput[index]) {
            return false; // Jika ada ketidakcocokan, bukan palindrom
        }
        charStack.pop();
        index++;
    }

    return true; // Jika semua karakter cocok, itu adalah palindrom
}

int main() {
    string input;
    cout << "Masukkan kalimat: ";
    getline(cin, input); // Menggunakan getline untuk membaca kalimat dengan spasi

    if (isPalindrome(input)) {
        cout << "Kalimat tersebut adalah palindrom." << endl;
    } else {
        cout << "Kalimat tersebut bukan palindrom." << endl;
    }

    return 0;
}
