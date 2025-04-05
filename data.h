#ifndef DATA_H
#define DATA_H

#include "linkedlist.h"  // Ambil definisi Node dari sini

#define MAX_KOTA 100

typedef struct {
    char namaKota[50];
    Node* headNama;
} Kota;

extern Kota daftarKota[MAX_KOTA];
extern int jumlahKota;

#endif
