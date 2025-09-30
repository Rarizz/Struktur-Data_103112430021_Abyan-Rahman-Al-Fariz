#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;

    cout << "input: ";
    cin >> n;

    cout << endl;

    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }

        for (int j = i; j >= 1; j--) {
            cout << j;
        }

        cout << "*";

        for (int j = 1; j <= i; j++) {
            cout << j;
        }

        cout << endl;
    }

    for (int j = 1; j <= n; j++) {
        cout << " ";
    }
    
    cout << "*" << endl;
}