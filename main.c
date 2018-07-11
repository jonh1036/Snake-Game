//  Created by Jonathan Pinho 10/07/2018.
//  Copyright © 2018 Jonathan. All rights reserved.

#include <stdio.h>
#include "mover.h"
void inicializa();
void imprimir();

int x = 0, y = 0;//Coordenadas da matriz
char mat[10][10];//Criação da matriz

int main(void) {
    char tecla;
    
    inicializa();//Inicialização da Matriz
    while(1){
		tecla = getch();
		system("cls");
		switch(tecla){
		    case 97: esquerda();//Movimentar para esquerda
		        break;
		    case 100: direita();//Movimentar para direita
		        break;
			case 113: exit(0);//Para encerrar o jogo
		      	
			case 115: baixo();//Movimentar para baixo
		    	break;
		    case 119: cima();//Movimentar para cima
		        break;
	        default: 
	            break;
        }
		imprimir();
    }
    printf("\n\n");	
	return 0;
}

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
