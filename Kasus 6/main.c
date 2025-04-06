#include <stddef.h>  // untuk NULL
#include "menu.h"
#include "data.h"     // untuk struct Kota

int main() {
    Kota* headKota = NULL;
    jalankanMenu(&headKota);  
    return 0;
}
