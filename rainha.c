#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 4

void inicializa_matriz(char m[][TAM]){
	int i, j;
	for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            m[i][j] = '#';
        }
    }
}


void imprime_matriz(char m[TAM][TAM]){
		printf("         0 1 2 3\n");
        printf("       0 %c|%c|%c|%c \n", m[0][0], m[0][1], m[0][2], m[0][3]);
        printf("         ------\n");
        printf("       1 %c|%c|%c|%c \n", m[1][0], m[1][1], m[1][2], m[1][3]);
        printf("         ------\n");
        printf("       2 %c|%c|%c|%c \n", m[2][0], m[2][1], m[2][2], m[2][3]);
        printf("         ------\n");
        printf("       3 %c|%c|%c|%c \n", m[3][0], m[3][1], m[3][2], m[3][3]);        
}


int valtab(char m[][TAM], int l, int c){
    int i, j;

    for(j = 0; j < c; j++){ 
        if (m[l][j] == 'R') return 0;
    }

    for(i = l, j = c; i >= 0 && j >= 0; i--, j--){
        if(m[i][j] == 'R') return 0;

    }
    for(i = l, j = c; i < TAM && j >= 0; i++, j--){
        if(m[i][j] == 'R') return 0;
    }

}


int posrainha(char m[TAM][TAM], int c){ 
    int i;

    if (c>=TAM) return 1;
       
    for (i=0; i<TAM; i++){   
        if(valtab(m, i, c)){

			m[i][c] = 'R';
			
    		if(posrainha(m, c+1)) return 1;

 			else m[i][c] = '#';					
		}
	}
    return 0;	
}


int main(){
    
    int col = 0;
    char tabuleiro[TAM][TAM];
    inicializa_matriz(tabuleiro);
    posrainha(tabuleiro, col);
    imprime_matriz(tabuleiro);
}