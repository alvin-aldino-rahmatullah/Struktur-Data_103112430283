#include "stack.h" // mengimport file header stack.h yang berisi definisi struktur dan konstanta stack
using namespace std;

void CreateStack(Stack &S) {
    S.TOP = Nil; // Inisialisasi TOP dengan Nil untuk menandakan stack kosong
}
//fungsi untuk memeriksa apakah stack kosong
bool IsEmpty(Stack S) 
{
    return S.TOP == Nil; // Mengembalikan true jika TOP adalah Nil (stack kosong)
}

//fungsi untuk memeriksa apakah stack penuh
bool IsFull(Stack S) 
{
    return S.TOP == MaxEl - 1; // Mengembalikan true jika TOP mencapai kapasitas maksimum stack
}

// fungsi untuk menambahkan elemen ke stack (push)
void push(Stack &S, int X) {
    if (!IsFull(S)) { // Memeriksa apakah stack tidak penuh sebelum menambahkan elemen
        S.TOP++; // Menaikkan indeks TOP
        S.info[S.TOP] = X; // Menambahkan elemen X ke posisi TOP
    } else {
        cout << "Stack penuh, tidak dapat menambahkan elemen." << endl; // Pesan jika stack penuh
    }
}

// fungsi untuk menghapus elemen dari stack (pop)
infotype pop(Stack &S) {
    infotype X = -999; // Inisialisasi variabel untuk menyimpan elemen yang dihapus
    if (!IsEmpty(S)) {
        X = S.info[S.TOP]; // Mengambil elemen dari posisi TOP
        S.TOP--; // Menurunkan indeks TOP
    } else {
        cout << "Stack kosong, tidak dapat menghapus elemen." << endl; // Pesan jika stack kosong
    }
    return X; // Mengembalikan elemen yang dihapus
}

void printInfo(Stack S) 
{
    if (IsEmpty(S)) {
        cout << "Stack kosong." << endl; // Pesan jika stack kosong
    } else {
        cout<<"[TOP] " ;// tampilkan penanda posisi TOP
        for (int i = S.TOP; i >= 0; i--) {
            cout << S.info[i] << endl; // Mencetak elemen stack dari TOP ke bawah
        }
    }
}

void balikStack(Stack &S) 
{
   if (!IsEmpty(S)) {
        Stack temp1, temp2;
        CreateStack(temp1); CreateStack(temp2);

        while (!IsEmpty(S)) {
            push (temp1, pop(S)); // Memindahkan elemen dari S ke temp1
        }
        while (!IsEmpty(temp1)) {
            push (temp2, pop(temp1)); // Memindahkan elemen dari temp1 ke temp2
        }
        while (!IsEmpty(temp2)) {
            push (S, pop(temp2)); // Memindahkan elemen dari temp2 kembali ke S
        }
    }
}