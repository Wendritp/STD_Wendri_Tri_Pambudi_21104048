/* contoh penggunaan 'if' Bentuk 1 */
#include <iostream>
using namespace std;


// int main(){
//     double tot_pembelian, diskon;
//     cout<<"total pembelian: Rp";
//     cin>>tot_pembelian;
//     diskon = 0;
//     if(tot_pembelian >= 100000)
//         diskon = 0.05*tot_pembelian;
//     cout<<"besar diskon = Rp" <<diskon;
// }

/* contoh penggunaan 'if' Bentuk 2 */

// int main(){
//     double tot_pembelian, diskon;
//     cout<<"total pembelian: Rp";
//     cin>>tot_pembelian;
//     diskon = 0;
//     if(tot_pembelian >= 100000)
//         diskon = 0.05*tot_pembelian;
//     else
//         diskon = 0;
//     cout<<"besar diskon = Rp" <<diskon;
// }

/* contoh penggunaan 'if' Bentuk 3 */

#include <stdio.h>
int main(){
    int kode_hari;
    puts("Menentukan hari\n");
    puts("1=Senin 3=Rabu 5=Jumat 7=Minggu ");
    puts("2=Selasa 4=Kamis 6=Sabtu ");
    cin>>kode_hari;
    switch(kode_hari){
    case 1:
        puts("Hari Senin");
        break;
    case 2:
        puts("Hari Selasa");
        break;
    case 3:
        puts("Hari Rabu");
        break;
    case 4:
        puts("Hari Kamis");
        break;
    case 5:
        puts("Hari Jumat");
        break;
    case 6:
        puts("Hari Sabtu");
        break;
    case 7:
        puts("Hari Minggu");
        break;
    default:
        puts("Kode masukan salah!!!");
    }
    return 0;
}