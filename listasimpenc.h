#ifndef LISTASIMPENC_H
#define LISTASIMPENC_H
#include <stdio.h>
#include <stdlib.h>

typedef int oitem;

typedef struct no{
    oitem info;
    struct no *prox;
}listasimpenc;



listasimpenc *inicializa_listasimpenc(){
    return NULL;
}

int listasimpenc_vazia(listasimpenc *lista){
    if(lista == NULL) return 1;

    return 0;
}

listasimpenc *aloca_listasimpenc(){
    listasimpenc *novono;
    novono = (listasimpenc*) malloc(sizeof(listasimpenc));

    return novono;
}

int insere_listasimpenc_no_fim(listasimpenc **lista, oitem e){
    listasimpenc *novono, *atual;

    novono = aloca_listasimpenc();

    if(novono == NULL) return 0;

    novono->info = e;
    novono->prox = NULL;

    if(listasimpenc_vazia(*lista)) *lista = novono;

    else{
        atual = *lista;
        while(atual->prox != NULL) atual = atual->prox;
        atual->prox = novono;
    }

    return 1;
}


int remove_listasimpenc(listasimpenc **lista, oitem e){
    listasimpenc *atual, *antatual;
    atual = *lista;
    antatual = NULL;

    while((atual != NULL) && (atual->info != e)){
        antatual = atual;
        atual = atual->prox;
    }

    if(atual == NULL) return 0;

    if(antatual == NULL) *lista = atual->prox;
    else antatual->prox = atual->prox;

    free(atual);
    atual = NULL;

    return 1;
}

void imprime_listasimpenc(listasimpenc *lista){
    listasimpenc *atual;
    
    atual = lista;

    while(atual != NULL){
        printf("%d\n", atual->info);
        atual = atual->prox;
    }
}

listasimpenc *busca_listasimpenc(listasimpenc *lista, oitem e){
    listasimpenc *atual;
    atual = lista;

    while((atual != NULL) && (atual->info != e)) atual = atual->prox;

    if(atual == NULL) return NULL;

    return atual;
}

int tamanho_listasimpenc(listasimpenc *lista){
    int cont = 0;
    listasimpenc *atual;
    atual = lista;

    while(atual != NULL){
        cont++; 
        atual = atual->prox;
    }

    return cont;
}

#endif

