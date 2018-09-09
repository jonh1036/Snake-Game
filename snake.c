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
void direita();
void esquerda();
void cima();
void baixo();
void rigth();
void left();
void up();
void down();
int ponteiroNulo(Position *p);
void insertO();
void clear();
void movimentar(Position *p);
void gameOp();

int x = 2, y = 0;//Coordenadas da matriz
char mat[MAT][MAT];//Cria��o da matriz
char tecla = 'd';
Snake snake;
Candy candy;


int main(void) {
    inicializa();//Inicializa��o da Matriz
    while(1){
		void gameOp();
    }
    printf("\n\n");	
	return 0;
}

void inicializa(){//Fun��o que inicializa a matriz no in�cio do programa
    int i, j;
	snake.size = 3; 
	snake.p = (Position*) malloc(sizeof(Position) * snake.size);
	ponteiroNulo(snake.p);
	
	for(i = 0; i < snake.size;i++) {
		snake.p[i].y = snake.size - i - 1;
		snake.p[i].x = 0;
	}

	for(i = 0; i < 10; i++ )
        for(j = 0; j < 10; j++){
        	if(i == 0 && (j>=0 && j<=2)){
        		mat[i][j] = '*';//Origem
			}
			else
				mat[i][j] = ' ';
		}
	clear();
    gerarDoce();
    insertO();
	imprimir();
}

void clear(){
    int i, j;
	for(i = 0; i < MAT ; i++)
        for(j = 0; j < MAT ; j++){
            mat[i][j] = ' ';
        }    
}

void imprimir(){//Fun��o que imprime a matriz completa
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
            candy.position.x = rand() %10; //Gera uma coordenada aleat�ria no eixo X
            candy.position.y = rand() %10; //Gera uma coordenada aleat�ria no eixo Y
            //candy.position.x = x1;
			//candy.position.y = y1;
    	}
		if(mat[candy.position.y][candy.position.x] == ' '){
			mat[candy.position.y][candy.position.x] = '$';
			//insertO();
			break;
		}
	}while(1);
	
	candy.life = rand()%10;
}

void insertO() {
	int i;
	//mat[candy.position.x][candy.position.y] = '$';//TALVEZ APAGAR
	
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

void gameOp() {
	char tec;
	
	Position head = snake.p[0];
	
	
	if (kbhit()){
		tec = getch();
		if( (tecla=='a' && tec != 'd') || (tecla=='d' && tec != 'a') || (tecla=='w' && tec != 's') || (tecla=='s' && tec != 'w') ){
			tecla = tec;	
		}
	}
	system("cls");
	switch(tecla){
	    case 'a':	head.x--;//Movimentar para esquerda
	    			candy.life--;
	        break;
	    case 'd':	head.x++;//Movimentar para direita
	    			candy.life--;
	        break;
		case 'q':	exit(0);//Para encerrar o jogo
	      	
		case 's':	head.y++;//Movimentar para baixo
					candy.life--;
	    	break;
	    case 'w':	head.y--;//Movimentar para cima
	    			candy.life--;
	        break;
	    default: printf("Teclas permitidas: \nPara cima (tecla W), \nPara baixo (tecla S),\nPara a esquerda (tecla A)\nPara a direita (tecla D)\nPara sair (tecla Q)\n\n");
	        break;
       }
    
    if(candy.life == 0){
    	mat[candy.position.y][candy.position.x] = ' ';
    	gerarDoce();
	}
	
	if(head.x == candy.position.x && head.y == candy.position.y) {
		snake.size++;
		gerarDoce();
	}
	
	movimentar(head);
	
    
	imprimir();
	
	
}

void movimentar(Position *p){//mover
	snake.p = (Position *) realloc(snake.p, snake.size * sizeof(Position));
	int i;
	for(i = snake.size -1 ; i >= 0 ;i-- ){
        if(i == 0)
            snake.p[i] = *p;
		else
            snake.p[i] = snake.p[i - 1] ;
    }
	
    for(i = 1; i < snake.size; i++){
        if(snake.p[0].x == snake.p[i].x  &&  snake.p[0].y == snake.p[i].y){
           	puts("GAMER OVER");
			exit(0);
        }
    }

    if( MAT < snake.p[0].x || snake.p[0].x < 0  ||  MAT < snake.p[0].y  ||  snake.p[0].y < 0 ){
        	puts("GAMER OVER");
			exit(0);
    }
	
}


void direita(){//Fun��o que move o '*' para a direita
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

void esquerda(){//Fun��o que move o '*' para a esquerda
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

void cima(){//Fun��o que move o '*' para a cima
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

void baixo(){//Fun��o que move o '*' para a baixo
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
