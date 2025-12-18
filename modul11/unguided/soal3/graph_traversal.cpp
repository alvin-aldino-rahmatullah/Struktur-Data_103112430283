#include "graph.h"        

void resetVisited(Graph &G) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = false;
        P = P->next;
    }
}


void enqueue(adrQueue &front, adrQueue &rear, adrNode N) { // menambah queue
    adrQueue Q = new ElmQueue; // alokasi queue baru
    Q->node = N;                   
    Q->next = NULL;// next kosong

    if (front == NULL) {           
        front = Q; // front menunjuk Q
        rear = Q; // rear menunjuk Q
    } else {                         
        rear->next = Q; // sambungkan ke belakang
        rear = Q; // geser rear
    }
}

adrNode dequeue(adrQueue &front, adrQueue &rear) { 
    adrQueue Q = front;             
    adrNode N = Q->node;          

    front = front->next;           
    if (front == NULL) {            
        rear = NULL;     
    }

    delete Q;                
    return N;               
}

void printBFS(Graph &G, adrNode N) { 
    if (N == NULL) {              
        return;                 
    }

    adrQueue front = NULL;         
    adrQueue rear = NULL;       

    N->visited = true;             
    enqueue(front, rear, N);       

    while (front != NULL) { // selama queue tidak kosong
        adrNode P = dequeue(front, rear); // ambil node
        cout << P->info << " "; // cetak node

        adrEdge E = P->firstEdge; // ambil edge
        while (E != NULL) { // selama edge ada
            if (E->node->visited == false) { // jika belum dikunjungi
                E->node->visited = true;     // tandai visited
                enqueue(front, rear, E->node); // masukkan queue
            }
            E = E->next; // pindah edge
        }
    }
}
