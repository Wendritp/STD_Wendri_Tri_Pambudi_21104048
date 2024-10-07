#include <iostream>
using namespace std;

void tampilArray2D(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarArray2D(int arr1[3][3], int arr2[3][3], int row, int col) {
    int temp = arr1[row][col];
    arr1[row][col] = arr2[row][col];
    arr2[row][col] = temp;
}

void tukarPointer(int* ptr1, int* ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    int array1[3][3] = {
        {2, 1, 1},
        {0, 4, 0},
        {4, 8, 0}
    };
    
    int array2[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int a = 11, b = 22;
    int* ptr1 = &a;
    int* ptr2 = &b;

    cout << "Array 1 sebelum pertukaran:" << endl;
    tampilArray2D(array1);

    cout << "\nArray 2 sebelum pertukaran:" << endl;
    tampilArray2D(array2);

    tukarArray2D(array1, array2, 1, 1);

    cout << "\nArray 1 setelah pertukaran elemen [1][1]:" << endl;
    tampilArray2D(array1);

    cout << "\nArray 2 setelah pertukaran elemen [1][1]:" << endl;
    tampilArray2D(array2);

    cout << "\nNilai sebelum pertukaran pointer:" << endl;
    cout << "Pointer 1 menunjuk ke nilai: " << *ptr1 << endl;
    cout << "Pointer 2 menunjuk ke nilai: " << *ptr2 << endl;

    tukarPointer(ptr1, ptr2);

    cout << "\nNilai setelah pertukaran pointer:" << endl;
    cout << "Pointer 1 menunjuk ke nilai: " << *ptr1 << endl;
    cout << "Pointer 2 menunjuk ke nilai: " << *ptr2 << endl;

    return 0;
}
