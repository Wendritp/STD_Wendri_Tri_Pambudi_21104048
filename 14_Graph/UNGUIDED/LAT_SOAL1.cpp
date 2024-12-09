#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    int vertices;
    cout << "Silakan masukkan jumlah simpul: ";
    cin >> vertices;

    vector<string> cityNames(vertices);
    for (int i = 0; i < vertices; ++i) {
        cout << "Silakan masukkan nama simpul " << i + 1 << ": ";
        cin >> cityNames[i];
    }

    vector<vector<int>> adjMatrix(vertices, vector<int>(vertices, 0));

    cout << "Silakan masukkan bobot antar simpul:" << endl;
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            cout << cityNames[i] << " --> " << cityNames[j] << ": ";
            cin >> adjMatrix[i][j];
        }
    }

    cout << setw(10) << " ";
    for (const auto &name : cityNames) {
        cout << setw(10) << name;
    }
    cout << endl;

    for (int i = 0; i < vertices; ++i) {
        cout << setw(10) << cityNames[i];
        for (int j = 0; j < vertices; ++j) {
            cout << setw(10) << adjMatrix[i][j];
        }
        cout << endl;
    }

    return 0;
}
