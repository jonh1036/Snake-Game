//  Created by Jonathan Pinho 10/07/2018.
//  Copyright © 2018 Jonathan. All rights reserved.

#include <stdio.h>

int x = 0, y = 0;//Coordenadas da matriz
char mat[10][10];//Criação da matriz

int main(void) {
    char tecla;
    
    while(1){
		tecla = getch();
		system("cls");
		switch(tecla){
		    case 97: //Movimentar para esquerda
		        break;
		    case 100: //Movimentar para direita
		        break;
			case 113: //Para encerrar o jogo
		      	
			case 115: //Movimentar para baixo
		    	break;
		    case 119: //Movimentar para cima
		        break;
	        default: 
	            break;
        }
	
    }
    printf("\n\n");	
	return 0;
}
