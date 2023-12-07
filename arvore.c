#include <stdio.h>
#include <string.h>
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

int main(){
	
	arvore raiz;
	raiz = inicializa_arvore();

	int h = 5;
	int m = 6;
	int r = 8;
	int o = 7;
	int d = 3;
	int f = 4;
	int c = 2;
	int b = 1;

	insere_no(&raiz, h);
	insere_no(&raiz, m);
	insere_no(&raiz, r);
	insere_no(&raiz, o);
	insere_no(&raiz, d);
	insere_no(&raiz, f);
	insere_no(&raiz, c);
	insere_no(&raiz, b);

	//pre_ordem(raiz);

	inv_ordem(raiz);

	//printf("%d", qnt_niveis(raiz) - 1);

	return 0;
}

