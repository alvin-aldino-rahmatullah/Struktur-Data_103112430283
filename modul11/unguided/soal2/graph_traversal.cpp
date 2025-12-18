#include "graph.h"                

void resetVisited(Graph &G) {       
    adrNode P = G.first;            
    while (P != NULL) { 
        P->visited = false;// set visited menjadi false
        P = P->next; // pindah ke node berikutnya
    }
}

void printDFS(Graph &G, adrNode N) {
    if (N == NULL) {                
        return; //jika node kosong maka keluar
    }

    if (N->visited == true) {      
        return; // jika sudah dikunjungi maka keluar
    }

    N->visited = true; // tandai node dikunjungi
    cout << N->info << " "; // cetak node

    adrEdge E = N->firstEdge; 
    while (E != NULL) {             
        printDFS(G, E->node); // DFS ke node tujuan
        E = E->next; // pindah ke edge berikutnya
    }
}
