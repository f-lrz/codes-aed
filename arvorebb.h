#ifndef ARVOREBB_H
#define ARVOREBB_H

#include <stdio.h>
#include <stdlib.h>


typedef int oitem;

typedef struct no{
    struct no *dir;
    oitem info;
    struct no *esq;
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

    novo->dir = NULL;
    novo->info = e;
    novo->esq = NULL;

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

int qnt_niveis(arvore raiz);

void inv_ordem(no *atu){
    if(atu != NULL){
        inv_ordem(atu->dir);
        inv_ordem(atu->esq);
        printf("\nNivel %d: %d", qnt_niveis(atu) - 1, atu->info);
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
    if(raiz == NULL) return 0;

    int nivel_esq;
    int nivel_dir;

    nivel_esq = qnt_niveis(raiz->esq);
    nivel_dir = qnt_niveis(raiz->dir);

    if(nivel_esq > nivel_dir) return nivel_esq + 1;
    else return nivel_dir + 1;

}

int qnt_nos(arvore raiz){
    if(raiz == NULL) return 0;

    int total_esq;
    int total_dir;

    total_esq = qnt_nos(raiz->esq);
    total_dir = qnt_nos(raiz->dir);

    return total_esq + total_dir + 1;
}


int remove_no(arvore *raiz, oitem e ) {
	no *p = *raiz;
    no *ant = NULL;
    no *sub;
    no *pai;
    no *filho;

	while((p != NULL) && (p->info != e)){
		ant = p;

		if (e < p->info) p = p->esq;

		else p = p->dir;
	}

	if(p == NULL) return 0;

	if(p->esq == NULL) sub = p->dir;
	
    else{
		if (p->dir == NULL) sub = p->esq;

		else{
	        pai = p; 
            sub = p->dir; 
            filho = sub->esq;

			while(filho != NULL){
				pai = sub;  
                sub = filho;  
                filho = sub->esq;
			}

			if(pai != p){
				pai->esq = sub->dir;
				sub->dir = p->dir;
			}

			sub->esq = p->esq;
		}

		if(ant == NULL) *raiz = sub;

		else{
			if (p == ant->esq) ant->esq = sub;
            else ant->dir = sub;
        }

		free(p);
    }
	return 1;
}


void destroi_no(no *noh){
   if(noh == NULL) return;
   destroi_no(noh->esq);
   destroi_no(noh->dir);
 //  printf("\n %d ", no->info);
   free(noh);
   noh = NULL;
   return;
}

void destroi_arvore(arvore *raiz){
   if(*raiz == NULL) return;
   destroi_no(*raiz);
  // free(*raiz);
   *raiz = NULL;
}


#endif