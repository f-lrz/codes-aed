#include "listasimpenc.h"

int main(){

    listasimpenc *lista1, *lista2;

    lista1 = inicializa_listasimpenc();
    lista2 = inicializa_listasimpenc();

    insere_listasimpenc_no_fim(&lista1, 10);
    insere_listasimpenc_no_fim(&lista1, 15);
    insere_listasimpenc_no_fim(&lista1, 20);
    insere_listasimpenc_no_fim(&lista2, 30);
    insere_listasimpenc_no_fim(&lista2, 40);
    insere_listasimpenc_no_fim(&lista2, 50);
    printf("\n");
    conecta_listasimpenc(&lista1, &lista2);
    imprime_listasimpenc(lista1);
    printf("\n");
    

    return 0;
}