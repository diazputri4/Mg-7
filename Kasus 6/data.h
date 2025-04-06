// data.h
#ifndef DATA_H
#define DATA_H

typedef struct orang {
    char nama[100];
    struct orang* next;
} Orang;

typedef struct kota {
    char namaKota[100];
    Orang* headOrang;  // Ubah dari Node* jadi Orang*
    struct kota* next;
} Kota;

#endif
