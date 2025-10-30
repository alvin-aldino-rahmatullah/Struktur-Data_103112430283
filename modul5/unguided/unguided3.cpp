#include <iostream>
#define Nil NULL
using namespace std;

typedef int infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

// Membuat elemen baru
address alokasi(infotype x) {
    address P = new elmlist; 
    P->info = x;           
    P->next = Nil;     
    P->prev = Nil;    
    return P;    
}

// Menghapus node dari memori
void dealokasi(address &P) {
    delete P;               
    P = Nil;            
}

// Menyisipkan di awal list
void insertFirst(List &L, address P) {
    P->next = L.first;     
    P->prev = Nil;     
    if (L.first != Nil)
        L.first->prev = P;
    else
        L.last = P;        
    L.first = P; 
}

// Menyisipkan di akhir list
void insertLast(List &L, address P) {
    P->prev = L.last;
    P->next = Nil;
    if (L.last != Nil)
        L.last->next = P;
    else
        L.first = P;
    L.last = P;
}

// Menyisipkan setelah elemen tertentu
void insertAfter(List &L, address P, address R) {
    P->next = R->next;
    P->prev = R;
    if (R->next != Nil)
        R->next->prev = P;
    else
        L.last = P;
    R->next = P;
}

// Menyisipkan sebelum elemen tertentu
void insertBefore(List &L, address P, address R) {
    P->next = R;
    P->prev = R->prev;
    if (R->prev != Nil)
        R->prev->next = P;
    else
        L.first = P;
    R->prev = P;
}

// Cetak list dari depan
void printForward(List L) {
    address P = L.first;
    cout << "Forward: ";
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

// Cetak list dari belakang
void printBackward(List L) {
    address P = L.last;
    cout << "Backward: ";
    while (P != Nil) {
        cout << P->info << " ";
        P = P->prev;
    }
    cout << endl;
}

void deleteFirst(List &L, address &P) {
    P = L.first;
    if (L.first != Nil) {
        L.first = L.first->next;
        if (L.first != Nil)
            L.first->prev = Nil;
        else
            L.last = Nil;
        P->next = Nil;
        P->prev = Nil;
    }
}

void deleteLast(List &L, address &P) {
    P = L.last;
    if (L.last != Nil) {
        L.last = L.last->prev;
        if (L.last != Nil)
            L.last->next = Nil;
        else
            L.first = Nil;
        P->next = Nil;
        P->prev = Nil;
    }
}

void deleteAfter(List &L, address &P, address R) {
    P = R->next;
    if (P != Nil) {
        R->next = P->next;
        if (P->next != Nil)
            P->next->prev = R;
        else
            L.last = R;
        P->next = Nil;
        P->prev = Nil;
    }
}

// Hapus elemen pertama bernilai x
void deleteByValue(List &L, infotype x) {
    address P = L.first;
    while (P != Nil && P->info != x) {
        P = P->next;
    }
    if (P == Nil) {
        cout << "Nilai " << x << " tidak ditemukan" << endl;
    } else {
        if (P == L.first) {
            address Q;
            deleteFirst(L, Q);
            dealokasi(Q);
        } else if (P == L.last) {
            address Q;
            deleteLast(L, Q);
            dealokasi(Q);
        } else {
            address Q;
            deleteAfter(L, Q, P->prev);
            dealokasi(Q);
        }
        cout << "Nilai " << x << " berhasil dihapus" << endl;
    }
}

// Menghapus semua elemen
void deleteAll(List &L) {
    address P;
    int count = 0;
    while (L.first != Nil) {
        deleteFirst(L, P);
        dealokasi(P);
        count++;
    }
    cout << "Semua elemen (" << count << ") berhasil dihapus" << endl;
}

// Smart insert: menyisipkan dengan logika kondisi
void smartInsert(List &L, infotype x) {
    address P = alokasi(x);

    if (L.first == Nil) {
        cout << "Smart Insert: List kosong, insert " << x << " di first" << endl;
        insertFirst(L, P);
    }
    else if (x < L.first->info) {
        cout << "Smart Insert: " << x << " < first, insert di first" << endl;
        insertFirst(L, P);
    }
    else if (x % 2 == 0) {
        cout << "Smart Insert: " << x << " genap, insert di last" << endl;
        insertLast(L, P);
    }
    else if (x > L.first->info && x < L.last->info) {
        cout << "Smart Insert: " << x << " di antara " << L.first->info << " dan " << L.last->info << endl;
        insertAfter(L, P, L.first);
    }
    else {
        cout << "Smart Insert: kondisi lain, insert di last" << endl;
        insertLast(L, P);
    }
}

// Conditional delete: hapus elemen ganjil
void conditionalDelete(List &L) {
    cout << "Sebelum Conditional Delete: ";
    printForward(L);

    address P = L.first;
    int count = 0;
    while (P != Nil) {
        address nextNode = P->next;
        if (P->info % 2 != 0) {
            if (P == L.first) {
                address Q;
                deleteFirst(L, Q);
                dealokasi(Q);
            } else if (P == L.last) {
                address Q;
                deleteLast(L, Q);
                dealokasi(Q);
            } else {
                address Q;
                deleteAfter(L, Q, P->prev);
                dealokasi(Q);
            }
            count++;
        }
        P = nextNode;
    }
    cout << "Conditional Delete: " << count << " elemen ganjil dihapus" << endl;
    cout << "Setelah Conditional Delete: ";
    printForward(L);
}

int main() {
    List L;
    L.first = Nil;
    L.last = Nil;

    cout << "SMART INSERT DEMO" << endl;
    smartInsert(L, 5); smartInsert(L, 3); smartInsert(L, 8); smartInsert(L, 6); smartInsert(L, 4); smartInsert(L, 7);

    cout << "Hasil Smart Insert:" << endl;
    printForward(L);
    printBackward(L);

    cout << "CONDITIONAL DELETE" << endl;
    conditionalDelete(L);

    cout << "DELETE BY VALUE DEMO" << endl;
    deleteByValue(L, 6); deleteByValue(L, 10);
    cout << "List akhir: ";
    printForward(L);

    cout << "DELETE ALL DEMO" << endl;
    deleteAll(L);

    return 0;
}
