#include "listadupenc.h"

/*#include "pilhasimpencsoussa.h"
#include "filasimpencsoussa.h"
#include "listadupencsoussa.h"*/

int jogo(listadupenc **lista){

    int dado;

    insere_listadupenc_no_fim(*lista,'a');
    insere_listadupenc_no_fim(*lista,'b');
    insere_listadupenc_no_fim(*lista,'c');
    insere_listadupenc_no_fim(*lista,'0');
    insere_listadupenc_no_fim(*lista,'e');
    insere_listadupenc_no_fim(*lista,'f');
    insere_listadupenc_no_fim(*lista,'g');
    insere_listadupenc_no_fim(*lista,'1');
    insere_listadupenc_no_fim(*lista,'h');
    insere_listadupenc_no_fim(*lista,'i');

    imprime_listadupenc(lista, 1);

    return 0;
}

int main(){

    listadupenc *caminho;
    caminho = aloca_listadupenc;

    printf("O dado foi lançado %d vezes.\n", jogo(&caminho));
    
    printf("\n");
    printf("\n");
    
    return 0;
}