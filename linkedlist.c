#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

void tambahNama(Node** head, const char* nama) {
    Node* baru = (Node*)malloc(sizeof(Node));
    if (!baru) {
        printf("Gagal mengalokasikan memori.\n");
        return;
    }
    strcpy(baru->nama, nama);
    baru->next = NULL;

    if (*head == NULL) {
        *head = baru;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }
}

void hapusNama(Node** head, const char* nama) {
    if (*head == NULL) {
        printf("List kosong.\n");
        return;
    }

    Node* temp = *head;
    Node* prev = NULL;

    while (temp != NULL && strcmp(temp->nama, nama) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Nama \"%s\" tidak ditemukan.\n", nama);
        return;
    }

    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Nama \"%s\" berhasil dihapus.\n", nama);
}

void tampilkanLinkedList(Node* head) {
    if (head == NULL) {
        printf(" (tidak ada data)\n");
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        printf(" - %s\n", temp->nama);
        temp = temp->next;
    }
}

int hitungLinkedList(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void hapusSemuaNama(Node** head) {
    Node* current = *head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}
