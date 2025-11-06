#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Hello world!" << endl;
    
    Stack S; // deklarasi variabel S bertipe Stack
    CreateStack(S); // inisialisasi stack S menjadi stack kosong

    push(S, 3); // menambahkan elemen 3 ke stack S
    push(S, 4); // menambahkan elemen 4 ke stack S  
    push(S, 8); // menambahkan elemen 8 ke stack S
    pop(S);     // menghapus elemen teratas dari stack S (elemen 8)
    push(S, 2); // menambahkan elemen 2 ke stack S
    push(S, 3); // menambahkan elemen 3 ke stack S
    pop(S);     // menghapus elemen teratas dari stack S (elemen 3)
    push(S, 9); // menambahkan elemen 9 ke stack S
    
    printInfo(S); // mencetak isi stack
    
    cout << "balik stack" << endl;
    balikStack(S); // membalik urutan elemen dalam stack S
    
    printInfo(S); // mencetak isi stack setelah dibalik
    
    return 0;
}