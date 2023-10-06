#ifndef PILHASIMPENC
#define PILHASIMPENC
#include <stdio.h>
#include <stdlib.h>

typedef int oitem; 

typedef struct noaux{   
  oitem info;   
  struct noaux *prox;   
} no; 


typedef struct{   
  no *topo;   
} pilhasimpenc;


pilhasimpenc* inicializa_pilhasimpenc(){
  pilhasimpenc *pilha = (pilhasimpenc*) malloc(sizeof(pilhasimpenc));   
  pilha->topo = NULL;   
  return pilha;
}  

int pilhasimpenc_vazia(pilhasimpenc *pilha){   
  if(pilha->topo == NULL) return 1;
  return 0;
}

no* aloca_pilhasimpenc(){
  no* endmemno;
	endmemno = (no*) malloc(sizeof(no));
	return endmemno;
}

int push_pilhasimpenc(pilhasimpenc *pilha, oitem e){   
  no *novo_no;   

  novo_no = aloca_pilhasimpenc();

  if(!novo_no) return 0;

  novo_no->info = e;  

  if(pilhasimpenc_vazia(pilha)) novo_no->prox = NULL;

  else novo_no->prox = pilha->topo;  

  pilha->topo = novo_no; 

  return 1;   
}        


int pop_pilhasimpenc(pilhasimpenc *pilha, oitem *e){   
  no *aux;

  if (pilhasimpenc_vazia(pilha)) return 0;
  
  *e = pilha->topo->info;
  
  aux = pilha->topo;

  pilha->topo = pilha->topo->prox;

  free(aux);
  
  aux = NULL;
  
  return 1;   
}        

int top_pilhasimpenc(pilhasimpenc *pilha, oitem *e){   
  no *aux;

  if (pilhasimpenc_vazia(pilha)) return 0;

  *e = pilha->topo->info;
  
  return 1;   
}        



pilhasimpenc *destroi_pilhasimpenc(pilhasimpenc *pilha){    
	no *atu = pilha->topo, *aux;
  oitem e;

	while (atu != NULL){
	  aux = atu->prox;
    pop_pilhasimpenc(pilha, &e);  
		atu = aux; 
  }

	pilha->topo = NULL;
	free(pilha);
	return NULL;
}



void imprime_pilhasimpenc(pilhasimpenc *pilha){
  pilhasimpenc *pilha_aux;
  oitem e;
     
  pilha_aux = inicializa_pilhasimpenc();
     
	while (!pilhasimpenc_vazia(pilha)){
    pop_pilhasimpenc(pilha,&e);
    printf("%d ", e);
    push_pilhasimpenc(pilha_aux, e);           
  }
	
	while (!pilhasimpenc_vazia(pilha_aux)){
    pop_pilhasimpenc(pilha_aux,&e);
    push_pilhasimpenc(pilha, e);           
  }
  
  pilha_aux = destroi_pilhasimpenc(pilha_aux);

}

#endif

