#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

// Tambah orang ke linked list
void tambahNama(Orang** head, const char* nama) {
    Orang* baru = (Orang*)malloc(sizeof(Orang));
    strcpy(baru->nama, nama);
    baru->next = NULL;

    if (*head == NULL) {
        *head = baru;
    } else {
        Orang* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = baru;
    }
}

// Hapus orang dari linked list
void hapusNama(Orang** head, const char* nama) {
    Orang* temp = *head;
    Orang* prev = NULL;

    while (temp != NULL && strcmp(temp->nama, nama) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    if (prev == NULL)
        *head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
}

// Tampilkan semua nama dalam linked list
void tampilkanLinkedList(Orang* head) {
    while (head != NULL) {
        printf("- %s\n", head->nama);
        head = head->next;
    }
}

// Hitung jumlah orang dalam linked list
int hitungLinkedList(Orang* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Edit nama orang dalam linked list
void editNama(Orang* head, const char* namaLama, const char* namaBaru) {
    while (head != NULL) {
        if (strcmp(head->nama, namaLama) == 0) {
            strcpy(head->nama, namaBaru);
            break;
        }
        head = head->next;
    }
}

// Hapus seluruh orang dalam linked list
void hapusSemuaNama(Orang** head) {
    Orang* temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}
