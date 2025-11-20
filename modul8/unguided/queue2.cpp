#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1; // Inisialisasi head ke -1 (queue kosong)
    Q.tail = -1; // Inisialisasi tail ke -1 (queue kosong)
}

bool isEmptyQueue(Queue Q) {
    return Q.tail == -1 || Q.head > Q.tail; // Queue kosong jika tail = -1 ATAU head melebihi tail
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
        Q.tail++; // Geser tail ke posisi berikutnya
        Q.info[Q.tail] = x; // Simpan nilai x di posisi tail
    }
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Antrian kosong" << endl; // Tampilkan pesan jika queue kosong
        return -1; // Return -1 sebagai indikator error
    } else {
        infotype x = Q.info[Q.head]; // Ambil nilai dari posisi head
        Q.head++; // Geser head ke posisi berikutnya (tanpa menghapus elemen)
        if (Q.head > Q.tail) { // Jika head melebihi tail (queue kosong)
            Q.head = -1;       // Reset head ke -1
            Q.tail = -1;       // Reset tail ke -1
        }
        return x; // Kembalikan nilai yang di-dequeue
    }
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " | "; // Tampilkan posisi head dan tail
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl; // Tampilkan pesan queue kosong
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " "; // Tampilkan elemen queue dari head ke tail
        }
        cout << endl; // Pindah baris setelah menampilkan semua elemen
    }
}