#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define MAT 10
#define MAX_WORM 100
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
void aux(Position p);
void clear();
void gerarDoce();
void imprimir();
void inicializa();
void insert();
void movimentar();
int ponteiroNulo(Position *p);
char mat[MAT][MAT];//Cria��o da matriz
char tecla = 'd';//Tecla de in�cio de jogo
Snake snake;//Vari�vel global para a cobra
Candy candy;//Vari�vel global para o doce

int main(void) {
	inicializa();
	movimentar();
    printf("\n\n");	
	return 0;
}

void inicializa(){//Inicializa a matriz no in�cio do programa
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

void movimentar(){//mover
	char tec;
	int i;
	
	Position head = snake.p[0];
	while(1){
		imprimir();
		
		if (kbhit()){
			tec = getch();
			if((tecla=='a' && tec != 'd') || (tecla=='d' && tec != 'a') || (tecla=='w' && tec != 's') || (tecla=='s' && tec != 'w') || (tec == 'q')){
				if(tec != 'w' && tec != 's' && tec != 'd' && tec != 'a' && tec != 'q'){
					printf("Teclas permitidas: \nPara cima (tecla W), \nPara baixo (tecla S),\nPara a esquerda (tecla A)\nPara a direita (tecla D)\nPara sair (tecla Q)\n\n");
					sleep(2);
				}
				else{
					tecla = tec;
				}
			}
		}
		switch(tecla){
	    	case 'a':	head.y--;
	    				candy.life--;
	    	    break;
	    	case 'd':	head.y++;
						candy.life--;
	    	    break;
			case 'q':	free(snake.p);
						exit(0);//Para encerrar o jogo
	    	  	
			case 's':	head.x++;
						candy.life--;
	    		break;
	    	case 'w':	head.x--;
						candy.life--;
	    	    break;
	    	default:
	    	    break;
		}
		if(candy.life == 0){//Caso a vida do doce acabe, ser� criado outro doce em outra posi��o aleat�ria na matriz
    		mat[candy.position.y][candy.position.x] = ' ';
    		gerarDoce();
		}
	
		if(head.x == candy.position.x  &&  head.y == candy.position.y ){//Caso de teste para a colis�o da cobra com um doce
    	   	snake.size++;
    		gerarDoce();
    	}
		
		if(head.x == 10 || head.x == -1 || head.y == 10 || head.y == -1){//Caso de teste para verificar se a cobra bateu em alguma extremidade da matriz
			puts("\nGame Over PAREDE");
			free(snake.p);
			exit(0);
		}
	
		for(i = 1; i < snake.size; i++){//Verifica se bateu no pr�prio corpo
    	    if(snake.p[0].x == snake.p[i].x  &&  snake.p[0].y == snake.p[i].y){
    	        puts("\nGame Over CORPO");
				free(snake.p);
				exit(0);
    	    }
    	}
    	usleep(100000);
		aux(head);
		clear();
		gerarDoce();
		insert();
		system("cls");
	}
}

void aux(Position p){
	int i;
	
	snake.p = (Position *) realloc( snake.p, snake.size * sizeof(Position));//Realoca a mem�ria para aumentar o corpo da cobra
	for(i = snake.size -1; i >= 0 ;i--){
        if(i == 0){
            snake.p[i] = p;
        }
		else{
            snake.p[i] = snake.p[i - 1] ;
        }
    }
}

void clear(){//Limpa a matriz
    int i, j;
	for(i = 0; i < MAT ; i++)
        for(j = 0; j < MAT ; j++){
            mat[i][j] = ' ';
        }    
}

void imprimir(){//Imprime a matriz
    int i, j;
    for(i = 0; i < 10; i++){
        printf("|");
        for(j = 0; j < 10; j++){
            printf("%c",mat[i][j]);
        }
        printf("|\n");
    }
}

void gerarDoce(){//Gera um doce com coordenada aleat�ria
	int i;
	
	do{
	   	srand(time(NULL));
     	for (i=0; i<1; i++){
            candy.position.x = rand() %10; //Gera uma coordenada aleat�ria no eixo X
            candy.position.y = rand() %10; //Gera uma coordenada aleat�ria no eixo Y
    	}
		if(mat[candy.position.y][candy.position.x] == ' '){
			mat[candy.position.y][candy.position.x] = '$';
			break;
		}
	}while(1);
	candy.life = rand()%10;//Define a vida do doce
}
void insert(){//Cadastra o corpo da cobra na matriz
	int i;
	for(i = 0; i < snake.size; i++) {
		mat[snake.p[i].x][snake.p[i].y] = '*';
	}
}
int ponteiroNulo (Position *p){//Retorna verdadeiro ou falso para a aloca��o de mem�ria
	if(p == NULL) {
		printf("Doesn't possible alloc");
		exit(1);
	}
	return 0;
}
