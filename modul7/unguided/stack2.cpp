#include "stack2.h"
using namespace std;

// procedure CreateStack( input/output S : Stack )
void CreateStack(Stack &S) {
    S.TOP = Nil; // Inisialisasi TOP dengan Nil untuk menandakan stack kosong
}

// function untuk memeriksa apakah stack kosong
bool isEmpty(Stack S) {
    return S.TOP == Nil; // Mengembalikan true jika TOP adalah Nil (stack kosong)
}

// function untuk memeriksa apakah stack penuh  
bool isFull(Stack S) {
    return S.TOP == MaxEl - 1; // Mengembalikan true jika TOP mencapai kapasitas maksimum stack
}

// procedure push(input/output S : Stack, input x : infotype)
void push(Stack &S, infotype X) {
    if (!isFull(S)) { // Memeriksa apakah stack tidak penuh sebelum menambahkan elemen
        S.TOP++; // Menaikkan indeks TOP
        S.info[S.TOP] = X; // Menambahkan elemen X ke posisi TOP
    } else {
        cout << "Stack penuh, tidak dapat menambahkan elemen." << endl;
    }
}

// function pop(input/output S : Stack ) -> infotype
infotype pop(Stack &S) {
    infotype X = -999; // Inisialisasi variabel untuk menyimpan elemen yang dihapus
    if (!isEmpty(S)) {
        X = S.info[S.TOP]; // Mengambil elemen dari posisi TOP
        S.TOP--; // Menurunkan indeks TOP
    } else {
        cout << "Stack kosong, tidak dapat menghapus elemen." << endl;
    }
    return X; // Mengembalikan elemen yang dihapus
}

// procedure printInfo( input S : Stack )
void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong." << endl;
    } else {
        cout << "[TOP] "; // tampilkan penanda posisi TOP
        for (int i = S.TOP; i >= 0; i--) {
            cout << S.info[i];
            if (i > 0) cout << " "; // tambahkan spasi antara elemen
        }
        cout << endl; // pindah baris setelah mencetak semua elemen
    }
}

// procedure balikStack(input/output S : Stack )
void balikStack(Stack &S) {
    if (!isEmpty(S)) {
        Stack temp1, temp2;
        CreateStack(temp1); 
        CreateStack(temp2);

        while (!isEmpty(S)) {
            push(temp1, pop(S)); // Memindahkan elemen dari S ke temp1
        }
        while (!isEmpty(temp1)) {
            push(temp2, pop(temp1)); // Memindahkan elemen dari temp1 ke temp2
        }
        while (!isEmpty(temp2)) {
            push(S, pop(temp2)); // Memindahkan elemen dari temp2 kembali ke S
        }
    }
}

// procedure pushAscending(in/out S : Stack, in x : integer)
void pushAscending(Stack &S, infotype X) {
    if (isFull(S)) {
        cout << "Stack penuh, tidak dapat menambahkan elemen." << endl;
        return;
    }
    
    // Jika stack kosong atau elemen lebih besar dari TOP, push langsung
    if (isEmpty(S) || X >= S.info[S.TOP]) {
        push(S, X);
        return;
    }
    
    // Jika elemen lebih kecil, cari posisi yang tepat dengan temporary stack
    Stack temp;
    CreateStack(temp);
    
    // Pindahkan elemen dari stack utama ke temp sampai menemukan posisi yang tepat
    while (!isEmpty(S) && X < S.info[S.TOP]) {
        push(temp, pop(S));
    }
    
    // Push elemen baru
    push(S, X);
    
    // Kembalikan elemen dari temp ke stack utama
    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}