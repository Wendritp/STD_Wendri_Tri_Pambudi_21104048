#include <iostream>
#include <vector>
using namespace std;

int main() {
    int vertices, edges;
    cout << "Masukkan jumlah simpul: ";
    cin >> vertices;

    cout << "Masukkan jumlah sisi: ";
    cin >> edges;

    vector<vector<int>> adjMatrix(vertices, vector<int>(vertices, 0));

    for (int i = 0; i < edges; ++i) {
        int u, v;
        cout << "Masukkan pasangan simpul (simpul1 simpul2): ";
        cin >> u >> v;
        --u; // Menyesuaikan indeks menjadi 0-based
        --v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // Karena graf tidak berarah
    }

    cout << "Adjacency Matrix:" << endl;
    for (const auto &row : adjMatrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
