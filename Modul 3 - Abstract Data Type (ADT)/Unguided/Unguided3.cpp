#include <iostream>
using namespace std;

// Prosedur untuk menampilkan isi array 2D
void tampilArray(int data[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Prosedur untuk menukar isi dua array 2D pada posisi tertentu
void tukarElemen(int arrA[3][3], int arrB[3][3], int barisA, int kolomA, int barisB, int kolomB) {
    int temp = arrA[barisA][kolomA];
    arrA[barisA][kolomA] = arrB[barisB][kolomB];
    arrB[barisB][kolomB] = temp;
}

void tukarDataPointer(int *p1, int *p2) {
    int sementara = *p1;
    *p1 = *p2;
    *p2 = sementara;
}

int main() {
    int matriks1[3][3] = {
        {11, 12, 13},
        {14, 15, 16},
        {17, 18, 19}
    };
    int matriks2[3][3] = {
        {91, 92, 93},
        {94, 95, 96},
        {97, 98, 99}
    };

    cout << "=== Matriks 1 (Awal) ===" << endl;
    tampilArray(matriks1);
    cout << "=== Matriks 2 (Awal) ===" << endl;
    tampilArray(matriks2);

    tukarElemen(matriks1, matriks2, 0, 1, 2, 2);

    cout << "=== Setelah Penukaran Elemen ===" << endl;
    cout << "Matriks 1:" << endl;
    tampilArray(matriks1);
    cout << "Matriks 2:" << endl;
    tampilArray(matriks2);


    int x = 50, y = 100;
    int *ptrX = &x;
    int *ptrY = &y;

    cout << "Sebelum tukar pointer: x = " << x << ", y = " << y << endl;
    tukarDataPointer(ptrX, ptrY);
    cout << "Sesudah tukar pointer: x = " << x << ", y = " << y << endl;

    return 0;
}
