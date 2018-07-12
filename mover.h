//  Created by Jonathan Pinho and Vinicius Mangueira 10/07/2018.
//  Copyright © 2018 Jonathan. All rights reserved.

#include <stdio.h>
extern char mat[10][10];
extern int x, y;
void direita();
void esquerda();
void cima();
void baixo();


int cont = 0;
void direita(){//Função que move o '*' para a direita
    char aux;

	if((x+1)<10 && mat[y][x+1] == '$') { //Caso de teste quando se encontra o doce
		mat[y][x+1] = '*';
			
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
	mat[y][x+1] = ' ';
		

	}
	else if((x+1)<10) { //Adicionando limite para a extremidade direita
	    aux = mat[y][x];
	    mat[y][x] = mat[y][x+1];
	    mat[y][x+1] = aux;
	    x +=1;
	}
}



void esquerda(){//Função que move o '*' para a esquerda
    char aux;

	if((x-1)>0 && mat[y][x-1] == '$') { //Caso de teste quando se encontra o doce
		mat[y][x-1] = '*';
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
	mat[y][x-1] == ' ';
	}
	else if((x-1)>=0) { //Adicionando limite para a extremidade esquerda
	    aux = mat[y][x];
	    mat[y][x] = mat[y][x-1];
	    mat[y][x-1] = aux;
	    x -=1;
	}
}

void cima(){//Função que move o '*' para a cima
    char aux;

	if((y-1)>0 && mat[y-1][x] == '$') { //Caso de teste quando se encontra o doce
		mat[y-1][x] = '*';
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
	mat[y-1][x] == ' ';
	}
	else if((y-1)>=0) { //Adicionando limite para a extremidade de cima
		aux = mat[y][x];
	    mat[y][x] = mat[y-1][x];
	    mat[y-1][x] = aux;
	    y -=1;
	}
}

void baixo(){//Função que move o '*' para a baixo
    char aux;

	if((y+1)<10 && mat[y+1][x] == '$') { //Caso de teste quando se encontra o doce
		mat[y][x+1] = '*';
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
	mat[y+1][x] == ' ';
	}
	else if((y+1)<10) { //Adicionando limite para a extremidade de baixo
	    aux = mat[y][x];
	    mat[y][x] = mat[y+1][x];
	    mat[y+1][x] = aux;
	    y +=1;
	}   
}
