#ifndef FILASIMPENC_H
#define FILASIMPENC_H

#include <stdio.h>
#include <stdlib.h>
#include "pilhasimpenc.h"

typedef int oitem; 

typedef struct no_aux{   
  oitem info;   
  struct no_aux *prox;   
} noh; 


typedef struct{   
  noh *ini, *fim; 
  int tam;  
} filasimpenc;


filasimpenc *inicializa_filasimpenc (){
  filasimpenc *fila = (filasimpenc*) malloc(sizeof(fila));   
  fila->ini = fila->fim = NULL;   
  fila->tam = 0;
  return fila;
}  

noh *aloca_filasimpenc(){
	noh* pt;
	pt = (noh*) malloc(sizeof(noh));
	return pt;
}

int filasimpenc_vazia (filasimpenc *fila){   
  if (fila->ini == NULL) return 1;
  return 0;
}

int insere_filasimpenc (filasimpenc *fila, oitem e){   
  noh *novo;   
  novo = aloca_filasimpenc();
  if (!novo) return 0;

  novo->info = e;  
  novo->prox = NULL;
  if ( filasimpenc_vazia(fila) ) fila->ini = novo;
     
  else fila->fim->prox = novo;  

  fila->fim = novo;

  fila->tam++;

  return 1;   
}        

int remove_filasimpenc (filasimpenc *fila, oitem *e){   
  noh *aux;

  if (filasimpenc_vazia(fila)) return 0;
  *e = fila->ini->info;
  aux = fila->ini;  

  if (fila->ini == fila->fim) fila->ini = fila->fim = NULL;

  else fila->ini = fila->ini->prox;
     
  free(aux);

  fila->tam--;

  return 1;   
}        


filasimpenc *destroi_filasimpenc(filasimpenc *fila){
	noh *atu = fila->ini;
	oitem e;
    
	while(atu != NULL){
        remove_filasimpenc(fila, &e);
        atu = atu->prox;
    }

  fila->ini = fila->fim = NULL;
  
  fila->tam = 0;

	free(fila);	 
	return NULL;       
}

void imprime_filasimpenc(filasimpenc *fila){
    filasimpenc *fila_aux;
    oitem e;

	fila_aux = inicializa_filasimpenc();
     
	while(!filasimpenc_vazia(fila)){
    remove_filasimpenc(fila,&e);
		printf("%d ", e);
    insere_filasimpenc(fila_aux, e);           
  }

    fila->ini = fila_aux->ini; 
    fila->fim = fila_aux->fim; 

    fila_aux->ini = NULL;
    fila_aux->fim = NULL;

    fila_aux = destroi_filasimpenc(fila_aux);
    printf("\n");

}


#endif