#include <iostream>
#include "Playlist.h"
using namespace std;

void menu() {
    cout << "\n=== PROGRAM PLAYLIST LAGU ===" << endl;
    cout << "1. Tambah lagu di awal playlist" << endl;
    cout << "2. Tambah lagu di akhir playlist" << endl;
    cout << "3. Tambah lagu setelah lagu ke-3" << endl;
    cout << "4. Hapus lagu berdasarkan judul" << endl;
    cout << "5. Tampilkan seluruh playlist" << endl;
    cout << "6. Keluar" << endl;
    cout << "Pilih menu: ";
}

int main() {
    Playlist myPlaylist;
    createPlaylist(myPlaylist);
    
    int pilihan;
    string judul, penyanyi;
    float durasi;

    insertFirst(myPlaylist, alokasi("Bohemian Rhapsody", "Queen", 5.55));
    insertLast(myPlaylist, alokasi("Yesterday", "The Beatles", 2.05));
    insertLast(myPlaylist, alokasi("Hotel California", "Eagles", 6.30));
    
    do {
        menu();
        cin >> pilihan;
        cin.ignore(); 
        
        switch (pilihan) {
            case 1:
                cout << "\n--- Tambah Lagu di Awal ---" << endl;
                cout << "Judul: "; getline(cin, judul);
                cout << "Penyanyi: "; getline(cin, penyanyi);
                cout << "Durasi (menit): "; cin >> durasi;
                insertFirst(myPlaylist, alokasi(judul, penyanyi, durasi));
                cout << "Lagu berhasil ditambahkan di awal playlist!" << endl;
                break;
                
            case 2:
                cout << "\n--- Tambah Lagu di Akhir ---" << endl;
                cout << "Judul: "; getline(cin, judul);
                cout << "Penyanyi: "; getline(cin, penyanyi);
                cout << "Durasi (menit): "; cin >> durasi;
                insertLast(myPlaylist, alokasi(judul, penyanyi, durasi));
                cout << "Lagu berhasil ditambahkan di akhir playlist!" << endl;
                break;
                
            case 3:
                cout << "\n--- Tambah Lagu Setelah Lagu ke-3 ---" << endl;
                cout << "Judul: "; getline(cin, judul);
                cout << "Penyanyi: "; getline(cin, penyanyi);
                cout << "Durasi (menit): "; cin >> durasi;
                insertAfter(myPlaylist, alokasi(judul, penyanyi, durasi), 3);
                cout << "Lagu berhasil ditambahkan setelah lagu ke-3!" << endl;
                break;
                
            case 4:
                cout << "\n--- Hapus Lagu ---" << endl;
                cout << "Judul lagu yang akan dihapus: "; 
                getline(cin, judul);
                deleteLagu(myPlaylist, judul);
                break;
                
            case 5:
                displayPlaylist(myPlaylist);
                break;
                
            case 6:
                cout << "Terima kasih telah menggunakan program!" << endl;
                break;
                
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
        
    } while (pilihan != 6);
    
    return 0;
}