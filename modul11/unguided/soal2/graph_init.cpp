#include "graph.h"               

void createGraph(Graph &G) {     
    G.first = NULL;        
}

// fungsi alokasi node
adrNode allocateNode(infoGraph X) { 
    adrNode P = new ElmNode; // alokasi memori node
    P->info = X;              
    P->visited = false; // node belum dikunjungi
    P->firstEdge = NULL;    
    P->next = NULL; // belum ada node berikutnya
    return P; // mengembalikan node
}

// menambah node ke graph
void insertNode(Graph &G, infoGraph X) { 
    adrNode P = allocateNode(X); // membuat node baru
    if (G.first == NULL) {       
        G.first = P;             //jika graph kosong, node akan menjadi node pertama
    } else {                     // jika graph tidak kosong
        adrNode Q = G.first;    
        while (Q->next != NULL) { // mencari node terakhir
            Q = Q->next;         // geser ke node berikutnya
        }
        Q->next = P;         
    }
}
