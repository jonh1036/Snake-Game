//  Created by Jonathan Pinho 10/07/2018.
//  Copyright © 2018 Jonathan. All rights reserved.

#include <stdio.h>
extern char mat[10][10];
extern int x, y;
void direita();
void esquerda();
void cima();
void baixo();

void direita(){//Função que move o '*' para a direita
    char aux;

	if((y+1)<10) { //Adicionando limite para a extremidade direita
	    aux = mat[x][y];
	    mat[x][y] = mat[x][y+1];
	    mat[x][y+1] = aux;
	    y +=1;
	}
}

void esquerda(){//Função que move o '*' para a esquerda
    char aux;

	if((y-1)>=0) { //Adicionando limite para a extremidade esquerda
	    aux = mat[x][y];
	    mat[x][y] = mat[x][y-1];
	    mat[x][y-1] = aux;
	    y -=1;
	}
}

void cima(){//Função que move o '*' para a cima
    char aux;

	if((x-1)>=0) { //Adicionando limite para a extremidade de cima
		aux = mat[x][y];
	    mat[x][y] = mat[x-1][y];
	    mat[x-1][y] = aux;
	    x -=1;
	}
}

void baixo(){//Função que move o '*' para a baixo
    char aux;

	if((x+1)<10) { //Adicionando limite para a extremidade de baixo
	    aux = mat[x][y];
	    mat[x][y] = mat[x+1][y];
	    mat[x+1][y] = aux;
		x +=1;
	}   
}
