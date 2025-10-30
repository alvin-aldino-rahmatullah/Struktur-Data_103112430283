#include <iostream>
#define Nil NULL
using namespace std;

typedef int infotype; // definisi tipe data infotype untuk menyimpan informasi pada elemen list
typedef struct elmlist *address; // definisi tipe data address sebagai pointer ke struct

struct elmlist{
    infotype info; //dekrlarasi variabel info untuk menyimpan data elemen
    address next;
    address prev;
};

struct List{
    address first;
    address last;
};

address alokasi(infotype x) { // Definisi fungsi alokasi untuk membuat elemen baru
    address P = new elmlist;   // Alokasi memori untuk elemen baru
    P -> info = x;          // Set info elemen dengan nilai x
    P -> next = Nil; // set next elemen ke Nil
    P -> prev = Nil; // set prev elemen ke Nil
    return P;
}

void dealokasi(address &P) { // Definisi fungsi dealokasi untuk menghapus elemen dari memori
    delete P; // Menghapus elemen yang ditunjuk oleh pointer P
    P = Nil;   // Set pointer P ke Nil setelah dealokasi
}

void insertFirst(List &L, address P) {
    P -> next = L.first;
    P -> prev = Nil; // set pointer next p ke first saat ini dan prev ke Nil
    if (L.first != Nil) L.first -> prev = P; // jika list tidak kosong, set prev first saat ini ke P
    else L.last = P; // jika list kosong, set last ke P
    L.first = P; // update firstlist menjadi P
}

void printInfo(List L) { // Definisi fungsi printInfo untuk mencetak elemen-elemen dalam list
    address P = L.first; // set P ke elemen pertama list
    while (P != Nil) { // selama P tidak Nil, cetak info dan pindah ke elemen berikutnya
        cout << P -> info << " ";
        P = P -> next;
    }
    cout << endl;
}

void deleteFirst(List &L, address &P) { // Definisi fungsi deleteFirst untuk menghapus elemen pertama dari list
    P = L.first; // set P ke elemen pertama list
    L.first -> next;
    
    if (L.first != Nil) { // jika list tidak kosong
        L.first = L.first -> next; // update first ke elemen berikutnya
        if (L.first != Nil) L.first -> prev = Nil; // jika first baru tidak Nil, set prev ke Nil
        else L.last = Nil; // jika list menjadi kosong, set last ke Nil
        P -> next = Nil; // putuskan hubungan P dengan list
        P -> prev = Nil;
    }
}

void deleteLast(List &L, address &P) { // Definisi fungsi deleteLast untuk menghapus elemen terakhir dari list
    P = L.last; // set P ke elemen terakhir list
    L.last = L.last -> prev;
    if (L.last != Nil) { // jika list tidak kosong
        L.last = L.last -> prev; // update last ke elemen sebelumnya
        if (L.last != Nil) L.last -> next = Nil; // jika last baru tidak Nil, set next ke Nil
        else L.first = Nil; // jika list menjadi kosong, set first ke Nil
        P -> next = Nil; // putuskan hubungan P dengan list
        P -> prev = Nil;
    }
}

void deleteAfter(List &L, address &P, address R) {
    P = R -> next; // set P ke elemen setelah R
    R -> next = P -> next; // hubungkan R ke elemen setelah P
    if (P -> next != Nil) P -> next -> prev = R; // jika P bukan elemen terakhir, hubungkan prev elemen setelah P ke R
    else L.last = R; // jika P adalah elemen terakhir, update last ke R
    P -> next = Nil; // putuskan hubungan P dengan list
    P -> prev = Nil;
}

int main() {
    List L;
    L.first = Nil;
    L.last = Nil;

   insertFirst(L, alokasi(1));
   insertFirst(L, alokasi(2));
   insertFirst(L, alokasi(3));
   printInfo(L); 

    address P;
    deleteFirst(L, P);
    dealokasi(P);
    deleteAfter(L, P, L.first);
    dealokasi(P);
    printInfo(L);
    return 0;
}