#include <iostream>
using namespace std;

/*deklarasi fungsi */
float ctof(float celcius);
int main(){
    float celcius, fahrenheit;
    cout<<"nilai celcius? ";
    cin>>celcius;
    /*hitung konversi*/
    fahrenheit = ctof(celcius);
    cout<<celcius<<" celcius adalah "
    <<"Fahrenheit ="<<fahrenheit<<endl;
    return 0;
}
/*pendefinisian fungsi*/
float ctof(float celcius){
    return celcius * 1.8 + 32;
}
