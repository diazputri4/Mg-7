#ifndef KOTA_H
#define KOTA_H

#include "data.h"  // Mengakses Kota, daftarKota, jumlahKota

// Tambah kota baru ke daftar
void tambahKota(const char* namaKota);

// Hapus kota dari daftar
void hapusKota(const char* namaKota);

// Cari indeks kota berdasarkan nama (return -1 jika tidak ditemukan)
int cariIndeksKota(const char* namaKota);

// Tampilkan semua kota dan nama-nama di dalamnya
void tampilkanSemua();

// Tampilkan semua nama di dalam satu kota
void tampilkanNamaPerKota(Kota k);

// Tampilkan jumlah kota dan total nama
void tampilkanJumlahData();

#endif
