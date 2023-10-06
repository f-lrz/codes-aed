#include "listasimpenc.h"
#include "listadupenc.h"
#include "pilhasimpenc.h"
#include "filasimpenc.h"

int main(){

    pilhasimpenc *pse;
    filasimpenc *fse;
    listadupenc *lde;
    
    push_pilhasimpenc(pse, 1);
    push_pilhasimpenc(pse, 2);
    push_pilhasimpenc(pse, 3);
    imprime_pilhasimpenc(pse);
    printf("\n");
    printf("\n");

    insere_filasimpenc(fse, 10);
    insere_filasimpenc(fse, 20);
    insere_filasimpenc(fse, 30);
    imprime_filasimpenc(fse);
    printf("\n");
    printf("\n");

    insere_listadupenc_no_fim(lde, 100);
    insere_listadupenc_no_fim(lde, 200);
    insere_listadupenc_no_fim(lde, 300);
    imprime_listadupenc(lde, 1);
    printf("\n");
    printf("\n");


    
    return 0;
}