#include <stdio.h>
#include <string.h>
#include <stdlib.h>

  /*printf("         0  1  2\n");
    printf("       0   |  |   \n");
    printf("       ---------\n");
    printf("       1   |  |   \n");
    printf("       ---------\n");
    printf("       2   |  |   \n");*/

    

void inicializa_m(char m[][3]){
  char esp = 255;
    for(int i = 0; i < 3; i++){
	   	 for(int j = 0; j < 3; j++){
		  	 m[i][j] = esp;
		    }
	  }
}

void imprime_m(char m[3][3]){
    printf("\n");
    printf("         0  1  2\n");
    printf("       0 %c |%c |%c \n", m[0][0], m[0][1], m[0][2]);
    printf("         --------\n");
    printf("       1 %c |%c |%c \n", m[1][0], m[1][1], m[1][2]);
    printf("         --------\n");
    printf("       2 %c |%c |%c \n", m[2][0], m[2][1], m[2][2]);
}

int coordenadavalida(char m[][3], int i, int j){
	char esp = 255;
	if(m[i][j] != esp) return 0;
	if((i > 3) || (j > 3)) return 0;
	return 1;
}

int fechoucoluna(char m[][3]){
    for(int a = 0; a < 3; a++){
        if((m[0][a] == 'X' && m[1][a] == 'X' && m[2][a] == 'X') || (m[0][a] == 'O' && m[1][a] == 'O' && m[2][a] == 'O')) return 1;
    }
    return 0;
}

int fechoulinha(char m[][3]){
    for(int a = 0; a < 3; a++){
        if((m[a][0] == 'X' && m[a][1] == 'X' && m[a][2] == 'X') || (m[a][0] == 'O' && m[a][1] == 'O' && m[a][2] == 'O')) return 1;
    }

    return 0;
}

int fechoudiagonal(char m[][3]){
    if((m[0][0] == 'X' && m[1][1] == 'X' && m[2][2] == 'X') || (m[0][0] == 'O' && m[1][1] == 'O' && m[2][2] == 'O')) return 1;
    if((m[0][2] == 'X' && m[1][1] == 'X' && m[2][0] == 'X') || (m[0][2] == 'O' && m[1][1] == 'O' && m[2][0] == 'O')) return 1;

    return 0;
}

int main (){
	system("color 8F");
	
    int parar = 0, empate = 1, cont = 0;
    char nome1[20], nome2[20], matriz[3][3];
    int ci, cj;

    do{
        system("cls");
        printf("Digite o nome do Jogador 1 (X): ");
        scanf("%s", nome1);

        printf("\nDigite o nome do Jogador 2 (O): ");
        scanf("%s", nome2);
    
        system("cls");
	
        printf("\n\n");
	    printf("*******************************\n");
	    printf("** J O G O   D A   V E L H A **\n");
        printf("*******************************");
        printf("\nNome do Jogador 1: %s\n", nome1);
        printf("Nome do Jogador 2: %s\n", nome2);
        printf("\nBoa sorte jogadores %s e %s!\n", nome1, nome2);
        printf("*******************************\n\n");
    
        inicializa_m(matriz);

        for(int i = 0; i < 5; i++){
            
            cont++;
            imprime_m(matriz);
    	    printf("\n\nJogador(a) %s: digite a coordenada para jogar o X (ex: '1 2'): ", nome1);
    	    scanf("%d %d", &ci, &cj);
		    while(!coordenadavalida(matriz, ci, cj)){
			    printf("\nCoordenada invalida!! Digite novamente: ");
			    scanf("%d %d", &ci, &cj);
		    }
		    matriz[ci][cj] = 'X';
            if(fechoulinha(matriz) || fechoucoluna(matriz) || fechoudiagonal(matriz) != 0){
                system("cls");
                imprime_m(matriz);
                printf("\nParabens %s!! Voce ganhou o jogo!", nome1);
                empate = 0;
                break;
            }
		    system("cls");

            if (cont == 5) break;

       	    imprime_m(matriz);
    	    printf("\n\nJogador(a) %s: digite a coordenada para jogar o O (ex: '1 2'): ", nome2);
    	    scanf("%d %d", &ci, &cj);
		    while(!coordenadavalida(matriz, ci, cj)){
			    printf("\nCoordenada invalida!! Digite novamente: ");
			    scanf("%d %d", &ci, &cj);
		    }
    	    matriz[ci][cj] = 'O';
            if(fechoulinha(matriz) || fechoucoluna(matriz) || fechoudiagonal(matriz) != 0){
                system("cls");
                imprime_m(matriz);
                printf("\nParabens %s!! Voce ganhou o jogo!", nome2);
                empate = 0;
                break;
            }
		    system("cls");

	    }

        if(cont == 5 && empate == 1) printf("Deu empate :/");

        printf("\n\nDeseja jogar novamente? ('1' = sim, '0' = nao)\n");
        scanf("%d", &parar);

    }while(parar);

    printf("\n\nObrigado por jogar :)\n\n\n");
    
    return 0;
}