#include "pilhasimpenc.h"
#include "filasimpenc.h"
#include "listadupenc.h"

/*#include "pilhasimpencsoussa.h"
#include "filasimpencsoussa.h"
#include "listadupencsoussa.h"*/


int main(){

    /*tp_pilhasimpencsoussa *pses;
    tp_filasimpencsoussa *fses;
    tp_listadupencsoussa *ldes;*/

    pilhasimpenc *pse;
    filasimpenc *fse;
    listadupenc *lde;

    /*pses = inicializa_pilhasimpencsoussa();
    fses = inicializa_filasimpencsoussa();
    ldes = inicializa_listadupencsoussa();*/

    pse = inicializa_pilhasimpenc();
    fse = inicializa_filasimpenc();
    lde = inicializa_listadupenc();

    /*push_pilhasimpencsoussa(pses, 1);
    push_pilhasimpencsoussa(pses, 2);
    push_pilhasimpencsoussa(pses, 3);
    imprime_pilhasimpencsoussa(pses);*/

    printf("\n");

    push_pilhasimpenc(pse, 1);
    push_pilhasimpenc(pse, 2);
    push_pilhasimpenc(pse, 3);
    imprime_pilhasimpenc(pse);

    printf("\n");
    printf("\n");

    /*insere_filasimpencsoussa(fses, 10);
    insere_filasimpencsoussa(fses, 20);
    insere_filasimpencsoussa(fses, 30);
    imprime_filasimpencsoussa(fses);*/

    insere_filasimpenc(fse, 10);
    insere_filasimpenc(fse, 20);
    insere_filasimpenc(fse, 30);
    imprime_filasimpenc(fse);

    printf("\n");
    printf("\n");

    /*insere_listadupencsoussa_no_fim(ldes, 100);
    insere_listadupencsoussa_no_fim(ldes, 200);
    insere_listadupencsoussa_no_fim(ldes, 300);
    imprime_listadupencsoussa(ldes, 1);*/

    insere_listadupenc_no_fim(lde, 11);
    insere_listadupenc_no_fim(lde, 22);
    insere_listadupenc_no_fim(lde, 33);
    imprime_listadupenc(lde, 2);

    printf("\n");
    printf("\n");
    
    return 0;
}