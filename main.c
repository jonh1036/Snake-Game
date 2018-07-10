//  Created by Jonathan Pinho 10/07/2018.
//  Copyright © 2018 Jonathan. All rights reserved.

#include <stdio.h>
void inicializa();
void imprimir();
void direita();
void esquerda();

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
			case 113: //Para encerrar o jogo
		      	
			case 115: //Movimentar para baixo
		    	break;
		    case 119: //Movimentar para cima
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

void direita(){//Função que move o '*' para a direita
    char aux;
    int a = x, b = y+1;
	if(b>=0 && b<=3) { //Adicionando limite para a extremidade direita
	    aux = mat[x][y];
	    mat[x][y] = mat[x][y+1];
	    mat[x][y+1] = aux;
	    y +=1;
	}
}

void esquerda(){//Função que move o '*' para a esquerda
    char aux;
    int a = x, b = y-1;
	if(b>=0 && b<=3) { //Adicionando limite para a extremidade esquerda
	    aux = mat[x][y];
	    mat[x][y] = mat[x][y-1];
	    mat[x][y-1] = aux;
	    y -=1;
	}
}
