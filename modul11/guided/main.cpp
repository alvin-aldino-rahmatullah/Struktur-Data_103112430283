#include "graph.h" 
#include <iostream>         

using namespace std;        

int main() {               
    Graph G; // Mendeklarasikan variabel Graph
    createGraph(G); // Menginisialisasi graph agar kondisi awal kosong

    // Menambahkan Node A, B, C, D
    insertNode(G, 'A');
    insertNode(G, 'B');     
    insertNode(G, 'C');     
    insertNode(G, 'D');     

    // Menghubungkan Node 
    connectNode(G, 'A', 'B'); 
    connectNode(G, 'A', 'C'); 
    connectNode(G, 'B', 'D'); 
    connectNode(G, 'C', 'D'); 

    cout << "Isi Graph:" << endl; 
    printGraph(G);                // Menampilkan seluruh isi graph beserta relasi node

    return 0;
}
