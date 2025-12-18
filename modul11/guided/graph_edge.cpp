#include "graph.h"                         

// Fungsi untuk mencari node berdasarkan info
adrNode findNode(Graph G, infoGraph X) {  
    adrNode P = G.first;                 
    while (P != NULL) {                   
        if (P->info == X) return P; // Jika info node cocok, kembalikan alamat node
        P = P->next; // Pindah ke node berikutnya
    }
    return NULL; // Mengembalikan NULL jika node tidak ditemukan
}

// Prosedur menghubungkan dua node
void connectNode(Graph &G, infoGraph start, infoGraph end) { 
    adrNode pStart = findNode(G, start); // Mencari node awal
    adrNode pEnd = findNode(G, end); // Mencari node tujuan

    if (pStart != NULL && pEnd != NULL) { // Memastikan kedua node ditemukan
        adrEdge newEdge = new ElmEdge; // Mengalokasikan memori edge baru
        newEdge->node = pEnd; // Menyimpan alamat node tujuan
        newEdge->next = pStart->firstEdge; // Menyisipkan edge di awal list edge
        pStart->firstEdge = newEdge; // Menghubungkan edge ke node awal
    }
}
