// linkedlist.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "data.h"  

void tambahNama(Orang** head, const char* nama);
void hapusNama(Orang** head, const char* nama);
void editNama(Orang* head, const char* namaLama, const char* namaBaru);
void tampilkanLinkedList(Orang* head);
int hitungLinkedList(Orang* head);
void hapusSemuaNama(Orang** head);

#endif
