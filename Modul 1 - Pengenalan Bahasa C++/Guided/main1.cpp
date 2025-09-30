#include <iostream>
using namespace std;

int main()
{

    int hari;
    cout << "Hari 1 - 7 : ";
    cin >> hari;

    if (hari == 7)
    {
        cout << "hari minggu" << endl;
    }
    else
    {
        cout << "hari kerja" << endl;
    }

    switch (hari)
    {
    case 7:
        cout << "hari minggu" << endl;
        break;

    default:
        cout << "hari kerja" << endl;
        break;
    }
}