#ifndef ARVOREBB_H
#define ARVORE_BB

#include <stdio.h>
#include <stdlib.h>



typedef int oitem;


typedef struct no{
    struct no *esq;
    oitem info;
    struct no *dir;
} no;

typedef no *arvore;



arvore inicializa_arvore(){
    return NULL;
}

int arvore_vazia(arvore raiz){
    if(raiz == NULL) return 1;
    return 0;
}

no *aloca_no(){
    no *noh;
    noh = (no*)malloc(sizeof(no));
    return noh;
}

int insere_no(arvore *raiz, oitem e){
    no *pai = NULL;
    no *novo;
    no *atu = *raiz;

    novo = aloca_no();
    if(!novo) return 0;

    novo->info = e;
    novo->esq = NULL;
    novo->dir = NULL;

    while(atu != NULL){
        pai = atu;

        if(e < atu->info) atu = atu->esq;
        else atu = atu->dir;
    }

    if(pai != NULL){
        if(e < pai->info) pai->esq = novo;
        else pai->dir = novo;
    }

    else *raiz = novo;

    return 1;
}

void pre_ordem(no *atu){
    if(atu != NULL){
        printf("\n%d", atu->info);
        pre_ordem(atu->esq);
        pre_ordem(atu->dir);
    }
}

void em_ordem(no *atu){
    if(atu != NULL){
        em_ordem(atu->esq);
        printf("\n%d", atu->info);
        em_ordem(atu->dir);
    }
}

void pos_ordem(no *atu){
    if(atu != NULL){
        pos_ordem(atu->esq);
        pos_ordem(atu->dir);
        printf("\n%d", atu->info);
    }
}

no *busca_no(no *atu, oitem e){
    while(atu != NULL){
        if(e < atu->info) atu = atu->esq;
        else{
            if(e > atu->info) atu = atu->dir;
            else return atu;
        }
    }

    return NULL;
}

arvore busca_no_com_recur(arvore atu, oitem e){
    if(atu != NULL){
        if(e < atu->info) return busca_no_com_recur(atu->esq, e);
        else{
            if(e < atu->info) return busca_no_com_recur(atu->dir, e);
            else return atu;
        }
    }
    else return NULL;
}

int qnt_niveis(arvore raiz){

}

int qnt_nos(arvore raiz){
    
}

#endif