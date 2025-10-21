#include "Playlist.h"
#include <iostream>
#include <iomanip>
using namespace std;

void createPlaylist(Playlist &L) {
    L.first = NULL;
}

address alokasi(string judul, string penyanyi, float durasi) {
    address P = new Node;
    P->data.judul = judul;
    P->data.penyanyi = penyanyi;
    P->data.durasi = durasi;
    P->next = NULL;
    return P;
}

void dealokasi(address P) {
    delete P;
}

void insertFirst(Playlist &L, address P) {
    if (isEmpty(L)) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

void insertLast(Playlist &L, address P) {
    if (isEmpty(L)) {
        L.first = P;
    } else {
        address last = L.first;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = P;
    }
}

void insertAfter(Playlist &L, address P, int posisi) {
    if (isEmpty(L)) {
        L.first = P;
        return;
    }
    
    address current = L.first;
    int count = 1;
    
    while (current != NULL && count < posisi) {
        current = current->next;
        count++;
    }
    
    if (current != NULL) {
        P->next = current->next;
        current->next = P;
    } else {
        insertLast(L, P);
    }
}

void deleteLagu(Playlist &L, string judul) {
    if (isEmpty(L)) {
        cout << "Playlist kosong!" << endl;
        return;
    }
    
    address current = L.first;
    address prev = NULL;

    while (current != NULL && current->data.judul != judul) {
        prev = current;
        current = current->next;
    }
    
    if (current == NULL) {
        cout << "Lagu dengan judul '" << judul << "' tidak ditemukan!" << endl;
        return;
    }

    if (prev == NULL) {
        L.first = current->next;
    } else {
        prev->next = current->next;
    }
    
    dealokasi(current);
    cout << "Lagu '" << judul << "' berhasil dihapus dari playlist!" << endl;
}

void displayPlaylist(Playlist L) {
    if (isEmpty(L)) {
        cout << "Playlist kosong!" << endl;
        return;
    }
    
    cout << "\n=== PLAYLIST LAGU ===" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << left << setw(20) << "Judul" 
         << setw(20) << "Penyanyi" 
         << setw(10) << "Durasi" << endl;
    cout << "--------------------------------------------------------" << endl;
    
    address current = L.first;
    int nomor = 1;
    float totalDurasi = 0;
    
    while (current != NULL) {
        cout << nomor << ". " 
             << left << setw(17) << current->data.judul 
             << setw(20) << current->data.penyanyi 
             << setw(10) << current->data.durasi << " menit" << endl;
        totalDurasi += current->data.durasi;
        current = current->next;
        nomor++;
    }
    
    cout << "--------------------------------------------------------" << endl;
    cout << "Total durasi playlist: " << totalDurasi << " menit" << endl;
    cout << "Jumlah lagu: " << (nomor - 1) << " lagu" << endl;
}

bool isEmpty(Playlist L) {
    return L.first == NULL;
}