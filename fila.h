#ifndef FILA_H
#define FILA_H
#include "pilha.h"
#include <stdio.h>
#define MAX 100

typedef int oitem;

typedef struct{
    int ini, fim;
    oitem item[MAX];
}fila;


void inicializa_fila(fila *f){
    f->ini = f->fim = MAX - 1;
}

int fila_vazia(fila *f){
    if(f->ini == f->fim) return 1;
    return 0;
}

int proximo(int pos){
    if(pos == MAX - 1) return 0;
    return ++pos;
}

int fila_cheia(fila *f){
    if(proximo(f->fim) == f->ini) return 1;
    return 0;
}

int insere_fila(fila *f, oitem aux){
    if (fila_cheia(f)) return 0;
    f->fim = proximo(f->fim);
    f->item[f->fim] = aux;
    return 1;
}

int remove_fila(fila *f, oitem *aux){
    if(fila_vazia(f)) return 0;
    f->ini = proximo(f->ini);
    *aux = f->item[f->ini];
    return 1;
}

void imprime_fila(fila f){
    oitem aux;
    while(!fila_vazia(&f)){
        remove_fila(&f, &aux);
        printf("%d\n", aux);
    }
}

int tamanho_fila(fila *f){
    if(fila_vazia(f)) return 0;
    if(f->ini < f->fim) return f->fim - f->ini;
    return MAX -1 - f->ini + f->fim + 1;
}

int tamanho_fila1(fila f){
    int cont = 0;
    oitem aux;
    while(!fila_vazia(&f)){
        remove_fila(&f, &aux);
        cont++;
    }

    return cont;
}

void inverte_fila(fila *f)
{
    pilha paux;
    oitem e;
    inicializa_pilha(&paux);
    while(!fila_vazia(f))
    {
        remove_fila(f,&e);
        push(&paux, e);
    }
    while(!pilha_vazia(&paux))
    {
        pop(&paux, &e);
        insere_fila(f,e);
    }
}

int primeiro_fila(fila *f, oitem *aux){
	if(fila_vazia(f)) return 0;
	*aux = f->item[f->ini];
	return 1;
}

#endif
