#include "listasimpenc.h"

int main(){

    listasimpenc *lista;

    lista = inicializa_listasimpenc();

    insere_listasimpenc_no_fim(&lista, 10);
    insere_listasimpenc_no_fim(&lista, 20);
    insere_listasimpenc_no_fim(&lista, 30);
    insere_listasimpenc_no_fim(&lista, 40);
    insere_listasimpenc_no_fim(&lista, 50);

    printf("\n");

    imprime_listasimpenc(lista);

    printf("\n");

    remove_listasimpenc(&lista, 30);
    remove_listasimpenc(&lista, 40);

    imprime_listasimpenc(lista);

    int tam = tamanho_listasimpenc(lista);

    printf("\n%d", tam);

    printf("\n");
    printf("\n");

    return 0;
}