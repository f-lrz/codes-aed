#ifndef LISTADUPENC
#define LISTADUPENC
#include <stdio.h>
#include <stdlib.h>

typedef int oitem; 

typedef struct no_aux {   
    struct no_aux *antatual;  
    oitem info;  
    struct no_aux *prox;   
} no; 

typedef struct {   
    no *ini;   
    no *fim;   
    int tam;   
} listadupenc;

listadupenc *inicializa_listadupenc(){
    listadupenc *lista = (listadupenc*) malloc(sizeof(listadupenc));   
    lista->ini = NULL;   
    lista->fim = NULL;   
    lista->tam = 0;   
    return lista;
}  


int listadupenc_vazia(listadupenc *lista) {
	if (lista->ini == NULL) return 1;
	return 0;	
}

no *aloca() {
	no* pt;
	pt = (no*) malloc(sizeof(no));
	return pt;
}

int insere_listadupenc_no_fim (listadupenc *lista, oitem e){   
    no *novo;   
    novo = aloca();
    if (!novo) return 0;
    novo->info = e;  

    if (listadupenc_vazia(lista)){
        novo->prox = NULL;   
        novo->antatual = NULL; 
        lista->ini = lista->fim = novo;
    }  

    else{
        novo->prox = NULL;   
        novo->antatual = lista->fim; 
        lista->fim->prox = novo;
        lista->fim = novo;
    }  
    
    lista->tam++; 

    return 1;   
}        

void imprime_listadupenc(listadupenc *lista, int ordem){

	if(lista==NULL) printf("Lista não inicializada");
	else{

        no *atual; 

        switch (ordem){
            case 1: 
                atual = lista->ini;
                while (atual != NULL){
                   printf("%d ", atual->info);
                   atual = atual->prox;           
                }
                break; 
                  
            case 2: 
                atual = lista->fim;
                while (atual != NULL){
                   printf("%d ", atual->info);
                   atual = atual->antatual;           
                   }
                break; 

            default: printf("codigo invalido");        
        }
	}
    printf("\n");
}


int remove_listadupenc(listadupenc *lista, oitem e){   

    no *atual;
    atual = lista->ini;

    while ((atual != NULL) && (atual->info != e)) atual = atual->prox;

    if (atual == NULL) return 0;  

    if (lista->ini == lista->fim) lista->ini = lista->fim = NULL;
   
    else if (lista->ini == atual){
        lista->ini = atual->prox;
        atual->prox->antatual = NULL;
    }
    
    else if (lista->fim == atual){ 
        lista->fim = atual->antatual;
        atual->antatual->prox = NULL;              
    }  

    else{
        atual->prox->antatual = atual->antatual;   
        atual->antatual->prox = atual->prox;
    } 

   lista->tam--; 

   free(atual);  

  
  return 1;   
}        

no* busca_listadupenc (listadupenc *lista, oitem e){   
    no *atual;
    atual = lista->ini;
    while ((atual != NULL) && (atual->info != e)) atual = atual->prox;
    return atual;
}     

int tamanho_listadupenc(listadupenc *lista){
    return lista->tam;
}

listadupenc * destroi_listadupenc (listadupenc *lista){   
    no *atual;
    atual = lista->ini;
    while (atual != NULL){ 
        lista->ini = atual->prox;
        free(atual);
        atual=lista->ini;
	}

    lista->tam = 0;

    free(lista);
    return NULL;
}  

#endif

