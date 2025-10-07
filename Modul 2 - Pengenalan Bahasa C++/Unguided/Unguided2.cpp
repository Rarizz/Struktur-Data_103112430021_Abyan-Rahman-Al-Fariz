#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Input jumlah elemen array: ";
    cin >> n;

    int *data = new int[n]; 

    cout << "\nMasukkan " << n << " nilai bilangan bulat:\n";
    for (int i = 0; i < n; i++) {
        cout << "Data ke-" << i + 1 << ": ";
        cin >> *(data + i); 
    }

    int total = 0;
    int maksimum = *data;
    int minimum = *data;

    for (int i = 0; i < n; i++) {
        int nilai = *(data + i);
        total += nilai;
        if (nilai > maksimum)
            maksimum = nilai;
        if (nilai < minimum)
            minimum = nilai;
    }

    cout << "\n=== HASIL PERHITUNGAN ===\n";
    cout << "Total nilai     : " << total << endl;
    cout << "Nilai maksimum  : " << maksimum << endl;
    cout << "Nilai minimum   : " << minimum << endl;

    delete[] data; 

    return 0;
}