#ifndef STACK_H
#define STACK_H

#include <iostream>
#define MaxEl 20
#define Nil -1

typedef int infotype;

struct Stack 
{
    infotype  info[MaxEl]; // Array penyimpan elemen stack
    int TOP; // Indeks elemen teratas stack
};

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, int X); // Menambahkan elemen x ke stack s
infotype pop(Stack &S); // Menghapus elemen teratas dari stack s dan mengembalikan nilainya
void printInfo(Stack S); // Mencetak isi stack s
void balikStack(Stack &S); // Membalik urutan elemen dalam stack s
#endif 