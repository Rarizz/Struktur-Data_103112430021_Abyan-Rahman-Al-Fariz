// #include <iostream>
// using namespace std;

// /*Mendeklarasikan prototype fungsi */
// int maks3(int a, int b, int c);
 
// int main(){
//     int x,y,z;
//     cout<<"masukkan nilai bilangan ke-1 =";
//     cin>>x;
//     cout<<"masukkan nilai bilangan ke-2 =";
//     cin>>y;
//     cout<<"masukkan nilai bilangan ke-3 =";
//     cin>>z;
//     cout<<"nilai maksimumnya adalah ="
//         <<maks3(x,y,z);
//     return 0;
// }

// /*badan fungsi */
// int maks3(int a, int b, int c){
// /* deklarasi variabel lokal dalam fungsi */
//     int temp_max = a;
//     if(b > temp_max)
//         temp_max = b;
//     if(c > temp_max)
//         temp_max = c;
//     return (temp_max);
// }

#include <iostream>
using namespace std;

//Prototype prosedur
void tulis(int x);

int main(){
    int jum;
    cout << "Jumlah baris kata = ";
    cin >> jum;
    tulis(jum);
    return 0;
}

//Badan prosedur
void tulis(int x){
    for (int i = 0; i < x; i++){
        cout << "Baris ke-" << i + 1 << endl;
    }
}