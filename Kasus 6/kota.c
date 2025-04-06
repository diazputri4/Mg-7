#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kota.h"
#include "linkedlist.h"  

// Fungsi menambahkan kota ke linked list
void tambahKota(Kota** head, const char* namaKota) {
    Kota* baru = (Kota*)malloc(sizeof(Kota));
    strcpy(baru->namaKota, namaKota);
    baru->headOrang = NULL;
    baru->next = NULL;

    if (*head == NULL) {
        *head = baru;
    } else {
        Kota* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }

    printf("Kota '%s' berhasil ditambahkan.\n", namaKota);
}

// Fungsi menghapus kota dari linked list
void hapusKota(Kota** head, const char* namaKota) {
    Kota *curr = *head, *prev = NULL;

    while (curr != NULL && strcmp(curr->namaKota, namaKota) != 0) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Kota '%s' tidak ditemukan.\n", namaKota);
        return;
    }

    if (prev == NULL) {
        *head = curr->next;
    } else {
        prev->next = curr->next;
    }

    hapusSemuaNama(&(curr->headOrang));
    free(curr);
    printf("Kota '%s' berhasil dihapus.\n", namaKota);
}

// Fungsi mencari kota berdasarkan nama
Kota* cariKota(Kota* head, const char* namaKota) {
    Kota* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->namaKota, namaKota) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Tambah orang ke kota tertentu
void tambahOrang(Kota* head, const char* namaKota, const char* namaOrang) {
    Kota* kota = cariKota(head, namaKota);
    if (kota != NULL) {
        tambahNama(&(kota->headOrang), namaOrang);
        printf("Orang '%s' berhasil ditambahkan ke kota '%s'.\n", namaOrang, namaKota);
    } else {
        printf("Kota '%s' tidak ditemukan.\n", namaKota);
    }
}

// Hapus orang dari kota tertentu
void hapusOrang(Kota* head, const char* namaKota, const char* namaOrang) {
    Kota* kota = cariKota(head, namaKota);
    if (kota != NULL) {
        hapusNama(&(kota->headOrang), namaOrang);
        printf("Orang '%s' di kota '%s' berhasil dihapus.\n", namaOrang, namaKota);
    } else {
        printf("Kota '%s' tidak ditemukan.\n", namaKota);
    }
}

// Tampilkan semua kota dan orang
void tampilkanSemua(Kota* head) {
    Kota* kota = head;
    while (kota != NULL) {
        printf("Kota: %s\n", kota->namaKota);
        tampilkanLinkedList(kota->headOrang);
        kota = kota->next;
    }
}

// Hitung semua orang di semua kota
void hitungSemua(Kota* head) {
    Kota* kota = head;
    int total = 0;
    while (kota != NULL) {
        int jumlah = hitungLinkedList(kota->headOrang);
        printf("Kota %s: %d orang\n", kota->namaKota, jumlah);
        total += jumlah;
        kota = kota->next;
    }
    printf("Total seluruh orang: %d\n", total);
}

