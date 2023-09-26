#ifndef PILHA_H
#define PILHA_H
#include <stdio.h>
#define MAX 100

typedef int oitem;

typedef struct{
    int topo;
    oitem item[MAX];
}pilha;


void inicializa_pilha(pilha *p){
    p->topo = -1;
}


int pilha_vazia(pilha *p){
    if(p->topo == -1) return 1;
    return 0;
}


int pilha_cheia(pilha *p){
    if(p->topo == MAX - 1) return 1;
    return 0;
}


int push(pilha *p, oitem valor){
    if(pilha_cheia(p)) return 0;
    p->topo++;
    p->item[p->topo] = valor;
    return 1;
}


int pop(pilha *p, oitem *aux){
    if(pilha_vazia(p)) return 0;
    *aux = p->item[p->topo];
    p->topo--;
    return 1;
}


int top(pilha *p, oitem *aux){
    if(pilha_vazia(p)) return 0;
    *aux = p->item[p->topo];
    return 1;
}


void imprime_pilha(pilha p){
    oitem aux;
    printf("\n\n");
    while(!pilha_vazia(&p)){
        pop(&p, &aux);
        printf("%d ", aux);
    }
    printf(".");
}


int altura_pilha(pilha *p){
    return p->topo + 1;
}


void retira_impares(pilha *p){
    pilha paux;
    oitem n;

    inicializa_pilha(&paux);

    while(!pilha_vazia(p)){
        pop(p, &n);
        if(n%2 == 0) push(&paux, n);
    }

    while(!pilha_vazia(&paux)){
        pop(&paux, &n);
        push(p, n);
    }
}


int compara_pilha(pilha p1, pilha p2){
	oitem aux1, aux2;
	
	if(altura_pilha(&p1) != altura_pilha(&p2)) return 0;
	
	else{
		
		while(!pilha_vazia(&p1)){
			pop(&p1, &aux1);
			pop(&p2, &aux2);
			
			if(aux1 != aux2) return 0;
		}
		
		return 1;
	}
}


int empilha_pilha(pilha *p1, pilha *p2){
	
	pilha paux;
	oitem aux;
	
	inicializa_pilha(&paux);
	
	if(altura_pilha(p1) + altura_pilha(p2) > MAX) return 0;
	
	else{
		while(!pilha_vazia(p2)){
			pop(p2, &aux);
			push(&paux, aux);
		}
		while(!pilha_vazia(&paux)){
			pop(&paux, &aux);
			push(p1, aux);
		}
	}
	
	return 1;
}


#endif


