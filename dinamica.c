#include "pilhasimpenc.h"
#include "filasimpenc.h"
#include "listadupenc.h"

#include "pilhasimpencsoussa.h"
#include "filasimpencsoussa.h"
#include "listadupencsoussa.h"

int josephus(){



}

int main(){

    tp_pilhasimpencsoussa *pse;
    tp_filasimpencsoussa *fse;
    tp_listadupencsoussa *lde;

    pse = inicializa_pilhasimpencsoussa();
    fse = inicializa_filasimpencsoussa();
    lde = inicializa_listadupencsoussa();

   

    push_pilhasimpencsoussa(pse, 1);
    push_pilhasimpencsoussa(pse, 2);
    push_pilhasimpencsoussa(pse, 3);
    imprime_pilhasimpencsoussa(pse);
    printf("\n");
    printf("\n");

    insere_filasimpencsoussa(fse, 10);
    insere_filasimpencsoussa(fse, 20);
    insere_filasimpencsoussa(fse, 30);
    imprime_filasimpencsoussa(fse);
    printf("\n");
    printf("\n");

    insere_listadupenc_no_fimsoussa(lde, 100);
    insere_listadupenc_no_fimsoussa(lde, 200);
    insere_listadupenc_no_fimsoussa(lde, 300);
    imprime_listadupencsoussa(lde, 1);
    printf("\n");
    printf("\n");


    
    return 0;
}