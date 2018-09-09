#include <stdio.h>
#include <stdlib.h>
#define MAT 10
#define MAX_WORM 100

typedef struct  {
    int x,y;
} Position;

typedef struct  {
    int size;
    Position *p;
} Snake;

typedef struct  {
    Position position;
    int life;
} Candy;

void inicializa();
void imprimir();
void gerarDoce();
void movimentar();
void direita();
void esquerda();
void cima();
void baixo();
void rigth();
void left();
void up();
void down();
int ponteiroNulo(Position *p);
void insert();
void clear();
void aux(Position p);

int x = 2, y = 0;//Coordenadas da matriz
char mat[MAT][MAT];//Criação da matriz
char tecla = 'd';
Snake snake;
Candy candy;

int main(void) {
    
	inicializa();//Inicialização da Matriz
	movimentar();
	
    printf("\n\n");	
	return 0;
}

void inicializa(){//Função que inicializa a matriz no início do programa
    int i;
	
	snake.size = 3; 
	snake.p = (Position*) malloc(snake.size * sizeof(Position));
	ponteiroNulo(snake.p);
	
	for(i = 0; i < snake.size;i++) {
		snake.p[i].y = snake.size - i - 1;
		snake.p[i].x = 0;
	}
	
	clear();
    gerarDoce();
    insert();
}

void clear(){
    int i, j;
	for(i = 0; i < MAT ; i++)
        for(j = 0; j < MAT ; j++){
            mat[i][j] = ' ';
        }    
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
            candy.position.x = rand() %10; //Gera uma coordenada aleatória no eixo X
            candy.position.y = rand() %10; //Gera uma coordenada aleatória no eixo Y
    	}
		if(mat[candy.position.y][candy.position.x] == ' '){
			mat[candy.position.y][candy.position.x] = '$';
			break;
		}
	}while(1);
	
	candy.life = rand()%10;
}

void insert(){
	int i;
	
	for(i = 0; i < snake.size; i++) {
		mat[snake.p[i].x][snake.p[i].y] = '*';
	}
}

int ponteiroNulo (Position *p) {
	if(p == NULL) {
		printf("Does not possible alloc");
		exit(1);
	}
	return 0;
}

void movimentar(){//mover
	char tec;
	
	Position head = snake.p[0];
	system("cls");
	while(1){
		imprimir();
		
		if (kbhit()){
			tec = getch();
			if( (tecla=='a' && tec != 'd') || (tecla=='d' && tec != 'a') || (tecla=='w' && tec != 's') || (tecla=='s' && tec != 'w') ){
				tecla = tec;	
			}
		}
		switch(tecla){
	    	case 'a':	//esquerda();//Movimentar para esquerda
	    				head.y--;
	    				candy.life--;
	    	    break;
	    	case 'd':	//direita();//Movimentar para direita
	    				head.y++;
						candy.life--;
	    	    break;
			case 'q':	exit(0);//Para encerrar o jogo
	    	  	
			case 's':	//baixo();//Movimentar para baixo
						head.x++;
						candy.life--;
	    		break;
	    	case 'w':	//cima();//Movimentar para cima
	    				head.x--;
						candy.life--;
	    	    break;
	    	default:	printf("Teclas permitidas: \nPara cima (tecla W), \nPara baixo (tecla S),\nPara a esquerda (tecla A)\nPara a direita (tecla D)\nPara sair (tecla Q)\n\n");
	    	    break;
		}
		if(candy.life == 0){
    		mat[candy.position.y][candy.position.x] = ' ';
    		gerarDoce();
		}
	
		if(head.x == candy.position.x  &&  head.y == candy.position.y ){
    	   	snake.size++;
    		gerarDoce();
    	}
	
		aux(head);
		clear();
		insert();
		system("cls");
	}
}

void aux(Position p){
	int i;
	
	snake.p = (Position *) realloc( snake.p, snake.size * sizeof(Position));
	for(i = snake.size -1; i >= 0 ;i--){
        if(i == 0){
            snake.p[i] = p;
        }else{
            snake.p[i] = snake.p[i - 1] ;
        }
    }
}

void direita(){//Função que move o '*' para a direita
    char aux;
    int i;

	if((x+1)<10 && mat[y][x+1] == '$') { //Caso de teste quando se encontra o doce
		mat[y][x+1] = '*';
		
		snake.size++;
	
		int x1, y1;
		do{
		  	gerarDoce();
			break;
		}while(1);
		rigth();	
	}
	else if(((x+1)<10 && mat[y][x+1] == '*') || ((x+1)==10)){ //Caso de teste quando se encontra o outra parte do corpo ou com a parede
		puts("GAMER OVER");
		exit(0);
	}
	else if((x+1)<10) { //Adicionando limite para a extremidade direita
	    rigth();
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
		
		snake.size++;
		
		int x1, y1,i;
		do{
		   	gerarDoce();
			break;
		}while(1);
		left();
	}
	else if(((x-1)>0 && mat[y][x-1] == '*') || ((x-1)<0)){ //Caso de teste quando se encontra o outra parte do corpo ou com a parede
		puts("GAMER OVER");
		exit(0);
	}
	else if((x-1)>=0) { //Adicionando limite para a extremidade esquerda
	    left();
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
		
		snake.size++;
		
		int x1, y1,i;
		do{
		   	gerarDoce();
			break;
		}while(1);	
		up();
	}
	else if(((y-1)>0 && mat[y-1][x] == '*') || ((y-1)<0)){ //Caso de teste quando se encontra o outra parte do corpo ou com a parede
		puts("GAMER OVER");
		exit(0);
	}
	else if((y-1)>=0) { //Adicionando limite para a extremidade de cima
		up();
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
		
		snake.size++;
		
		int x1, y1,i;
		do{
			gerarDoce();
			break;
		}while(1);
		down();
	}
	else if(((y+1)<10 && mat[y+1][x] == '*') || ((y+1)==10)){ //Caso de teste quando se encontra o outra parte do corpo ou com a parede
		puts("GAMER OVER");
		exit(0);
	}
	else if((y+1)<10) { //Adicionando limite para a extremidade de baixo
	    down();
	}  
}

void down(){
	char aux;
	
	aux = mat[y][x];
	mat[y][x] = mat[y+1][x];
	mat[y+1][x] = aux;
	y +=1;
}
