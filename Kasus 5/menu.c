#include <stdio.h>
#include <string.h>
#include "data.h"
#include "kota.h"
#include "linkedlist.h"
#include "filemanager.h"

void menuUtama() {
    muatDariFile("data.txt"); // Load data jika ada

    int pilihan;
    char namaKota[50];
    char namaOrang[50];

    do {
        printf("\n===== MENU =====\n");
        printf("1. Tambah Kota\n");
        printf("2. Hapus Kota\n");
        printf("3. Tambah Nama ke Kota\n");
        printf("4. Hapus Nama dari Kota\n");
        printf("5. Tampilkan Semua Data\n");
        printf("6. Tampilkan Nama per Kota\n");
        printf("7. Tampilkan Jumlah Data\n");
        printf("0. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);
        getchar(); // Buang newline

        switch (pilihan) {
            case 1:
                printf("Masukkan nama kota: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = '\0';
                tambahKota(namaKota);
                break;
            case 2:
                printf("Masukkan nama kota yang ingin dihapus: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = '\0';
                hapusKota(namaKota);
                break;
            case 3:
                printf("Masukkan nama kota: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = '\0';
                printf("Masukkan nama orang: ");
                fgets(namaOrang, sizeof(namaOrang), stdin);
                namaOrang[strcspn(namaOrang, "\n")] = '\0';
                {
                    int indeks = cariIndeksKota(namaKota);
                    if (indeks != -1) {
                        tambahNama(&daftarKota[indeks].headNama, namaOrang);
                    } else {
                        printf("Kota tidak ditemukan.\n");
                    }
                }
                break;
            case 4:
                printf("Masukkan nama kota: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = '\0';
                printf("Masukkan nama orang yang ingin dihapus: ");
                fgets(namaOrang, sizeof(namaOrang), stdin);
                namaOrang[strcspn(namaOrang, "\n")] = '\0';
                {
                    int indeks = cariIndeksKota(namaKota);
                    if (indeks != -1) {
                        hapusNama(&daftarKota[indeks].headNama, namaOrang);
                    } else {
                        printf("Kota tidak ditemukan.\n");
                    }
                }
                break;
            case 5:
                tampilkanSemua();
                break;
            case 6:
                printf("Masukkan nama kota: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = '\0';
                {
                    int indeks = cariIndeksKota(namaKota);
                    if (indeks != -1) {
                        tampilkanNamaPerKota(daftarKota[indeks]);
                    } else {
                        printf("Kota tidak ditemukan.\n");
                    }
                }
                break;
            case 7:
                tampilkanJumlahData();
                break;
            case 0:
                simpanKeFile("data.txt"); // Simpan sebelum keluar
                printf("Terima kasih!\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }

    } while (pilihan != 0);
}
