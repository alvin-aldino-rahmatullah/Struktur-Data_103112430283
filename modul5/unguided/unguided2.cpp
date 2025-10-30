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

// Menyisipkan node di awal list
void insertFirst(List &L, address P) {
    P->next = L.first; P->prev = Nil;                    
    if (L.first != Nil) L.first->prev = P;            
    else L.last = P;                   
    L.first = P;                      
}

// Mencetak isi list dari depan ke belakang
void printInfo(List L) {
    address P = L.first;              
    while (P != Nil) {               
        cout << P->info << " ";       
        P = P->next;                  
    }
    cout << endl;                     
}

// Menghapus node pertama
void deleteFirst(List &L, address &P) {
    P = L.first;                    
    if (L.first != Nil) {            
        L.first = L.first->next;    
        if (L.first != Nil) L.first->prev = Nil;   
        else L.last = Nil;            
        P->next = Nil; P->prev = Nil;
    }
}

// Menghapus node terakhir
void deleteLast(List &L, address &P) {
    P = L.last;                      
    if (L.last != Nil) {              
        L.last = L.last->prev;        
        if (L.last != Nil) L.last->next = Nil;       
        else L.first = Nil;            
        P->next = Nil; P->prev = Nil;
    }
}

// Menghapus node setelah node tertentu
void deleteAfter(List &L, address &P, address R) {
    P = R->next;                      
    if (P != Nil) {                
        R->next = P->next;            
        if (P->next != Nil) P->next->prev = R;       
        else L.last = R;            
        P->next = Nil;P->prev = Nil;
    }
}

// Menghapus elemen pertama dengan nilai tertentu
void deleteByValue(List &L, infotype x) {
    address P = L.first;              

    // telusuri list hingga ketemu nilai x
    while (P != Nil && P->info != x) {
        P = P->next;
    }

    // jika tidak ketemu
    if (P == Nil) {
        cout << "Nilai " << x << " tidak ditemukan" << endl;
    } else {
        // jika ketemu, hapus berdasarkan posisinya
        if (P == L.first) {
            address Q; deleteFirst(L, Q); dealokasi(Q);
        } else if (P == L.last) {
            address Q; deleteLast(L, Q); dealokasi(Q);
        } else {
            address Q; deleteAfter(L, Q, P->prev); dealokasi(Q);
        }
        cout << "Nilai " << x << " berhasil dihapus" << endl;
    }
}

// Menghapus semua elemen list
void deleteAll(List &L) {
    address P;
    int count = 0; 
    while (L.first != Nil) {     
        deleteFirst(L, P); dealokasi(P);               
        count++;                      
    }
    cout << "Semua elemen (" << count << ") berhasil dihapus" << endl;
}

int main() {
    List L; L.first = Nil; L.last = Nil; address P;

    insertFirst(L, alokasi(1)); insertFirst(L, alokasi(2)); insertFirst(L, alokasi(3)); insertFirst(L, alokasi(2));

    cout << "List awal: ";
    printInfo(L);                     

    deleteByValue(L, 2);
    cout << "Setelah deleteByValue(2): ";
    printInfo(L);

    deleteByValue(L, 5);
    cout << "List tetap: ";
    printInfo(L);

    insertFirst(L, alokasi(1)); insertFirst(L, alokasi(2)); insertFirst(L, alokasi(3)); insertFirst(L, alokasi(4)); insertFirst(L, alokasi(5));

    cout << "List setelah tambah data: ";
    printInfo(L);
    deleteAll(L);
    return 0;
}