#include "arvorebb.h"
#include <stdio.h>

int main(){
    arvore arv;

    arv = inicializa_arvore();

    insere_no(&arv, 3);
    insere_no(&arv, 9);
    insere_no(&arv, 6);
    insere_no(&arv, 7);
    insere_no(&arv, 1);
    insere_no(&arv, 2);
    insere_no(&arv, 10);
    insere_no(&arv, 11);
    insere_no(&arv, 12);

    printf("%d %d\n", qnt_niveis(arv), qnt_nos(arv));

}