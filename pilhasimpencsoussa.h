#include <stdio.h>
#include <stdlib.h>

typedef int tp_item; 

typedef struct tp_no_aux {   
  tp_item info;   
  struct tp_no_aux *prox;   
} tp_no; 


typedef struct {   
  tp_no *topo;   
} tp_pilhasimpencsoussa;


tp_pilhasimpencsoussa *inicializa_pilhasimpencsoussa (){
   tp_pilhasimpencsoussa *pilha=(tp_pilhasimpencsoussa*) malloc(sizeof(tp_pilhasimpencsoussa));   
   pilha->topo = NULL;   
   return pilha;
}  

int pilhasimpencsoussa_vazia (tp_pilhasimpencsoussa *pilha){   
 if (pilha->topo == NULL) return 1;
 return 0;
}

tp_no *aloca_pilhasimpencsoussa() {
	tp_no* pt;
	pt=(tp_no*) malloc(sizeof(tp_no));
	return pt;
}

int push_pilhasimpencsoussa (tp_pilhasimpencsoussa *pilha, tp_item e){   
  tp_no *novo;   
  novo=aloca_pilhasimpencsoussa();
  if (!novo) return 0;

  novo->info = e;  
  if ( pilhasimpencsoussa_vazia(pilha) ) { //Se for o primeiro elemento da lista
     novo->prox = NULL;   
     }  
  else {
     novo->prox = pilha->topo;   
     }  
  pilha->topo = novo; 
  return 1;   
}        


int pop_pilhasimpencsoussa (tp_pilhasimpencsoussa *pilha, tp_item *e){   
  tp_no *aux;

  if (pilhasimpencsoussa_vazia(pilha)) return 0;
  *e=pilha->topo->info;
  aux=pilha->topo;
  pilha->topo=pilha->topo->prox;
  free(aux);
  aux=NULL;
  return 1;   
}        

int top_pilhasimpencsoussa (tp_pilhasimpencsoussa *pilha, tp_item *e){   
  tp_no *aux;

  if (pilhasimpencsoussa_vazia(pilha)) return 0;
  *e=pilha->topo->info;
  return 1;   
}        



tp_pilhasimpencsoussa *destroi_pilha(tp_pilhasimpencsoussa *pilha) {    
	 tp_no *atu=pilha->topo, *aux;
     tp_item e;
	 while (atu != NULL)
	       {
			aux = atu->prox;
            pop_pilhasimpencsoussa(pilha, &e);  
			atu= aux; 
            }
	pilha->topo = NULL;
	free(pilha);
	return NULL;
}



void imprime_pilhasimpencsoussa(tp_pilhasimpencsoussa *pilha) {
     tp_pilhasimpencsoussa *pilha_aux;
     tp_item e;
     //cria e inicializa uma pilha auxiliar
	 pilha_aux=inicializa_pilhasimpencsoussa();
     
	 while (!pilhasimpencsoussa_vazia(pilha))
	       {
            pop_pilhasimpencsoussa(pilha,&e);
            printf("%d ", e);
            push_pilhasimpencsoussa(pilha_aux, e);           
            }
	
	while (!pilhasimpencsoussa_vazia(pilha_aux))
	       {
            pop_pilhasimpencsoussa(pilha_aux,&e);
            push_pilhasimpencsoussa(pilha, e);           
            }
     pilha_aux = destroi_pilha(pilha_aux);

}



