#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "data.h"

// Fungsi-fungsi untuk menyimpan dan memuat data
void simpanData(Kota* headKota, const char* namaFile);
void muatData(Kota** headKota, const char* namaFile);

#endif
