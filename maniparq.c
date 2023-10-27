#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ler_formatado(FILE *arq, char nome[]){
    float nota1, nota2, nota3;

    arq = fopen(nome, "r");
    if(!arq) return 0;

    while(fscanf(arq, "%f %f %f", &nota1, &nota2, &nota3) != EOF) printf("Nota 1: %.1f, Nota 2: %.1f, Nota 3: %.1f\n", nota1, nota2, nota3);

    fclose(arq);

    return 1;
}

int main(){

    FILE *arq;
    char msg[20], nome[20], registro[20];

    scanf("%s", nome);
    arq = fopen(nome, "w");

    if(!arq) return 0;

    fprintf(arq, "9.0 7.0 4.0\n9.0 5.0 5.0\n5.0 7.0 7.0");

    fclose(arq);

    ler_formatado(arq, nome);

    return 1;
}


/*9.0 7.0 4.0
  9.0 5.0 5.0
  5.0 7.0 7.0*/