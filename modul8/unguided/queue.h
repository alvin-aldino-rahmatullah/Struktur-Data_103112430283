#ifndef QUEUE_H 
#define QUEUE_H

#include <iostream>
using namespace std;

#define MAX_QUEUE 5
typedef int infotype; 

struct Queue {
    infotype info[MAX_QUEUE]; // Array untuk menyimpan elemen queue
    int head; // Indeks untuk elemen depan queue
    int tail; // Indeks untuk elemen belakang queue
    int count; // Penghitung jumlah elemen dalam queue
};

void createQueue(Queue &Q); // Fungsi untuk inisialisasi queue kosong
bool isEmptyQueue(Queue Q); // Fungsi untuk cek apakah queue kosong
bool isFullQueue(Queue Q); // Fungsi untuk cek apakah queue penuh
void enqueue(Queue &Q, infotype x); // Fungsi untuk menambah elemen
void printInfo(Queue Q); // Fungsi untuk menampilkan isi queue
infotype dequeue(Queue &Q); // Fungsi untuk menghapus dan mengembalikan elemen
#endif