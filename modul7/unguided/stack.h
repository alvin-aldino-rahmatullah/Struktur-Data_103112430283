#ifndef STACK_H
#define STACK_H

#include <iostream>
#define MaxEl 20
#define Nil -1

typedef int infotype;

struct Stack 
{
    infotype info[MaxEl]; // Array penyimpan elemen stack
    int TOP; // Indeks elemen teratas stack
};

// DEKLARASI FUNGSI
void CreateStack(Stack &S);
bool isEmpty(Stack S);        // DITAMBAHKAN: deklarasi isEmpty
bool isFull(Stack S);         // DITAMBAHKAN: deklarasi isFull
void push(Stack &S, infotype X); // Menambahkan elemen x ke stack s
infotype pop(Stack &S); // Menghapus elemen teratas dari stack s dan mengembalikan nilainya
void printInfo(Stack S); // Mencetak isi stack s
void balikStack(Stack &S); // Membalik urutan elemen dalam stack s

#endif