#include <iostream>
using namespace std;

int main() {
    string nama[5];
    float nilai[5][3];
    float rata[5];
    int terbaik = 0;

    cout << "=== Input Data Mahasiswa ===" << endl;

    // Input nama dan nilai mahasiswa
    for (int i = 0; i < 5; i++) {
        cout << "\nNama mahasiswa ke-" << i + 1 << ": ";
        cin >> nama[i];

        float total = 0;
        for (int j = 0; j < 3; j++) {
            cout << "  Masukkan nilai mata kuliah ke-" << j + 1 << ": ";
            cin >> nilai[i][j];
            total += nilai[i][j];
        }
        rata[i] = total / 3;
    }

    // Cari mahasiswa dengan rata-rata tertinggi
    for (int i = 1; i < 5; i++) {
        if (rata[i] > rata[terbaik]) {
            terbaik = i;
        }
    }

    // Tampilkan hasil akhir
    cout << "\n=== Daftar Nilai Mahasiswa ===" << endl;
    cout << "Nama\tNilai1\tNilai2\tNilai3\tRata-rata" << endl;

    for (int i = 0; i < 5; i++) {
        cout << nama[i] << "\t";
        for (int j = 0; j < 3; j++) {
            cout << nilai[i][j] << "\t";
        }
        cout << rata[i];
        if (i == terbaik) cout << "  <-- Terbaik";
        cout << endl;
    }

    cout << "\nMahasiswa dengan rata-rata tertinggi adalah: " 
         << nama[terbaik] << " (" << rata[terbaik] << ")" << endl;

    return 0;
}
