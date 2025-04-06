#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "kota.h"
#include "filemanager.h"

void tampilkanMenu() {
    printf("\n--- MENU ---\n");
    printf("1. Tambah Kota\n");
    printf("2. Tambah Orang ke Kota\n");
    printf("3. Hapus Kota\n");
    printf("4. Hapus Orang dari Kota\n");
    printf("5. Tampilkan Semua Kota & Orang\n");
    printf("6. Hitung Total Kota & Orang\n");
    printf("7. Simpan Data ke File\n");
    printf("8. Keluar\n");
    printf("Pilih: ");
}

void jalankanMenu(Kota** headKota) {
    int pilihan;
    char buffer[100];
    char namaKota[50], namaOrang[50];
    const char* namaFile = "data.txt";

    while (1) {
        tampilkanMenu();
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan nama kota: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = '\0';
                tambahKota(headKota, namaKota);
                break;

            case 2:
                printf("Masukkan nama kota: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = '\0';
                printf("Masukkan nama orang: ");
                fgets(namaOrang, sizeof(namaOrang), stdin);
                namaOrang[strcspn(namaOrang, "\n")] = '\0';
                tambahOrang(*headKota, namaKota, namaOrang);
                break;

            case 3:
                printf("Masukkan nama kota yang ingin dihapus: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = '\0';
                hapusKota(headKota, namaKota);
                break;

            case 4:
                printf("Masukkan nama kota: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = '\0';
                printf("Masukkan nama orang yang ingin dihapus: ");
                fgets(namaOrang, sizeof(namaOrang), stdin);
                namaOrang[strcspn(namaOrang, "\n")] = '\0';
                hapusOrang(*headKota, namaKota, namaOrang);
                break;

            case 5:
                tampilkanSemua(*headKota);
                break;

            case 6:
                hitungSemua(*headKota);
                break;

            case 7:
                simpanData(*headKota, namaFile);
                break;

            case 8:
                simpanData(*headKota, namaFile);
                printf("Keluar dari program.\n");
                return;

            default:
                printf("Pilihan tidak valid.\n");
        }
    }
}
