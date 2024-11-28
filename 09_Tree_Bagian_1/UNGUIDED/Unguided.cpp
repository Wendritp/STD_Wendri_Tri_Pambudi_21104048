#include <iostream>
#include <limits>

using namespace std;

// Struktur pohon
struct Pohon {
    char data;
    Pohon *left, *right, *parent;
};

Pohon *root, *baru;

// Inisiasi
void init() {
    root = NULL;
}

// Cek Node
bool isEmpty() {
    return root == NULL;
}

// Buat node baru
void buatNode(char data) {
    if (isEmpty()) {
        root = new Pohon{data, NULL, NULL, NULL};
        cout << "Node " << data << " berhasil menjadi Root" << endl;
    } else {
        cout << "Pohon sudah dibuat." << endl;
    }
}

// Tambah node kiri
Pohon *insertLeft(char data, Pohon *Node) {
    if (isEmpty()) {
        cout << "Pohon belum dibuat" << endl;
        return NULL;
    }
    if (Node->left != NULL) {
        cout << "Node " << Node->data << " sudah memiliki child kiri!" << endl;
        return NULL;
    }
    baru = new Pohon{data, NULL, NULL, Node};
    Node->left = baru;
    cout << "Node " << data << " berhasil ditambahkan di kiri " << Node->data << endl;
    return baru;
}

// Tambah node kanan
Pohon *insertRight(char data, Pohon *Node) {
    if (isEmpty()) {
        cout << "Pohon belum dibuat" << endl;
        return NULL;
    }
    if (Node->right != NULL) {
        cout << "Node " << Node->data << " sudah memiliki child kanan!" << endl;
        return NULL;
    }
    baru = new Pohon{data, NULL, NULL, Node};
    Node->right = baru;
    cout << "Node " << data << " berhasil ditambahkan di kanan " << Node->data << endl;
    return baru;
}

// Fungsi untuk menampilkan child dan descendant dari node
void tampilDescendant(Pohon *Node) {
    if (!Node) {
        cout << "Node tidak ditemukan" << endl;
        return;
    }
    cout << "Descendant dari Node " << Node->data << ": ";
    if (Node->left) cout << Node->left->data << " ";
    if (Node->right) cout << Node->right->data << " ";
    if (!Node->left && !Node->right) cout << "(Tidak ada child)";
    cout << endl;
}

// Fungsi rekursif untuk memeriksa apakah pohon adalah BST  //SOAL 2
bool is_valid_bst(Pohon *node, char min_val = numeric_limits<char>::min(), char max_val = numeric_limits<char>::max()) {
    if (!node) return true;
    if (node->data <= min_val || node->data >= max_val) return false;
    return is_valid_bst(node->left, min_val, node->data) && is_valid_bst(node->right, node->data, max_val);
}

// Fungsi rekursif untuk menghitung jumlah simpul daun //SOAL 3
int cari_simpul_daun(Pohon *node) {
    if (!node) return 0;
    if (!node->left && !node->right) return 1;
    return cari_simpul_daun(node->left) + cari_simpul_daun(node->right);
}

// Menu utama //SOAL 1
void menu() {
    int pilihan;
    char data, parentData;
    Pohon *parentNode;
    do {
        cout << "\nMenu Binary Tree:\n";
        cout << "1. Buat Root\n";
        cout << "2. Tambah Node Kiri\n";
        cout << "3. Tambah Node Kanan\n";
        cout << "4. Tampilkan Descendant\n";
        cout << "5. Cek apakah BST\n";
        cout << "6. Hitung Simpul Daun\n";
        cout << "7. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan data Root: ";
                cin >> data;
                buatNode(data);
                break;
            case 2:
                cout << "Masukkan data Parent: ";
                cin >> parentData;
                parentNode = root; // Misalnya mencari Parent secara manual
                if (parentNode->data == parentData) {
                    cout << "Masukkan data untuk Node Kiri: ";
                    cin >> data;
                    insertLeft(data, parentNode);
                }
                break;
            case 3:
                cout << "Masukkan data Parent: ";
                cin >> parentData;
                parentNode = root; // Misalnya mencari Parent secara manual
                if (parentNode->data == parentData) {
                    cout << "Masukkan data untuk Node Kanan: ";
                    cin >> data;
                    insertRight(data, parentNode);
                }
                break;
            case 4:
                cout << "Masukkan data Node: ";
                cin >> data;
                tampilDescendant(root); // Demo untuk root
                break;
            case 5:
                cout << (is_valid_bst(root) ? "Pohon adalah BST" : "Pohon bukan BST") << endl;
                break;
            case 6:
                cout << "Jumlah Simpul Daun: " << cari_simpul_daun(root) << endl;
                break;
            case 7:
                cout << "Keluar dari program" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 7);
}

// Main
int main() {
    init();
    menu();
    return 0;
}
