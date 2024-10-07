#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED

#include <string>
using namespace std;

struct Pelajaran {
    string namaMapel;
    string kodeMapel;
};


Pelajaran create_pelajaran(string namaMapel, string kodeMapel);


void tampil_pelajaran(const Pelajaran& pel);

#endif
