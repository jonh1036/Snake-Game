//  Created by Jonathan Pinho and Vinicius Mangueira 10/07/2018.
//  Copyright © 2018 Jonathan. All rights reserved.

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "prototypes.h"
void direita();
void esquerda();
void cima();
void baixo();
void rigth();
void left();
void up();
void down();

extern int x, y;
extern char mat[10][10];

struct Snake positionSnake;

void direita(){//Função que move o '*' para a direita
    char aux;
    int i;

	if((x+1)<10 && mat[y][x+1] == '$') { //Caso de teste quando se encontra o doce
		mat[y][x+1] = '*';
		
		
		positionSnake.size++;
		positionSnake.bodySize[1].x = mat[0][x+1];
		positionSnake.bodySize[1].y	= mat[y][0];  //Test in mat, add x, y, test, after implemented loop to make it.
	
		int x1, y1;
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
		rigth();	
	}
	else if((x+1)<10) { //Adicionando limite para a extremidade direita
	    rigth();
	}
	else if((x+1)==10) {
		puts("GAMER OVER");
		exit(0);
	}
}

void rigth(){
	char aux;

	aux = mat[y][x];
	mat[y][x] = mat[y][x+1];
	mat[y][x+1] = aux;
	x +=1;	
}

void esquerda(){//Função que move o '*' para a esquerda
    char aux;

	if((x-1)>0 && mat[y][x-1] == '$') { //Caso de teste quando se encontra o doce
		mat[y][x-1] = '*';
		
		positionSnake.size++;
		
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
		left();
	}
	else if((x-1)>=0) { //Adicionando limite para a extremidade esquerda
	    left();
	}
	else if((x-1)<0) {
		puts("GAMER OVER");
		exit(0);
	}
}

void left(){
	char aux;
	
	aux = mat[y][x];
	mat[y][x] = mat[y][x-1];
	mat[y][x-1] = aux;
	x -=1;
}

void cima(){//Função que move o '*' para a cima
    char aux;

	if((y-1)>0 && mat[y-1][x] == '$') { //Caso de teste quando se encontra o doce
		mat[y-1][x] = '*';
		
		positionSnake.size++;
		
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
		up();
	}
	else if((y-1)>=0) { //Adicionando limite para a extremidade de cima
		up();
	}
	else if((y-1)<0) {
		puts("GAMER OVER");
		exit(0);
	}
}

void up(){
	char aux;
	
	aux = mat[y][x];
	mat[y][x] = mat[y-1][x];
	mat[y-1][x] = aux;
	y -=1;
}

void baixo(){//Função que move o '*' para a baixo
    char aux;

	if((y+1)<10 && mat[y+1][x] == '$') { //Caso de teste quando se encontra o doce
		mat[y+1][x] = '*';
		
		positionSnake.size++;
		
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
		down();
	}
	else if((y+1)<10) { //Adicionando limite para a extremidade de baixo
	    down();
	}
	else if((y+1)==10) {
		puts("GAMER OVER");
		exit(0);
	}   
}

void down(){
	char aux;
	
	aux = mat[y][x];
	mat[y][x] = mat[y+1][x];
	mat[y+1][x] = aux;
	y +=1;
}
