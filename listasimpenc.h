#ifndef LISTASIMPENC_H
#define LISTASIMPENC_H
#include "PILHA.H"
#include "FILA.H"
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

void destroi_listasimpenc(listasimpenc **lista){
    listasimpenc *atual;

    atual = *lista;

    while(atual != NULL){
        *lista = atual->prox;
        free(atual);
        atual = *lista;
    }

    *lista = NULL;
}







int insere_listasimpenc_ordenado(listasimpenc **lista, oitem e){
    listasimpenc *novono, *antatual, *atual;

    novono = aloca_listasimpenc();

    if(novono == NULL) return 0;

    novono->info = e;

    atual = *lista;
    antatual = NULL;

    while((atual != NULL) && (atual->info < novono->info)){
        antatual = atual;
        atual = atual->prox;
    }

    if(antatual == NULL) *lista = novono;
    else antatual->prox = novono;

    novono->prox = atual;

    return 1;
}

int no_maior_q_n(listasimpenc **lista, int n){
    listasimpenc *atual;
    int cont = 0;

    atual = *lista;

    while(atual != NULL){
        if(atual->info > n) cont++;
        atual = atual->prox; 
    }


    return cont;
}

int listasimpenc_iguais(listasimpenc **l1, listasimpenc **l2){
    listasimpenc *atual1, *atual2;
    int tam1 = tamanho_listasimpenc(*l1), tam2 = tamanho_listasimpenc(*l2);

    atual1 = *l1;
    atual2 = *l2;

    if(tam1 != tam2) return 0;

    while(atual1 != NULL){
        if(atual1->info != atual2->info) return 0;
        atual1 = atual1->prox;
        atual2 = atual2->prox;
    }

    return 1;
}

void destroi_impar_listasimpenc(listasimpenc **l){
    listasimpenc *atual, *antatual;

    atual = *l;
    antatual = NULL;
    
    while(atual != NULL){
        antatual = atual;
        atual = atual->prox;
        if(antatual->info % 2 != 0){
            remove_listasimpenc(l, antatual->info);
        }
    }
}
int conecta_listasimpenc(listasimpenc **l1, listasimpenc **l2){
    listasimpenc *atual;

    atual = *l1;

    while(atual->prox != NULL) atual = atual->prox;

    atual->prox = *l2;
    
    atual = *l2;

    while(atual->prox != NULL) atual = atual->prox;
    atual->prox = *l1;

    *l2 = *l1;

    return 1;
}






#endif

