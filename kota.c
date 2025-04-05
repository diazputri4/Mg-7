#include <stdio.h>
#include <string.h>
#include "kota.h"
#include "data.h"
#include "linkedlist.h"

void tambahKota(const char* namaKota) {
    if (jumlahKota >= MAX_KOTA) {
        printf("Kapasitas kota sudah penuh!\n");
        return;
    }

    if (cariIndeksKota(namaKota) != -1) {
        printf("Kota sudah terdaftar!\n");
        return;
    }

    strcpy(daftarKota[jumlahKota].namaKota, namaKota);
    daftarKota[jumlahKota].headNama = NULL;
    jumlahKota++;
    printf("Kota %s berhasil ditambahkan.\n", namaKota);
}

int cariIndeksKota(const char* namaKota) {
    for (int i = 0; i < jumlahKota; i++) {
        if (strcmp(daftarKota[i].namaKota, namaKota) == 0) {
            return i;
        }
    }
    return -1;
}

void hapusKota(const char* namaKota) {
    int idx = cariIndeksKota(namaKota);
    if (idx == -1) {
        printf("Kota tidak ditemukan!\n");
        return;
    }

    hapusSemuaNama(&daftarKota[idx].headNama);  // ✅ Perbaikan bug

    // Geser array ke kiri
    for (int i = idx; i < jumlahKota - 1; i++) {
        daftarKota[i] = daftarKota[i + 1];
    }
    jumlahKota--;

    printf("Kota %s dan seluruh data orangnya berhasil dihapus.\n", namaKota);
}

void tampilkanNamaPerKota(Kota k) {
    printf("\nData orang di kota %s:\n", k.namaKota);
    tampilkanLinkedList(k.headNama);
}

void tampilkanSemua() {
    printf("\n=== DATA SELURUH KOTA DAN ORANG ===\n");
    for (int i = 0; i < jumlahKota; i++) {
        printf("\nKota: %s\n", daftarKota[i].namaKota);
        tampilkanLinkedList(daftarKota[i].headNama);
    }
}

void tampilkanJumlahData() {
    int totalOrang = 0;
    for (int i = 0; i < jumlahKota; i++) {
        totalOrang += hitungLinkedList(daftarKota[i].headNama);
    }

    printf("\nJumlah Kota: %d\n", jumlahKota);
    printf("Total Nama: %d\n", totalOrang);

    for (int i = 0; i < jumlahKota; i++) {
        int jml = hitungLinkedList(daftarKota[i].headNama);
        printf("- %s: %d orang\n", daftarKota[i].namaKota, jml);
    }
}
