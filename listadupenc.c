#ifndef LISTADUPENC
#define LISTADUPENC
#include <stdio.h>
#include <stdlib.h>

typedef int oitem; 

typedef struct no_aux {   
    struct no_aux *ant;  
    oitem info;  
    struct no_aux *prox;   
} no; 

typedef struct {   
    no *ini;   
    no *fim;   
    int tamanho;   
} listadupenc;

listadupenc *inicializa_listadupenc(){
    listadupenc *lista=(listadupenc*) malloc(sizeof(listadupenc));   
    lista->ini = NULL;   
    lista->fim = NULL;   
    lista->tamanho = 0;   
    return lista;
}  


int listad_vazia(listadupenc *lista) {
	if ( (lista->ini == NULL) ) 
		return 1;
	return 0;	
}

no *aloca() {
	no* pt;
	pt=(no*) malloc(sizeof(no));
	return pt;
}

int insere_listadupenc_no_fim (listadupenc *lista, oitem e){   
    no *novo;   
    novo = aloca();
    if (!novo) return 0;
    novo->info = e;  

    if (listadupenc_vazia(lista)){
        novo->prox = NULL;   
        novo->ant = NULL; 
        lista->ini = lista->fim = novo;
    }  

    else{
        novo->prox = NULL;   
        novo->ant = lista->fim; 
        lista->fim->prox = novo;
        lista->fim = novo;
    }  
    
    lista->tamanho++; 

    return 1;   
}        

void imprime_listadupenc(listadupenc *lista, int ordem){

	if(lista==NULL) printf("Lista não inicializada");
	else{

     no *atu; 

     switch (ordem){

        case 1: atu = lista->ini;
                while (atu != NULL){
                   printf("%d ", atu->info);
                   atu=atu->prox;           
                   }
                break; 
                  
        case 2: atu = lista->fim;
                while (atu != NULL) {
                   printf("%d ", atu->info);
                   atu=atu->ant;           
                   }
                break; 

        default: printf("codigo invalido");        
     }
	}
     printf("\n");
}


int remove_listadupenc (listadupenc *lista, oitem e){   

    no *atu;
    atu = lista->ini;

    while ((atu != NULL) && (atu->info != e)) atu=atu->prox;

    if ( atu == NULL) return 0;  

    if (lista->ini == lista->fim) lista->ini = lista->fim = NULL;

    else{   
        
        if (lista->ini == atu){
        lista->ini = atu->prox;
        atu->prox->ant = NULL;
        }  

        else{

        if (lista->fim == atu){ 
            lista->fim = atu->ant;
            atu->ant->prox = NULL;              
        }  

        else{
            atu->prox->ant = atu->ant;   
            atu->ant->prox = atu->prox;
        } 
      }
    } 

   free(atu);  

   lista->tamanho--; 
  
  return 1;   
}        

no * busca_listadupenc (listadupenc *lista, oitem e){   
    no *atu;
    atu = lista->ini;
    while ((atu != NULL) && (atu->info != e)) atu=atu->prox;
    return atu;
}        

listadupenc * destroi_listadupenc (listadupenc *lista){   
    no *atu;
    atu = lista->ini;
    while (atu != NULL){ 
        lista->ini = atu->prox;
        free(atu);
        atu=lista->ini;
		}
    free(lista);
    return NULL;
}  

#endif

