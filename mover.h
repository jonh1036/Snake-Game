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

void cima(){//Função que move o '*' para a cima
    char aux;
    int a = x-1, b = y;
	if(a>=0 && a<=3) { //Adicionando limite para a extremidade de cima
		aux = mat[x][y];
	    mat[x][y] = mat[x-1][y];
	    mat[x-1][y] = aux;
	    x -=1;
	}
}

void baixo(){//Função que move o '*' para a baixo
    char aux;
    int a = x+1, b = y;
	if(a>=0 && a<=3) { //Adicionando limite para a extremidade de baixo
	    aux = mat[x][y];
	    mat[x][y] = mat[x+1][y];
	    mat[x+1][y] = aux;
		x +=1;
	}   
}
