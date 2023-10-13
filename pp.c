#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listasimpenc.h"


void josephus(listasimpenc *lista, int gap){

	

}


int main(){

	listasimpenc *lista;
	int gap;

	lista = inicializa_listasimpenc();

	printf("Informe o tamanho do gap: \n");
	scanf("%d, &gap");

	josephus(&lista, gap);

	return 0;
}