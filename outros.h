//  Created by Jonathan Pinho 10/07/2018.
//  Copyright © 2018 Jonathan. All rights reserved.

#include <stdio.h>
#include <stdlib.h>
extern char mat[10][10];
extern int x, y;

void inicializa();
void imprimir();
void gerarDoce();

void inicializa(){//Função que inicializa a matriz no início do programa
    int i, j;
    for(i = 0; i < 9; i++ )
        for(j = 0; j < 9; j++)
            mat[i][j] = ' ';

    mat[0][0] = '*';//Origem
    gerarDoce();
	imprimir();
}

void imprimir(){//Função que imprime a matriz completa
    int i, j;
    for(i = 0; i < 9; i++){
        printf("|");
        for(j = 0; j < 9; j++){
            printf("%c",mat[i][j]);
        }
        printf("|\n");
    }
}

void gerarDoce(){
	int x1, y1;
	do{
		x1 = rand() % 9;
		y1 = rand() % 9;
		if(mat[x1][y1] == ' '){
			mat[x1][y1] = '$';
			break;
		}
	}while(1);
}
