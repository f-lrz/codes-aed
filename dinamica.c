#include "listasimpenc.h"

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
        if(atual->info % 2 == 1){
            antatual = atual->prox;
            free(atual);
        }
        antatual = atual;
        atual = atual->prox;
    }
}

int main(){

    listasimpenc *lista;

    lista = inicializa_listasimpenc();

    insere_listasimpenc_no_fim(&lista, 10);
    insere_listasimpenc_no_fim(&lista, 15);
    insere_listasimpenc_no_fim(&lista, 20);
    insere_listasimpenc_no_fim(&lista, 30);
    insere_listasimpenc_no_fim(&lista, 40);
    printf("\n");
    imprime_listasimpenc(lista);
    destroi_impar_listasimpenc(&lista);
    imprime_listasimpenc(lista);
    printf("\n");
    

    return 0;
}