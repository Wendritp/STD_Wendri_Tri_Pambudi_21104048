#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

int isFull(){
    return top == maksimal;
}

int isEmpthy(){
    return top == 0;
}

void cetakArrayBuku() {
    if (isEmpthy()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

void pushArrayBuku(string data){
    if(isFull()){
        cout << "Data Stack Penuh" << endl;
    }else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku(){
    if(isEmpthy()){
        cout << "Tidak ada data yang dihapus" << endl;
    }else {
        arrayBuku[top-1] = " ";
        top--;
    }
}

void peekArrayBuku(int posisi){
    if(isEmpthy()){
        cout << "Tidak ada data yang bisa dilihat" << endl;
    }else {
        int index = top - posisi;
        if (index > 0 && index < top){
            cout << "Data pada posisi ke-" << posisi << " adalah " << arrayBuku[index] << endl;
        }else {
            cout << "Posisi Diluar jangkauan" << endl;
        }
    }
}

int countStack(){
    return top;
}

void changeArrayBuku(int posisi, string data){
    int index = top - posisi;
    if(index > 0 && index < top){
        arrayBuku[index] = data;
    }else {
        cout << "Posisi Melebihi data yang ada" << endl;
    }
}

void destroyArrayBuku(){
    for(int i = 0; i < maksimal; i++){
        arrayBuku[i] = " ";
    }
    for (int i = top - 1; i >= 0; i--){
        cout << arrayBuku[i] << endl;
    }
}

int main(){ 
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n" < <endl;

    cout << "Apakah data stack penuh>" << (isFull() ? "Ya" : "Tidak") << endl;
    cout << "Apakah data stack kosong>" << (isEmpthy() ? "Ya" : "Tidak") << endl;

    peekArrayBuku(2);
    popArrayBuku();

    cout << "Banyaknya Data = " << countStack() << endl;

    changeArrayBuku(2, "Bahasa jerman");
    cetakArrayBuku();
    cout << "\n" << endl;

    destroyArrayBuku();
    cout << "Top Setelah Destroy = " << top << endl;
    cetakArrayBuku();

    return 0;

}