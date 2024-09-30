#include <iostream>
#include <conio.h>
using namespace std;

int main(){
    int x, y; // deklarasi variabel x dan y bertipe int
    int *px; // px merupakan variabel pointer menunjuk ke variabel int

    x = 87;
    px = &x; // px menunjuk ke alamat memori x
    y = *px; // y diisi dengan nilai yang ditunjuk oleh px

    cout <<"Alamat memori x : " <<&x <<endl;
    cout <<"Isi px : " <<px <<endl;
    cout <<"Isi x : " <<x <<endl;
    cout <<"Nilai yang ditunjuk oleh px : " <<*px <<endl;
    cout <<"Nilai y : " <<y <<endl;
    getch();
    
    return 0;
}