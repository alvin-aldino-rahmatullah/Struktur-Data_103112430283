#include <iostream>
#define Nil NULL
using namespace std;

typedef int infotype;

typedef struct elmlist *address;

struct elmlist{
    infotype info;
    address next;
    address prev;
};

struct List{
    address first;
    address last;
};

void insertFirst(List &L, address P) {
    P -> next = L.first;
    P -> prev = Nil;
    if (L.first != Nil) L.first -> prev = P;
    else L.last = P;
    L.first = P;
}


void insertLast(List &L, address P) { // definisi fungsi insertLast untuk menyisipkan elemen di akhir list
    P -> prev = L.last;
    P -> next = Nil;
    if (L.last != Nil) L.last -> next = P;
    else L.first = P;
    L.last = P;
}

void insertAfter(List &L, address P, address R) {
    P -> next = R -> next;
    P -> prev = R;
    if (R -> next != Nil) R -> next -> prev = P;
    else L.last = P;
    R -> next = P;
}

address alokasi(infotype x) { // Definisi fungsi alokasi untuk membuat elemen baru
    address P = new elmlist;   // Alokasi memori untuk elemen baru
    P -> info = x;          // Set info elemen dengan nilai x
    P -> next = Nil; // set next elemen ke Nil
    P -> prev = Nil; // set prev elemen ke Nil
    return P;
}

void printInfo(List L) { // Definisi fungsi printInfo untuk mencetak elemen-elemen dalam list
    address P = L.first; // set P ke elemen pertama list
    while (P != Nil) { // 
        cout << P -> info << " ";
        P = P -> next;
    }
    cout << endl;
}

int main() {
    List L;
    L.first = Nil;
    L.last = Nil;

    address P1 = alokasi(1);
    insertFirst(L, P1);

    address P2 = alokasi(2);
    insertLast(L, P2);
    
    address P3 = alokasi(3);
    insertAfter(L, P3, P1);

    printInfo(L); 

    return 0;
}