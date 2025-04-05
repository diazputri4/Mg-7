#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node {
    char nama[50];
    struct node* next;
} Node;

void tambahNama(Node** head, const char* nama);
void hapusNama(Node** head, const char* nama);
void tampilkanLinkedList(Node* head);
int hitungLinkedList(Node* head);
void hapusSemuaNama(Node** head);

#endif
