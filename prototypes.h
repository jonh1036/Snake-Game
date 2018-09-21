#define MAT 10
#define MAX_WORM 100
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct  {
    int x,y;
}Position;
typedef struct  {
    int size;
    Position *p;
}Snake;
typedef struct  {
    Position position;
    int life;
}Candy;

void crescer(Position p);
void clear();
void colider(Position head); 
void gerarDoce();
void imprimir();
void inicializa();
void insert();
void movimentar();
int ponteiroNulo(Position *p);
void fileHelperW();
void fileHelperL();
