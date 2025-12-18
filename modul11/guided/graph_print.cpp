#include "graph.h"

 // Prosedur untuk menampilkan isi graph
void printGraph(Graph &G) {
    adrNode P = G.first;               
    while (P != NULL) { // Loop selama masih ada node
        cout << "Node " << P->info << " terhubung ke: "; 
        adrEdge E = P->firstEdge;     
        while (E != NULL) { // Loop selama masih ada edge
            cout << E->node->info << " "; // Menampilkan node tujuan edge
            E = E->next; // Pindah ke edge berikutnya
        }
        cout << endl; // Pindah baris setelah satu node selesai dicetak
        P = P->next; // Pindah ke node berikutnya
    }
}
