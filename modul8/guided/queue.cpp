#include "queue.h"
#include <iostream>

using namespace std;

//Definisi prosedur untuk membuat queue kosong
void createQueue(Queue &Q)
{
    Q.head = 0;
    Q.tail = 0;
    Q.count = 0; // Set jumlah elemen menjadi 0
}

//Definisi fungsi untuk memeriksa apakah queue kosong
bool isEmpty(Queue Q)
{
    return Q.count == 0; // Queue kosong jika count adalah 0
}

//Definisi fungsi untuk memeriksa apakah queue penuh
bool isFull(Queue Q)
{
    return Q.count == MAX_QUEUE; // Kembali true jika count mencapai kapasitas maksimum
}

//Definisi prosedur untuk menambahkan elemen ke dalam queue
void enqueue(Queue &Q, int X)
{
    if (!isFull(Q)) // jika queue tidak penuh
    {
        Q.info[Q.tail] = X; // masukkan data x ke posisi tail
        // pindahkan ekor secara memutar (circular)
        Q.tail = (Q.tail + 1) % MAX_QUEUE; // Update tail dengan wrap-around
        Q.count++; // Increment jumlah elemen
    }
    else // jika queue penuh
    {
        cout << "Queue is full!" << endl; // tampilkan pesan queue penuh
    }
}

//Definisi fungsi untuk menghapus elemen dari dalam queue
int dequeue(Queue &Q)
{
    if (!isEmpty(Q)) // jika queue tidak kosong
    {
        int X = Q.info[Q.head]; // ambil data dari posisi head
        // pindahkan kepala secara memutar (circular)
        Q.head = (Q.head + 1) % MAX_QUEUE; // Update head dengan wrap-around
        Q.count--; // Decrement jumlah elemen
        return X; // kembalikan nilai yang di dequeue
    }
    else // jika queue kosong
    {
        cout << "Queue is empty!" << endl; // tampilkan pesan queue kosong
        return -1; // kembalikan nilai indikasi error
    }
}

void printInfo(Queue Q)
{
    cout << "Isi queue: [";
    if (!isEmpty(Q))
    {
        int i = Q.head; // mulai dari head
        int n = 0; // menghitung jumlah elemen yang sudah dicetak
        while (n < Q.count) // ulangi sebanyak jumlah elemen dalam queue
        {
            cout << Q.info[i];
            if (n < Q.count - 1) {
                cout << " "; // tambah spasi antara elemen kecuali elemen terakhir
            }
            i = (i + 1) % MAX_QUEUE; // Update indeks dengan wrap-around
            n++; // tambah penghitung
        }
    }
    else
    {
        cout << "Queue is empty!"; // pesan jika queue kosong
    }
    cout << "]" << endl;
}