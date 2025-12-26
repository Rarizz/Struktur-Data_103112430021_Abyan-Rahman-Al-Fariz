#include "multilist.h"

void createListJurusan(ListJurusan &L) {
    L.firstJur = NULL;
}

adrJur alokasiJur(infotypeJur x) {
    adrJur P = new ElmJur;
    P->info = x;
    P->nextJur = NULL;
    P->firstMhs = NULL;
    return P;
}

adrMhs alokasiMhs(infotypeMhs x) {
    adrMhs P = new ElmMhs;
    P->info = x;
    P->nextMhs = NULL;
    return P;
}

void insertJurusan(ListJurusan &L, adrJur P) {
    if (L.firstJur == NULL) {
        L.firstJur = P;
    } else {
        adrJur Q = L.firstJur;
        while (Q->nextJur != NULL) {
            Q = Q->nextJur;
        }
        Q->nextJur = P;
    }
}

void insertMahasiswa(adrJur PJur, adrMhs PMhs) {
    if (PJur != NULL) {
        if (PJur->firstMhs == NULL) {
            PJur->firstMhs = PMhs;
        } else {
            adrMhs Q = PJur->firstMhs;
            while (Q->nextMhs != NULL)
                Q = Q->nextMhs;
            Q->nextMhs = PMhs;
        }
    }
}

adrJur findJurusan(ListJurusan L, string kode) {
    adrJur P = L.firstJur;
    while (P != NULL) {
        if (P->info.kode == kode) return P;
        P = P->nextJur;
    }
    return NULL;
}

adrMhs findMahasiswa(adrJur PJur, string nim) {
    if (PJur == NULL) return NULL;

    adrMhs P = PJur->firstMhs;
    while (P != NULL) {
        if (P->info.nim == nim) return P;
        P = P->nextMhs;
    }
    return NULL;
}

void printData(ListJurusan L) {
    adrJur PJ = L.firstJur;
    cout << "\n===== DATA JURUSAN DAN MAHASISWA =====\n";

    while (PJ != NULL) {
        cout << "Jurusan: " << PJ->info.nama << " (" << PJ->info.kode << ")\n";

        adrMhs PM = PJ->firstMhs;
        if (PM == NULL) {
            cout << "   Tidak ada mahasiswa.\n";
        } else {
            while (PM != NULL) {
                cout << "   - " << PM->info.nim << " | " << PM->info.nama << endl;
                PM = PM->nextMhs;
            }
        }
        cout << endl;

        PJ = PJ->nextJur;
    }
}
