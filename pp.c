#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char nome[30];
	int mat;
	float n1;
	float n2;
	float n3;
	float media;
	char aprov;
}aluno;


void imprime(aluno a[]){
	printf("\n\n\n");
	for(int i = 0; i < 5; i++){
		printf("Aluno %d: %s\n", i+1, a[i].nome);
		printf("Matricula: %d\n", a[i].mat);
		printf("Nota 1: %.1f\n", a[i].n1);
		printf("Nota 2: %.1f\n", a[i].n2);
		printf("Nota 3: %.1f\n", a[i].n3);
		printf("Media: %.1f\n", a[i].media);
		if(a[i].aprov == 's') printf("Situacao: Aprovado\n\n");
		else printf("Situacao: Reprovado\n\n");
	}
}


int main(){
	
	aluno a[5];
	float maiorn1 = 0;
	float maiorm = 0;
	float menorm = 10;
	printf("Informe dados de 5 alunos abaixo.\n\n");
	
	for(int i = 0; i < 5; i++){
		printf("Nome do aluno %d: ", i+1);
		scanf("%s", a[i].nome);
		printf("Matricula do aluno %d: ", i+1);
		scanf("%d", &a[i].mat);
		printf("Nota 1, 2 e 3 do aluno %d:\n", i+1);
		scanf("%f %f %f", &a[i].n1, &a[i].n2, &a[i].n3);
		printf("\n\n");
	}
	
	for(int i = 0; i < 5; i++){
		if(a[i].n1 > maiorn1) maiorn1 = a[i].n1;
	}
	for(int i = 0; i < 5; i++){
	    if(maiorn1 == a[i].n1){
            printf("\nAluno(s) com a maior nota da primeria prova:\n");
            printf("%s com nota %.1f\n", a[i].nome, maiorn1);
        }
    }

	for(int i = 0; i < 5; i++) a[i].media = (a[i].n1 + a[i].n2 + a[i].n3) / 3;
	for(int i = 0; i < 5; i++) if(a[i].media > maiorm) maiorm = a[i].media;	

	for(int i = 0; i < 5; i++){
	    if(maiorm == a[i].media){
            printf("\nAluno(s) com a maior media da primeria prova:\n");
            printf("%s com nota %.1f\n", a[i].nome, maiorm);
        }
    }
	
	for(int i = 0; i < 5; i++) if(a[i].media < menorm) menorm = a[i].media;
	
    for(int i = 0; i < 5; i++){
	    if(menorm == a[i].media){
            printf("\nAluno(s) com a menor media da primeria prova:\n");
            printf("%s com nota %.1f\n", a[i].nome, menorm);
        }
    }
	
	for(int i = 0; i < 5; i++){
		if(a[i].media >= 6) a[i].aprov = 's';
	}
	
	imprime(a);
	
	return 0;
}