#ifndef FILASIMPENC
#define FILASIMPENC
#include <stdio.h>
#include <stdlib.h>
#include "pilhasimpenc.h"

typedef int oitem; 

typedef struct noaux{   
  oitem info;   
  struct noaux *prox;   
} no; 


typedef struct{   
  no *ini, *fim; 
  int tam;  
} filasimpenc;


filasimpenc *inicializa_filasimpenc (){
  filasimpenc *fila = (filasimpenc*) malloc(sizeof(fila));   
  fila->ini = fila->fim = NULL;   
  fila->tam = 0;
  return fila;
}  

no *aloca_filasimpenc(){
	no* pt;
	pt = (no*) malloc(sizeof(no));
	return pt;
}

int filasimpenc_vazia (filasimpenc *fila){   
  if (fila->ini == NULL) return 1;
  return 0;
}

int insere_filasimpenc (filasimpenc *fila, oitem e){   
  no *novo;   
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
  no *aux;

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
	no *atu = fila->ini;
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