#include "Doublylist.h"
#include "Doublylist.cpp"
#include <iostream>

using namespace std;

int main() {
    List L;
    CreateList(L);

    infotype x;
    address P;

    for (int i = 0; i < 4; i++) {
        cout << "Masukkan Nomor Polisi : ";
        cin >> x.nopol;

        infotype temp;
        temp.nopol = x.nopol;

        if (findElm(L, temp) != NULL) {
            cout << "Nomor polisi sudah terdaftar\n\n";
            continue;
        }

        cout << "Masukkan Warna Kendaraan : ";
        cin >> x.warna;
        cout << "Masukkan Tahun Kendaraan : ";
        cin >> x.thnBuat;
        cout << endl;

        P = alokasi(x);
        insertLast(L, P);
    }

    cout << endl;
    printInfo(L);

    infotype cari;
    cout << "Masukkan Nomor Polisi yang dicari : ";
    cin >> cari.nopol;

    address found = findElm(L, cari);
    if (found != NULL) {
        cout << endl;
        cout << "Nomor Polisi : " << found->info.nopol << endl;
        cout << "Warna        : " << found->info.warna << endl;
        cout << "Tahun        : " << found->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }

    cout << endl;

    infotype hapus;
    cout << "Masukkan Nomor Polisi yang akan dihapus : ";
    cin >> hapus.nopol;

    address del = findElm(L, hapus);
    if (del != NULL) {
        if (del == L.First) {
            deleteFirst(L, del);
        } else if (del == L.Last) {
            deleteLast(L, del);
        } else {
            deleteAfter(del->prev, del);
        }
        cout << "Data dengan nomor polisi " << hapus.nopol << " berhasil dihapus." << endl;
        dealokasi(del);
    } else {
        cout << "Data tidak ditemukan." << endl;
    }

    cout << endl;
    printInfo(L);

    return 0;
}
