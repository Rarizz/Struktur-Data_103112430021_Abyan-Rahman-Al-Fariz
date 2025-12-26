#include "circularlist.h"

void CreateList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    if (P != Nil) {
        delete P;
        P = Nil;
    }
}

void insertFirst(List &L, address P) {
    if (L.First == Nil) {
        L.First = P;
        P->next = P;
    } else {
        address last = L.First;
        while (last->next != L.First) last = last->next;
        P->next = L.First;
        last->next = P;
        L.First = P;
    }
}

void insertAfter(List &L, address Prec, address P) {
    if (Prec == Nil) return;
    P->next = Prec->next;
    Prec->next = P;
}

void insertLast(List &L, address P) {
    if (L.First == Nil) {
        insertFirst(L, P);
    } else {
        address last = L.First;
        while (last->next != L.First) last = last->next;
        last->next = P;
        P->next = L.First;
    }
}

void deleteFirst(List &L, address &P) {
    if (L.First == Nil) {
        P = Nil;
        return;
    }

    if (L.First->next == L.First) {
        P = L.First;
        L.First = Nil;
        P->next = Nil;
    } else {
        address last = L.First;
        while (last->next != L.First) last = last->next;
        P = L.First;
        L.First = P->next;
        last->next = L.First;
        P->next = Nil;
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec == Nil || L.First == Nil) {
        P = Nil;
        return;
    }
    P = Prec->next;
    if (P == Prec) {
        L.First = Nil;
        P->next = Nil;
    } else {
        Prec->next = P->next;
        if (P == L.First) {
            L.First = P->next;
        }
        P->next = Nil;
    }
}

void deleteLast(List &L, address &P) {
    if (L.First == Nil) {
        P = Nil;
        return;
    }
    if (L.First->next == L.First) {
        P = L.First;
        L.First = Nil;
        P->next = Nil;
    } else {
        address Q = L.First;
        while (Q->next->next != L.First) Q = Q->next;
        P = Q->next; // last
        Q->next = L.First;
        P->next = Nil;
    }
}

address findElm(List L, infotype x) {
    if (L.First == Nil) return Nil;
    address P = L.First;
    do {
        if (P->info.nim == x.nim) return P;
        P = P->next;
    } while (P != L.First);
    return Nil;
}

void printInfo(List L) {
    if (L.First == Nil) {
        cout << "List kosong.\n";
        return;
    }
    cout << "Daftar Mahasiswa:\n";
    address P = L.First;
    int idx = 1;
    do {
        cout << idx++ << ". ";
        cout << "Nama: " << P->info.nama << ", NIM: " << P->info.nim
             << ", JK: " << P->info.jenis_kelamin
             << ", IPK: " << P->info.ipk << '\n';
        P = P->next;
    } while (P != L.First);
}

address createData(string nama, string nim, char jenis_kelamin, float ipk) {
    infotype x;
    x.nama = nama;
    x.nim = nim;
    x.jenis_kelamin = jenis_kelamin;
    x.ipk = ipk;
    return alokasi(x);
}
