//  Created by Jonathan Pinho and Vinicius Mangueira 10/07/2018.
//  Copyright © 2018 Jonathan. All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializa();
void imprimir();
void gerarDoce();

extern int x, y;
extern char mat[10][10];


void inicializa(){//Função que inicializa a matriz no início do programa
    int i, j;
    for(i = 0; i < 10; i++ )
        for(j = 0; j < 10; j++)
            mat[i][j] = ' ';

    mat[0][0] = '*';//Origem
    gerarDoce();
	imprimir();
}

void imprimir(){//Função que imprime a matriz completa
    int i, j;
    for(i = 0; i < 10; i++){
        printf("|");
        for(j = 0; j < 10; j++){
            printf("%c",mat[i][j]);
        }
        printf("|\n");
    }
}

void gerarDoce(){
	int x1, y1,i;
	do{
	   	srand(time(NULL));
     	for (i=0; i<1; i++){
            x1 = rand() %10; //Gera uma coordenada aleatória no eixo X
            y1 = rand() %10; //Gera uma coordenada aleatória no eixo Y
      	}
		
		if(mat[y1][x1] == ' '){
			mat[y1][x1] = '$';
			break;
		}
	}while(1);
}
