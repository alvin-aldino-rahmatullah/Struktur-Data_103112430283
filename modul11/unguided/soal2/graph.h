#ifndef GRAPH_H                 
#define GRAPH_H

#include <iostream>            
using namespace std;         

typedef char infoGraph;          

typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmEdge {                
    adrNode node; // node tujuan
    adrEdge next; // edge berikutnya
};

struct ElmNode {               
    infoGraph info;             
    bool visited;                
    adrEdge firstEdge;         
    adrNode next;                
};

struct Graph {                 
    adrNode first;            
};

void createGraph(Graph &G);      
adrNode allocateNode(infoGraph X); 
void insertNode(Graph &G, infoGraph X); 
void connectNode(Graph &G, infoGraph start, infoGraph end); 
void printGraph(Graph &G);
// traversal
adrNode findNode(Graph G, infoGraph X); // deklarasi findNode
void resetVisited(Graph &G); // mengosongkan status visited
void printDFS(Graph &G, adrNode N); // menampilkan DFS

#endif