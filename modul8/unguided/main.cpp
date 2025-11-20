#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl; 
    
    Queue Q; // Deklarasi variabel
    createQueue(Q); // Memanggil fungsi 
    
    cout << "------------------" << endl;
    cout << "H - T : Queue Info" << endl; 
    cout << "------------------" << endl;
    printInfo(Q); // Menampilkan kondisi awal queue (kosong)
    enqueue(Q, 5); printInfo(Q);  // Menambah elemen 5 dan tampilkan queue
    enqueue(Q, 2); printInfo(Q);  // Menambah elemen 2 dan tampilkan queue
    enqueue(Q, 7); printInfo(Q);  // Menambah elemen 7 dan tampilkan queue
    dequeue(Q); printInfo(Q); // Menghapus elemen depan dan tampilkan queue
    dequeue(Q); printInfo(Q); // Menghapus elemen depan dan tampilkan queue
    enqueue(Q, 4); printInfo(Q);  // Menambah elemen 4 dan tampilkan queue
    dequeue(Q); printInfo(Q); // Menghapus elemen depan dan tampilkan queue
    dequeue(Q); printInfo(Q); // Menghapus elemen depan dan tampilkan queue
    return 0; 
}