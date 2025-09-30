#include <iostream>
using namespace std;

int main()
{
    int num;

    cout << "Masukkan angka (0-100): ";
    cin >> num;

    if (num < 0 || num > 100)
    {
        cout << "Angka tidak valid!" << endl;
    }
    else
    {
        string satuan[] = {"", "Satu", "Dua", "Tiga", "Empat", "Lima", "Enam", "Tujuh", "Delapan", "Sembilan"};
        string puluhan[] = {"", "", "Dua Puluh", "Tiga Puluh", "Empat Puluh", "Lima Puluh", "Enam Puluh", "Tujuh Puluh", "Delapan Puluh", "Sembilan Puluh"};

        if (num == 0)
        {
            cout << "Nol";
        }
        else if (num == 10)
        {
            cout << "Sepuluh";
        }
        else if (num >= 11 && num <= 19)
        {
            string belasan[] = {"", "Sebelas", "Dua Belas", "Tiga Belas", "Empat Belas", "Lima Belas", "Enam Belas", "Tujuh Belas", "Delapan Belas", "Sembilan Belas"};
            cout << belasan[num - 10];
        }
        else
        {
            if (num / 10 > 0)
            {
                cout << puluhan[num / 10] << " ";
            }

            if (num % 10 > 0)
            {
                cout << satuan[num % 10];
            }
        }
    }

    cout << endl;
}