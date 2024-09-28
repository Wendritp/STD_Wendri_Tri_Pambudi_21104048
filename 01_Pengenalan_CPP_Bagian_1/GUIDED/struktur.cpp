#include <iostream>
#include <conio.h>
#define MAX 5
using namespace std;

int main(){
    int i;
    struct data{
    char nama[40];
    int nilai;
    };
    data siswa[MAX];
    for(i=0; i<MAX; i++){
        cout<<"masukkan data ke- "<<i+1<<endl;
        cout<<"nama = ";
        cin>>siswa[i].nama;
        cout<<"nilai = ";
        cin>>siswa[i].nilai;
    }
    cout<<"\ndata siswa\n";
    cout<<"=======";
    for(i=0; i<MAX; i++){
        cout<<"\n\ndata ke-"<<i+1;
        cout<<"\n\nnama="<<siswa[i].nama;
        cout<<"\n\nnilai="<<siswa[i].nilai;
        }
    getch();
    return 0;
}
