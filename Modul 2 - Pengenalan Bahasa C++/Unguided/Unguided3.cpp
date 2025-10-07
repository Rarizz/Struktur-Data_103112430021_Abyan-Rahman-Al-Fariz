#include <iostream>
using namespace std;

float rataKelas(float data[], int jumlah) {
    float total = 0;
    for (int i = 0; i < jumlah; i++) {
        total += data[i];
    }
    return total / jumlah;
}

void nilaiEkstrim(float data[], int jumlah, float &maks, float &min) {
    maks = data[0];
    min = data[0];

    for (int i = 1; i < jumlah; i++) {
        if (data[i] > maks)
            maks = data[i];
        if (data[i] < min)
            min = data[i];
    }
}

int main() {
    int n;
    cout << "Input jumlah siswa: ";
    cin >> n;

    float nilai[n];
    cout << "\nMasukkan nilai ujian setiap siswa:\n";
    for (int i = 0; i < n; i++) {
        cout << "Siswa ke-" << i + 1 << " = ";
        cin >> nilai[i];
    }

    float rata = rataKelas(nilai, n);
    float tertinggi, terendah;
    nilaiEkstrim(nilai, n, tertinggi, terendah);

    cout << "\n=== HASIL REKAP NILAI ===" << endl;
    cout << "Rata-rata kelas  : " << rata << endl;
    cout << "Nilai tertinggi  : " << tertinggi << endl;
    cout << "Nilai terendah   : " << terendah << endl;

    return 0;
}
