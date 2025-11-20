#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = 0;    // Inisialisasi head di posisi 0
    Q.tail = 0;    // Inisialisasi tail di posisi 0 (queue kosong)
}

bool isEmptyQueue(Queue Q) {
    return Q.head == Q.tail;  // Queue kosong ketika head dan tail bertemu
}

bool isFullQueue(Queue Q) {
    return (Q.tail + 1) % MAX_QUEUE == Q.head;  // Queue penuh jika tail+1 (dengan modulus) sama dengan head
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Antrean Penuh!" << endl;  // Tidak bisa menambah elemen jika queue penuh
    } else {
        Q.info[Q.tail] = x;  // Simpan elemen di posisi tail saat ini
        Q.tail = (Q.tail + 1) % MAX_QUEUE;  // Geser tail dengan operasi modulus untuk circular movement
    }
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Antrean Kosong!" << endl;  // Tidak bisa mengambil elemen dari queue kosong
        return -1;  // Nilai error
    } else {
        infotype x = Q.info[Q.head];  // Ambil elemen dari posisi head
        Q.head = (Q.head + 1) % MAX_QUEUE;  // Geser head dengan operasi modulus
        return x;  // Kembalikan elemen yang diambil
    }
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " | ";  // Tampilkan posisi head dan tail
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;  // Tampilkan status queue kosong
    } else {
        int i = Q.head;  // Mulai dari head
        while (i != Q.tail) {  // Iterasi sampai mencapai tail
            cout << Q.info[i] << " ";  // Tampilkan elemen
            i = (i + 1) % MAX_QUEUE;  // Pindah ke elemen berikutnya dengan circular movement
        }
        cout << endl;
    }
}