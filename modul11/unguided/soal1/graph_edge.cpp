#include "graph.h"               

adrNode findNode(Graph G, infoGraph X) { 
    adrNode P = G.first;         // mencari node, dimulai dari node pertama
    while (P != NULL) {          
        if (P->info == X) {      
            return P;            
        }
        P = P->next;             
    }
    return NULL;                 
}

// menghubungkan node
void connectNode(Graph &G, infoGraph start, infoGraph end) { 
    adrNode pStart = findNode(G, start); // node awal
    adrNode pEnd = findNode(G, end);     // node tujuan

    if (pStart != NULL && pEnd != NULL) { // jika kedua node ada
        adrEdge E = new ElmEdge;          
        E->node = pEnd;                  
        E->next = pStart->firstEdge;     
        pStart->firstEdge = E;           
    }
}
