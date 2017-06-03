#ifndef _MAIN_H_
#define _MAIN_H_

#include <iostream>
#include <stdlib.h>

using namespace std;

struct node
{
    int info;
    node *left;
    node *right;
};

node* newNode(int dado);
int insere(node **no, int dado);
void imprime(node* no, int i);
void achaNULL (node* no);
void mostraArvore(node* no, int n_elementos);
void substitui(node* no, node* substituto);
int remove(node** raiz, int dado);

#endif