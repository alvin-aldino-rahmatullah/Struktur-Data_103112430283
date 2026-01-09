#include "circularlist.h"
#include <iostream>
using namespace std;

void createList(List &L) {
    L.first = Nil;
}

// Alokasi elemen baru
address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = P;  //elemen menunjuk ke dirinya sendiri
    return P;
}

// Dealokasi elemen
void dealokasi(address P) {
    delete P;
}

// Insert elemen di awal list
void insertFirst(List &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        P->next = P;  
    } else {
 
        address last = L.first;
        while (last->next != L.first) {
            last = last->next;
        }
        
        P->next = L.first;
        L.first = P;
        last->next = L.first;  // Update last next ke first baru
    }
}

// Insert elemen setelah elemen tertentu
void insertAfter(List &L, address Prec, address P) {
    if (Prec == Nil || P == Nil) return;
    
    P->next = Prec->next;
    Prec->next = P;
}

// Insert elemen di akhir list
void insertLast(List &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        P->next = P;  
    } else {
        address last = L.first;
        while (last->next != L.first) {
            last = last->next;
        }
        
        last->next = P;
        P->next = L.first;
    }
}

// Insert elemen secara terurut berdasarkan NIM
void insertSorted(List &L, address P) {
    if (L.first == Nil) {  
        L.first = P;
        P->next = P;
        return;
    }
    
    // Jika P harus menjadi elemen pertama (NIM lebih kecil dari first)
    if (P->info.nim < L.first->info.nim) {
        address last = L.first;
        while (last->next != L.first) {
            last = last->next;
        }
        P->next = L.first;
        L.first = P;
        last->next = L.first;
        return;
    }
    

    address current = L.first;
    address prev = Nil;
    
    do {
        if (P->info.nim < current->info.nim) {
            break;
        }
        prev = current;
        current = current->next;
    } while (current != L.first);
    
  
    if (prev == Nil) {  
        address last = L.first;
        while (last->next != L.first) {
            last = last->next;
        }
        last->next = P;
        P->next = L.first;
    } else {
        P->next = prev->next;
        prev->next = P;
    }
}

// Delete elemen pertama
void deleteFirst(List &L, address &P) {
    if (L.first == Nil) {
        P = Nil;
        return;
    }
    
    P = L.first;
    
    if (P->next == P) { 
        L.first = Nil;
    } else {
 
        address last = L.first;
        while (last->next != L.first) {
            last = last->next;
        }
        
        L.first = P->next;
        last->next = L.first;
    }
    
    P->next = Nil; 
}

// Delete elemen setelah elemen tertentu
void deleteAfter(List &L, address Prec, address &P) {
    if (Prec == Nil || Prec->next == Prec) {
        P = Nil;
        return;
    }
    
    P = Prec->next;
    
    if (P == L.first) {  
        if (P->next == P) {  
            L.first = Nil;
        } else {
 
            address prev = L.first;
            while (prev->next != P) {
                prev = prev->next;
            }
            prev->next = P->next;
            L.first = P->next;
        }
    } else {
        Prec->next = P->next;
    }
    
    P->next = Nil;
}

// Delete elemen terakhir
void deleteLast(List &L, address &P) {
    if (L.first == Nil) {
        P = Nil;
        return;
    }
    
    if (L.first->next == L.first) {  
        P = L.first;
        L.first = Nil;
        P->next = Nil;
    } else {
        address Q = L.first;
        address prev = Nil;
        

        do {
            prev = Q;
            Q = Q->next;
        } while (Q->next != L.first);
        
        P = Q;
        prev->next = L.first;
        P->next = Nil;
    }
}

// Find elemen dengan NIM tertentu
address findElm(List L, infotype x) {
    if (L.first == Nil) return Nil;
    
    address P = L.first;
    do {
        if (P->info.nim == x.nim) {
            return P;
        }
        P = P->next;
    } while (P != L.first);
    
    return Nil;
}

void printInfo(List L) {
    if (L.first == Nil) {
        cout << "List kosong" << endl;
        return;
    }
    
    address P = L.first;
    
    do {
        cout << "Nama : " << P->info.nama << endl;
        cout << "NIM : " << P->info.nim << endl;
        cout << "L/P : " << P->info.jenis_kelamin << endl;
        cout << "IPK : " << P->info.ipk << endl;
        cout << endl;
        
        P = P->next;
    } while (P != L.first);
}