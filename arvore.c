#include "arvorebb.h"
#include <stdio.h>

int main(){
    arvore arv;

    arv = inicializa_arvore();

    insere_no(&arv, 3);
    insere_no(&arv, 9);
    insere_no(&arv, 6);

    em_ordem(&arv);

}