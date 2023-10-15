#ifndef FILASIMPENCSOUSSA_H
#define FILASIMPENCSOUSSA_H

#include <stdio.h>
#include <stdlib.h>

typedef int tp_item; 

typedef struct no_aux {   
  tp_item info;   
  struct no_aux *prox;   
} no; 


typedef struct {   
  tp_no *ini, *fim;   
} tp_filasimpencsoussa;


tp_filasimpencsoussa *inicializa_filasimpencsoussa (){
   tp_filasimpencsoussa *fila=(tp_filasimpencsoussa*) malloc(sizeof(tp_filasimpencsoussa));   
   fila->ini=fila->fim = NULL;   
   return fila;
}  

tp_no *aloca_filasimpencsoussa() {
	tp_no* pt;
	pt=(tp_no*) malloc(sizeof(tp_no));
	return pt;
}

int filasimpencsoussa_vazia (tp_filasimpencsoussa *fila){   
 if (fila->ini == NULL) return 1;
 return 0;
}

int insere_filasimpencsoussa (tp_filasimpencsoussa *fila, tp_item e){   
  tp_no *novo;   
  novo=aloca_filasimpencsoussa();
  if (!novo) return 0;

  novo->info = e;  
  novo->prox = NULL;
  if ( filasimpencsoussa_vazia(fila) ) { //Se for o primeiro elemento da lista
     fila->ini = novo;
     }  
  else {
     fila->fim->prox = novo; 
     }  
  fila->fim=novo;
  return 1;   
}        

int remove_filasimpencsoussa (tp_filasimpencsoussa *fila, tp_item *e){   
  tp_no *aux;

  if (filasimpencsoussa_vazia(fila)) return 0;
  *e=fila->ini->info;
  aux=fila->ini;  

  if (fila->ini == fila->fim) //Se for o único nó da fila
     fila->ini=fila->fim=NULL;
  else
     fila->ini=fila->ini->prox;
     
  free(aux);
  return 1;   
}        


tp_filasimpencsoussa *destroi_fila(tp_filasimpencsoussa *fila) {
	 tp_no *atu=fila->ini;
	 tp_item e;
    
	 while (atu!=NULL)
	       {
            remove_filasimpencsoussa(fila, &e);
            atu=atu->prox;
            }
     fila->ini=fila->fim=NULL;
	 free(fila);	 
	 return NULL;       
}

void imprime_filasimpencsoussa(tp_filasimpencsoussa *fila) {
     tp_filasimpencsoussa *fila_aux;
     tp_item e;
     //cria e inicializa uma pilha auxiliar
	 fila_aux=inicializa_filasimpencsoussa();
     
	 while (!filasimpencsoussa_vazia(fila))
	       {
            remove_filasimpencsoussa(fila,&e);
			printf("%d ", e);
            insere_filasimpencsoussa(fila_aux, e);           
            }

     fila->ini = fila_aux->ini; 
     fila->fim = fila_aux->fim; 
     fila_aux->ini = NULL;
     fila_aux->fim = NULL;
     fila_aux = destroi_fila(fila_aux);
     printf("\n");

}

#endif
