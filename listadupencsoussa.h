#ifndef LISTADE_H
#define LISTADE_H

#include <stdio.h>
#include <stdlib.h>

typedef int tp_item; 

//dados estruturado que representa o descritor
typedef struct tp_no_aux {   
  struct tp_no_aux *ant;  
  tp_item info;  
  struct tp_no_aux *prox;   
} tp_no; 

//dado estruturado que representa o nó da lista
typedef struct {   
  tp_no *ini;   
  tp_no *fim;   
  int tamanho;   
} tp_listadupencsoussa;

//aloca-se memória para o descritor (explicado no ínicio deste arquivo) e faz o seus ponteiros apontarem para o Nulo
tp_listadupencsoussa *inicializa_listadupencsoussa(){
   tp_listadupencsoussa *lista=(tp_listadupencsoussa*) malloc(sizeof(tp_listadupencsoussa));   
   lista->ini = NULL;   
   lista->fim = NULL;   
   lista->tamanho = 0;   
   return lista;
}  


int listadupencsoussa_vazia(tp_listadupencsoussa *lista) {
	if ( (lista->ini == NULL) ) 
		return 1;
	return 0;	
}

//Aloca um nó da lista
tp_no *aloca_listadupencsoussa() {
	tp_no* pt;
	pt=(tp_no*) malloc(sizeof(tp_no));
	return pt;
}

//insere um novo nó na lista
int insere_listadupencsoussa_no_fim (tp_listadupencsoussa *lista, tp_item e){   
  tp_no *novo;   
  novo=aloca_listadupencsoussa();
  if (!novo) return 0;
  novo->info = e;  
  if ( listadupencsoussa_vazia(lista) ){ //Se for o primeiro elemento da lista
     novo->prox = NULL;   
     novo->ant = NULL; 
     lista->ini = lista->fim = novo;
     }  
  else {
     novo->prox = NULL;   
     novo->ant = lista->fim; 
     lista->fim->prox = novo;
     lista->fim = novo;
     }  
  lista->tamanho++;   
  return 1;   
}        

//imprime os conteúdos da lista (de frente para trás ou de trás pra frente)
void imprime_listadupencsoussa(tp_listadupencsoussa *lista, int ordem) {
	if (lista==NULL)
		printf("Lista não inicializada");
	else {
     tp_no *atu;     
     switch (ordem) {
        case 1: atu = lista->ini;
                while (atu != NULL) {
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


//remove um elemento da lista
int remove_listadupencsoussa (tp_listadupencsoussa *lista, tp_item e){   
  tp_no *atu;
  atu = lista->ini;
  while ( (atu != NULL) && (atu->info != e) ) { 
        atu=atu->prox;}
  if ( atu == NULL) return 0;  
  if (lista->ini == lista->fim) { //Se o for o unico elemento da lista
      lista->ini = lista->fim = NULL; }
  else {   
   if (lista->ini == atu) {  //Se for o primeiro elemento da lista
      lista->ini = atu->prox;
      atu->prox->ant = NULL;
      }  
   else {
      if (lista->fim == atu) { // se for o último nó da lista
       lista->fim = atu->ant;
       atu->ant->prox = NULL;              
       }
      else {
        atu->prox->ant = atu->ant;   
        atu->ant->prox = atu->prox;
        } 
      }
     }   
   free(atu);  
  lista->tamanho--;   
  return 1;   
}        

//Com base em um conteúdo, retorna-se o endereço do nó que contém o conteúdo
tp_no * busca_listadupencsoussa (tp_listadupencsoussa *lista, tp_item e){   
  tp_no *atu;
  atu = lista->ini;
  while ( (atu != NULL) && (atu->info != e) ) { 
        atu=atu->prox;}
  return atu;
}        

//Retira da memória todos os nós da lista e também o descritor
tp_listadupencsoussa * destroi_listadupencsoussa (tp_listadupencsoussa *lista){   
  tp_no *atu;
  atu = lista->ini;
  while (atu != NULL)  { 
        lista->ini = atu->prox;
        free(atu);
        atu=lista->ini;
		}
  free(lista);
  return NULL;
}  

#endif

