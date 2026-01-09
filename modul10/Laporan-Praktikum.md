<h1 align = center > <b>  LAPORAN PRATIKUM STUKTUR DATA <br>
</b></h1><p align = center><b>Nama : Alvin Aldino Rahmatullah || NIM : 103112430283 || Kelas : IF-12-05</b></p>

<h1> 1. Motivasi Belajar Struktur Data </h1>

Saya merasa mempelajari struktur data adalah pondasi awal untuk mengelola dan memahami informasi. Dengan memahami struktur data dengan baik saya merasa nantinya akan mudah menyusun program yang lebih efisien dan mampu menyelesaikan permasalahan nyata yang dihadapi, seperti pengolahan data pada aplikasi, layanan digital dan program yang mempermudah kegiatan sehari hari


<h1> 2. Dasar Teori </h1>

Multilist adalah pengembangan dari linked list yang digunakan untuk menyimpan data dengan hubungan bertingkat, seperti relasi antara data induk dan data anak. Pada struktur ini, satu elemen induk dapat memiliki sebuah linked list lain yang berisi data anak. Setiap node induk menyimpan data utama dan memiliki pointer ke node induk lainnya, serta sebuah list anak yang dikelola secara terpisah. Dengan cara ini, data anak tidak tercampur dengan data induk lain dan tetap terhubung dengan induknya masing-masing. Struktur multilist sering digunakan untuk kasus yang melibatkan relasi satu ke banyak, misalnya data kategori dan item, atau data induk dengan beberapa detail di dalamnya. Kelebihannya adalah data menjadi lebih terstruktur dan mudah dikembangkan sesuai kebutuhan.

<h1> 3. Guided </h1>

**-Code Program-**

**multilist.h**

```cpp

#ifndef MULTILIST_H_INCLUDED
#define MULTILIST_H_INCLUDED
#define Nil NULL

typedef int infotype;
typedef struct elemen_induk *address_induk;
typedef struct elemen_anak *address_anak;

struct elemen_anak {
    infotype info;
    address_anak next, prev;
};

struct list_anak {
    address_anak first, last;
};

struct elemen_induk {
    infotype info;
    list_anak anak;
    address_induk next, prev;
};

struct list_induk {
    address_induk first, last;
};

void createList(list_induk &L);
address_induk alokasi(infotype x);
void insertLastInduk(list_induk &L, address_induk P);
address_induk findInduk(list_induk L, infotype x);
void insertLastAnak(list_anak &LA, address_anak PA);
address_anak alokasiAnak(infotype x);
void printInfo(list_induk L);

#endif

```

**multilist.cpp**

```cpp

#include "multilist.h"
#include <iostream>
using namespace std;

void createList(list_induk &L) {
    L.first = Nil;
    L.last = Nil;
}

address_induk alokasi(infotype x) {
    address_induk P = new elemen_induk;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    P->anak.first = Nil;
    P->anak.last = Nil;
    return P;
}

void insertLastInduk(list_induk &L, address_induk P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

address_induk findInduk(list_induk L, infotype x) {
    address_induk P = L.first;
    while (P != Nil) {
        if (P->info == x) return P;
        P = P->next;
    }
    return Nil;
}

```

**multilist_anak.cpp**

```cpp

#include "multilist.h"
#include <iostream>
using namespace std;

address_anak alokasiAnak(infotype x) {
    address_anak P = new elemen_anak;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void insertLastAnak(list_anak &LA, address_anak PA) {
    if (LA.first == Nil) {
        LA.first = PA;
        LA.last = PA;
    } else {
        LA.last->next = PA;
        PA->prev = LA.last;
        LA.last = PA;
    }
}

void printInfo(list_induk L) {
    address_induk PI = L.first;
    while (PI != Nil) {
        cout << "Induk: " << PI->info << endl;
        address_anak PA = PI->anak.first;
        while (PA != Nil) {
            cout << "  Anak: " << PA->info << endl;
            PA = PA->next;
        }
        PI = PI->next;
    }
}

```

**main.cpp**

```cpp
#include "multilist.h"
#include <iostream>
using namespace std;

int main() {
    list_induk L;
    createList(L);

    address_induk P1 = alokasi(1);
    insertLastInduk(L, P1);

    address_anak PA1 = alokasiAnak(10);
    insertLastAnak(P1->anak, PA1);

    address_induk P2 = alokasi(2);
    insertLastInduk(L, P2);

    address_anak PA2 = alokasiAnak(20);
    insertLastAnak(P2->anak, PA2);

    printInfo(L);
    return 0;
}
```

**-Penjelasan Umum-**

program dibuat untuk menerapkan konsep multilist, yaitu struktur data yang memiliki hubungan antara data induk dan data anak. Setiap data induk menyimpan sebuah nilai, lalu memiliki list anak sendiri yang terhubung langsung ke induk tersebut. Di dalam program, list induk digunakan untuk menyimpan elemen utama, sedangkan setiap elemen induk memiliki list anak yang berfungsi menampung data turunannya. Proses dimulai dengan membuat list induk kosong, kemudian menambahkan data induk satu per satu menggunakan operasi insert last. Setelah itu, pada masing-masing induk ditambahkan data anak ke dalam list anak miliknya.

**-Output-**

![](output/output_g1.png)


<h1>4. Unguided</h1>

**-Code Program-**

**circularlist.h**

```cpp

#ifndef CIRCULARLIST_H_INCLUDED
#define CIRCULARLIST_H_INCLUDED
#include <string>
using namespace std;

#define Nil NULL

typedef struct infotype {
    string nama;
    string nim;
    char jenis_kelamin;
    float ipk;
} infotype;

typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address P);
void insertFirst(List &L, address P);
void insertAfter(List &L, address Prec, address P);
void insertLast(List &L, address P);
void insertSorted(List &L, address P);
void deleteFirst(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
void deleteLast(List &L, address &P);
address findElm(List L, infotype x);
void printInfo(List L);

#endif

```

**circularlist.cpp**

```cpp
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

```

**main.cpp**

```cpp

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

```

**-Penjelasan Umum-**

Setiap node menyimpan data mahasiswa berupa nama, NIM, jenis kelamin, dan IPK. Program menyediakan beberapa operasi dasar seperti insert first, insert last, insert after, serta insert sorted. Pada implementasi di main program, data mahasiswa dimasukkan menggunakan insert sorted, sehingga data otomatis tersusun berdasarkan NIM secara menaik tanpa perlu pengurutan tambahan. Setelah seluruh data dimasukkan, fungsi print digunakan untuk menampilkan isi list. Proses penampilan data dilakukan dengan menelusuri list secara melingkar hingga kembali ke elemen pertama. Output yang dihasilkan menunjukkan bahwa seluruh data mahasiswa berhasil tersimpan, terurut berdasarkan NIM, dan struktur circular list berjalan dengan baik.

**-Output-**

![](output/output_u1.png)

<h1> 5. Referensi </h1>


    1. https://www.geeksforgeeks.org/data-structures/linked-list

    2. https://www.programiz.com/dsa/linked-list

    3. https://www.geeksforgeeks.org/dsa/multilevel-linked-list
