#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *arq;
    char msg[20], nome[20], registro[20];

    scanf("%s", nome);
    arq = fopen(nome, "w");

    if(!arq) return 0;

    printf("\nMensagem 1:\n");
    scanf("%[^\n]s", msg);
    fprintf(arq, strcat(msg, "\n"));

    rewind(arq);
    fclose(arq);
    arq = fopen(nome, "r");

    while(fgets(registro, sizeof(registro), arq)) printf("\n%s", registro);

    fclose(arq);
    return 1;
}
