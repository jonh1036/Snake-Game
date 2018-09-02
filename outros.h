//  Created by Jonathan Pinho and Vinicius Mangueira 10/07/2018.
//  Copyright © 2018 Jonathan. All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializa();
void imprimir();
void gerarDoce();
void movimentar();

extern int x, y;
extern char mat[10][10];
extern char tecla;

extern struct Snake positionSnake;

void inicializa(){//Função que inicializa a matriz no início do programa
    int i, j;
    for(i = 0; i < 10; i++ )
        for(j = 0; j < 10; j++){
        	if(i == 0 && (j>=0 && j<=2)){
        		mat[i][j] = '*';//Origem
			}
			else
				mat[i][j] = ' ';
		}
	positionSnake.size = 3; 
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

void movimentar(){
	char tec;
	
	if (kbhit()){
		tec = getch();
		if( (tecla=='a' && tec != 'd') || (tecla=='d' && tec != 'a') || (tecla=='w' && tec != 's') || (tecla=='s' && tec != 'w') ){
			tecla = tec;	
		}
	}
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
	    default: printf("Teclas permitidas: \nPara cima (tecla W), \nPara baixo (tecla S),\nPara a esquerda (tecla A)\nPara a direita (tecla D)\nPara sair (tecla Q)\n\n");
	        break;
       }
	imprimir();
}
