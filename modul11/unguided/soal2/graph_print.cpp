#include "graph.h"              

  // menampilkan graph
void printGraph(Graph &G) {    
    adrNode P = G.first; // mulai dari node pertama
    while (P != NULL) {         
        cout << P->info << " -> "; //selama node ada, cetak node
        adrEdge E = P->firstEdge; 
        while (E != NULL) {     
            cout << E->node->info << " "; 
            E = E->next; // pindah ke edge berikutnya
        }
        cout << endl; // pindah baris
        P = P->next; // pindah ke node berikutnya
    }
}