#include "graph.h" 

void createGraph(Graph &G) {     
    G.first = NULL; // Menandakan bahwa graph masih kosong
}

// Fungsi untuk mengalokasikan node baru
adrNode allocateNode(infoGraph X) {
    adrNode P = new ElmNode;// Mengalokasikan memori untuk satu node graph
    P->info = X; // Mengisi informasi node dengan nilai X
    P->visited = false; // Menandai node sebagai belum dikunjungi
    P->firstEdge = NULL; // Menginisialisasi list edge kosong
    P->next = NULL; // Menginisialisasi pointer ke node berikutnya
    return P; // Mengembalikan alamat node yang baru dibuat
}

// Prosedur untuk menambahkan node ke graph
void insertNode(Graph &G, infoGraph X) { 
    adrNode P = allocateNode(X);       
    if (G.first == NULL) {          
        G.first = P; // Jika kosong, node menjadi node pertama
    } else {
        adrNode Q = G.first;           
        while (Q->next != NULL) { // Menelusuri hingga node terakhir
            Q = Q->next; // Pindah ke node berikutnya
        }
        Q->next = P; // Menyambungkan node baru di akhir list
    }
}
