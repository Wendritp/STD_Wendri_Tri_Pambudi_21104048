#include <iostream>
#include <cmath>

using namespace std;

class Kerucut {
private:
    double radius;
    double tinggi;

public:
    Kerucut(double r, double t) : radius(r), tinggi(t) {}

    double hitungVolume() {
        return (1.0 / 3.0) * M_PI * radius * radius * tinggi;
    }

    double hitungLuasPermukaan() {
        double garisPelukis = sqrt(radius * radius + tinggi * tinggi);
        return M_PI * radius * (radius + garisPelukis);
    }
};

int main() {
    double radius, tinggi;

    cout << "Masukkan jari-jari kerucut: ";
    cin >> radius;
    cout << "Masukkan tinggi kerucut: ";
    cin >> tinggi;

    Kerucut kerucut(radius, tinggi);

    double volume = kerucut.hitungVolume();
    double luasPermukaan = kerucut.hitungLuasPermukaan();

    cout << "Volume kerucut: " << volume << endl;
    cout << "Luas permukaan kerucut: " << luasPermukaan << endl;

    return 0;
}
