#include <stdio.h>
#include <locale.h>
#include "arvoretrie.h"


int main(){
	
	tp_no* raiz;
	raiz = cria_no('\0');
	
	char palavra[30];

	strcpy(palavra, "asa");
	raiz = insere_no_trie(raiz, palavra);

	strcpy(palavra, "axe");
	raiz = insere_no_trie(raiz, palavra);

	raiz = insere_no_trie(raiz, "ameixa");
	raiz = insere_no_trie(raiz, "banana");
	raiz = insere_no_trie(raiz, "abara");
	raiz = insere_no_trie(raiz, "bala");

	strcpy(palavra, "abacaxi");

	if(busca_no_trie(raiz, palavra)) printf("Palavra encontrada\n");

	else printf("Palavra nao encontrada\n");

	imprime_arv_trie(raiz);

	remove_no_trie(&raiz, "banana");

	return 0;
}

