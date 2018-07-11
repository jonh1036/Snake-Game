//  Created by Jonathan Pinho 10/07/2018.
//  Copyright © 2018 Jonathan. All rights reserved.

#include <stdio.h>
extern char mat[10][10];
extern int x, y;

void inicializa();
void imprimir();

void inicializa(){//Função que inicializa a matriz no início do programa
    int i, j;
    for(i = 0; i < 4; i++ )
        for(j = 0; j < 4; j++)
            mat[i][j] = ' ';

    mat[0][0] = '*';//Origem
	imprimir();
}

void imprimir(){//Função que imprime a matriz completa
    int i, j;
    for(i = 0; i < 4; i++){
        printf("|");
        for(j = 0; j < 4; j++){
            printf("%c",mat[i][j]);
        }
        printf("|\n");
    }
}
