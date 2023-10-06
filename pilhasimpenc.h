#ifndef PILHASIMPENC
#define PILHASIMPENC
#include <stdio.h>
#include <stdlib.h>

typedef int oitem; 

typedef struct no_aux{   
  oitem info;   
  struct no_aux *prox;   
} no; 


typedef struct{   
  no *topo;   
} pilha;


pilha *inicializa_pilha (){
  pilha *pilha = (pilha*) malloc(sizeof(pilha));   
  pilha->topo = NULL;   
  return pilha;
}  

int pilha_vazia (pilha *pilha){   
  if(pilha->topo == NULL) return 1;
  return 0;
}

no *aloca(){
  no* pt;
	pt = (no*) malloc(sizeof(no));
	return pt;
}

int push (pilha *pilha, oitem e){   
  no *novo_no;   

  novo_no = aloca();

  if(!novo_no) return 0;

  novo_no->info = e;  

  if(pilha_vazia(pilha)) novo_no->prox = NULL;

  else novo_no->prox = pilha->topo;  

  pilha->topo = novo_no; 

  return 1;   
}        


int pop (pilha *pilha, oitem *e){   
  no *aux;

  if (pilha_vazia(pilha)) return 0;
  
  *e = pilha->topo->info;
  
  aux = pilha->topo;

  pilha->topo = pilha->topo->prox;

  free(aux);
  
  aux = NULL;
  
  return 1;   
}        

int top (pilha *pilha, oitem *e){   
  no *aux;

  if (pilha_vazia(pilha)) return 0;

  *e = pilha->topo->info;
  
  return 1;   
}        



pilha *destroi_pilha(pilha *pilha){    
	no *atu = pilha->topo, *aux;
  oitem e;

	while (atu != NULL){
	  aux = atu->prox;
    pop(pilha, &e);  
		atu = aux; 
  }

	pilha->topo = NULL;
	free(pilha);
	return NULL;
}



void imprime_pilha(pilha *pilha){
  pilha *pilha_aux;
  oitem e;
     
  pilha_aux=inicializa_pilha();
     
	while (!pilha_vazia(pilha)){
    pop(pilha,&e);
    printf("%d ", e);
    push(pilha_aux, e);           
  }
	
	while (!pilha_vazia(pilha_aux)){
    pop(pilha_aux,&e);
    push(pilha, e);           
  }
  
  pilha_aux = destroi_pilha(pilha_aux);

}

#endif

