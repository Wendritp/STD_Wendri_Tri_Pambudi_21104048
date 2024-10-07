#include <iostream>
using namespace std;

int main() {
    int var = 21104048;
    int* ptr;

    ptr = &var;

    cout << "Nilai dari var: " << var << endl;
    cout << "Alamat memori var: " << ptr << endl;
    cout << "Nilai yang ditunjuk oleh pointer: " << *ptr << endl;

    return 0;
}
