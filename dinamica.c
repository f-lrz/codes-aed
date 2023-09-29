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


int main(){

    listasimpenc *lista;

    lista = inicializa_listasimpenc();

    insere_listasimpenc_ordenado(&lista, 10);
    insere_listasimpenc_ordenado(&lista, 20);
    insere_listasimpenc_ordenado(&lista, 15);
    insere_listasimpenc_ordenado(&lista, 30);

    printf("\n");
    imprime_listasimpenc(lista);
    printf("\n");
    

    return 0;
}