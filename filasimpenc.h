#ifndef FILASIMPENC
#define FILASIMPENC
#include <stdio.h>
#include <stdlib.h>

typedef int oitem; 

typedef struct no_aux{   
  oitem info;   
  struct no_aux *prox;   
} no; 


typedef struct{   
  no *ini, *fim; 
  int tam = 0;  
} fila;


fila *inicializa_fila (){
   fila *fila = (fila*) malloc(sizeof(fila));   
   fila->ini = fila->fim = NULL;   
   return fila;
}  

no *aloca(){
	no* pt;
	pt = (no*) malloc(sizeof(no));
	return pt;
}

int fila_vazia (fila *fila){   
 if (fila->ini == NULL) return 1;
 return 0;
}

int insere_fila (fila *fila, oitem e){   
  no *novo;   
  novo = aloca();
  if (!novo) return 0;

  novo->info = e;  
  novo->prox = NULL;
  if ( fila_vazia(fila) ) fila->ini = novo;
     
  else fila->fim->prox = novo;  

  fila->fim = novo;
  return 1;   
}        

int remove_fila (fila *fila, oitem *e){   
  no *aux;

  if (fila_vazia(fila)) return 0;
  *e = fila->ini->info;
  aux = fila->ini;  

  if (fila->ini == fila->fim) fila->ini = fila->fim = NULL;

  else fila->ini = fila->ini->prox;
     
  free(aux);
  return 1;   
}        


fila *destroi_fila(fila *fila){
	no *atu = fila->ini;
	oitem e;
    
	while(atu!=NULL){
        remove_fila(fila, &e);
        atu = atu->prox;
    }

    fila->ini=fila->fim = NULL;

	free(fila);	 
	return NULL;       
}

void imprime_fila(fila *fila){
    fila *fila_aux;
    oitem e;

	fila_aux=inicializa_fila();
     
	while(!fila_vazia(fila)){
        remove_fila(fila,&e);
		printf("%d ", e);
        insere_fila(fila_aux, e);           
    }

    fila->ini = fila_aux->ini; 
    fila->fim = fila_aux->fim; 

    fila_aux->ini = NULL;
    fila_aux->fim = NULL;

    fila_aux = destroi_fila(fila_aux);
    printf("\n");

}


#endif