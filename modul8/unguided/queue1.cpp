#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1; // Inisialisasi head ke -1 (menandakan queue kosong)
    Q.tail = -1; // Inisialisasi tail ke -1 (menandakan queue kosong)
}

bool isEmptyQueue(Queue Q) {
    return Q.tail == -1; // Queue kosong jika tail = -1
}

bool isFullQueue(Queue Q) {
    return Q.tail == MAX_QUEUE - 1; // Queue penuh jika tail mencapai indeks terakhir array
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Antrian ini sudah penuh" << endl; // Tampilkan pesan jika queue penuh
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0; // Jika queue kosong, set head ke 0
        }
        Q.tail++; // Pindahkan tail ke posisi berikutnya
        Q.info[Q.tail] = x; // Simpan nilai x di posisi tail
    }
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Antrian kosong" << endl; // Tampilkan pesan jika queue kosong
        return -1; // Return -1 sebagai indikator error
    } else {
        infotype x = Q.info[Q.head]; // Ambil nilai dari posisi head
        for (int i = Q.head; i < Q.tail; i++) {
            Q.info[i] = Q.info[i + 1]; // Geser semua elemen ke kiri (ke depan)
        }
        Q.tail--; // Kurangi tail karena satu elemen dikeluarkan
        if (Q.tail == -1) { 
            Q.head = -1;    // Jika queue menjadi kosong, reset head ke -1
        }
        return x; // Kembalikan nilai yang di-dequeue
    }
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " : "; // Tampilkan posisi head dan tail
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl; // Tampilkan pesan queue kosong
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i]; // Tampilkan elemen queue
            if (i < Q.tail) {
                cout << " "; // Tambah spasi antara elemen kecuali elemen terakhir
            }
        }
        cout << endl; // Pindah baris setelah menampilkan semua elemen
    }
}