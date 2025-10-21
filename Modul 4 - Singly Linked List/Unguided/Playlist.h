#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <string>
using namespace std;

struct Lagu {
    string judul;
    string penyanyi;
    float durasi;
};

struct Node {
    Lagu data;
    Node* next;
};

typedef Node* address;

struct Playlist {
    address first;
};

void createPlaylist(Playlist &L);
address alokasi(string judul, string penyanyi, float durasi);
void dealokasi(address P);
void insertFirst(Playlist &L, address P);
void insertLast(Playlist &L, address P);
void insertAfter(Playlist &L, address P, int posisi);
void deleteLagu(Playlist &L, string judul);
void displayPlaylist(Playlist L);
bool isEmpty(Playlist L);

#endif