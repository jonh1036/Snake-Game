//  Created by Jonathan Pinho and Vinicius Mangueira 10/07/2018.
//  Copyright © 2018 Jonathan. All rights reserved.

#include <stdio.h>
#include "mover.h"
#include "outros.h"
#define MAT_LENGHT 10
#define MAX_WORM 100


int x = 0, y = 0;//Coordenadas da matriz
char mat[MAT_LENGHT][MAT_LENGHT];//Criação da matriz

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
