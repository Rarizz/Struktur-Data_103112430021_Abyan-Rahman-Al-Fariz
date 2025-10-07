#include <iostream>
using namespace std;

void cetakPola(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Masukkan sebuah bilangan bulat n: ";
    cin >> n;
    cetakPola(n);
    return 0;
}