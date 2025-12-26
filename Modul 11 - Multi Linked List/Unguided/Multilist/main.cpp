    #include <iostream>
    #include "multilist.h"
    #include "multilist.cpp"
    using namespace std;

    int main() {
        ListJurusan L;
        createListJurusan(L);

        cout << "=== INPUT DATA JURUSAN ===" << endl;
        adrJur j1 = alokasiJur({"IF", "Informatika"});
        adrJur j2 = alokasiJur({"SI", "Sistem Informasi"});
        insertJurusan(L, j1);
        insertJurusan(L, j2);

        cout << "=== INPUT DATA MAHASISWA ===" << endl;
        insertMahasiswa(j1, alokasiMhs({"103112430001", "Abyan"}));
        insertMahasiswa(j1, alokasiMhs({"103112430021", "Fahmi"}));

        insertMahasiswa(j2, alokasiMhs({"103112410011", "Bintang"}));

        printData(L);

        cout << "\n=== CARI MAHASISWA ===" << endl;
        adrJur cariJur = findJurusan(L, "IF");
        adrMhs cariMhs = findMahasiswa(cariJur, "103112430001");

        if (cariMhs != NULL) {
            cout << "Mahasiswa ditemukan: " << cariMhs->info.nama << endl;
        } else {
            cout << "Mahasiswa tidak ditemukan!" << endl;
        }

        return 0;
    }
