#include "circularlist.h"
#include <iostream>
using namespace std;


address createData(string nama, string nim, char jenis_kelamin, float ipk) {
infotype x;
x.nama = nama;
x.nim = nim;
x.jenis_kelamin = jenis_kelamin;
x.ipk = ipk;
return alokasi(x);
}


int main() {
    List L;
    address P = Nil;
    
    createList(L);

    cout << "coba insert first, last, dan after" << endl;

    P = createData("Danu", "04", 'l', 4.0);
    insertSorted(L, P);

    P = createData("Fahmi", "06", 'l', 3.45);
    insertSorted(L, P);
    
    P = createData("Bobi", "02", 'l', 3.71);
    insertSorted(L, P);
    
    P = createData("Ali", "01", 'l', 3.3);
    insertSorted(L, P);

    P = createData("Gita", "07", 'p', 3.75);
    insertSorted(L, P);

    P = createData("Cindi", "03", 'p', 3.5);
    insertSorted(L, P);

    P = createData("Hilmi", "08", 'p', 3.3);
    insertSorted(L, P);

    P = createData("Eli", "05", 'p', 3.4);
    insertSorted(L, P);
    
    printInfo(L);
    return 0;
}