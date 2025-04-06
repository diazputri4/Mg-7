// kota.h
#ifndef KOTA_H
#define KOTA_H

#include "data.h"  // <- ini sudah cukup, karena struct ada di sini

void tambahKota(Kota** head, const char* namaKota);
void hapusKota(Kota** head, const char* namaKota);
Kota* cariKota(Kota* head, const char* namaKota);

void tambahOrang(Kota* head, const char* namaKota, const char* namaOrang);
void hapusOrang(Kota* head, const char* namaKota, const char* namaOrang);
void tampilkanSemua(Kota* head);
void hitungSemua(Kota* head);

#endif
