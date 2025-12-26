#ifndef MULTILIST_H_INCLUDED
#define MULTILIST_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nim;
    string nama;
};

typedef Mahasiswa infotypeMhs;

struct ElmMhs {
    infotypeMhs info;
    ElmMhs *nextMhs;
};

typedef ElmMhs* adrMhs;


struct Jurusan {
    string kode;
    string nama;
};

typedef Jurusan infotypeJur;

struct ElmJur {
    infotypeJur info;
    adrMhs firstMhs;  
    ElmJur *nextJur;
};

typedef ElmJur* adrJur;

struct ListJurusan {
    adrJur firstJur;
};


void createListJurusan(ListJurusan &L);

adrJur alokasiJur(infotypeJur x);
adrMhs alokasiMhs(infotypeMhs x);

void insertJurusan(ListJurusan &L, adrJur P);
void insertMahasiswa(adrJur PJur, adrMhs PMhs);

adrJur findJurusan(ListJurusan L, string kode);
adrMhs findMahasiswa(adrJur PJur, string nim);

void printData(ListJurusan L);

#endif
