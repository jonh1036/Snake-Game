#include "prototypes.h"

char mat[MAT][MAT];//Criação da matriz
char tecla = 'd';//Tecla de início de jogo
Snake snake;//Variável global para a cobra
Candy candy;//Variável global para o doce

void gameOptions() {
	int op;
	printf("Welcome to the Snake Game \n Press 1 to start the new Game \n Press 2 to continue game \n");
	scanf("%d",&op);
	switch(op) {
		case 1: inicializa();
				fileHelperW(); //Inciar� com as configura��es inciais e insere no arquivo	
		case 2: inicializa();
				fileHelperL();	
				//Falta inicializar com as posi��es
	}
}
void inicializa(){//Inicializa a matriz no início do programa
    int i;
	snake.size = 3; 
	snake.p = (Position*) malloc(snake.size * sizeof(Position));
	ponteiroNulo(snake.p);
    
	for(i = 0; i < snake.size;i++) {
		snake.p[i].x = snake.size - i - 1;
		snake.p[i].y = 0;
	}
	clear();
    gerarDoce();
    insert();
    movimentar();
}

void movimentar(){//mover
	char tec;
	Position head = snake.p[0];
	while(1){
		imprimir();
		
		if (kbhit()){
			tec = getch();
			if((tecla=='a' && tec != 'd') || (tecla=='d' && tec != 'a') || (tecla=='w' && tec != 's') || (tecla=='s' && tec != 'w') || (tec == 'q')){
				if(tec != 'w' && tec != 's' && tec != 'd' && tec != 'a' && tec != 'q' && tec != 'r'){
					printf("Teclas permitidas: \nPara cima (tecla W), \nPara baixo (tecla S),\nPara a esquerda (tecla A)\nPara a direita (tecla D)\nPara sair (tecla Q)\n\n");
					sleep(2);
				}
				else if(tec == 'r')
					fileHelperW();
				else
					tecla = tec;
			}
		}
		switch(tecla){
            case 'A':
	    	case 'a':	head.x--;
	    	    break;
            
            case 'D':
	    	case 'd':	head.x++;
	    	    break;
            
            case 'Q':
			case 'q':	free(snake.p);
						exit(0);//Para encerrar o jogo
			
            case 'S':
            case 's':	head.y++;
	    		break;
	    	
            case 'W':
            case 'w':	head.y--;
	    	    break;
            
            case 'R':
	    	case 'r': //fileHelperW();
	    			  //free(snake.p);
	    			  break;
	    	default:
	    	    break;
		}
		candy.life--;
		if(candy.life == 0){//Caso a vida do doce acabe, será criado outro doce em outra posição aleatória na matriz
    		mat[candy.position.y][candy.position.x] = ' ';
    		gerarDoce();
		}
		colider(head);
    	usleep(125000);//0,125 segundos de delay
    	crescer(head);
		clear();
		mat[candy.position.y][candy.position.x] = '$';
		insert();
		system("cls");
	}
}

void colider(Position head) {
		int i;
	
		if(head.x == candy.position.x  &&  head.y == candy.position.y ){//Caso de teste para a colisão da cobra com um doce
    	   	snake.size++;
    		gerarDoce();
    	}
		
		if(head.x == MAT || head.x == -1 || head.y == MAT || head.y == -1){//Caso de teste para verificar se a cobra bateu em alguma extremidade da matriz
			puts("\nGame Over");
			free(snake.p);
			exit(0);
		}
	
		for(i = 1; i < snake.size; i++){//Verifica se bateu no próprio corpo
    	    if(head.x == snake.p[i].x  &&  head.y == snake.p[i].y){
    	        puts("\nGame Over");
				free(snake.p);
				exit(0);
    	    }
    	}
}

void crescer(Position p){
	int i;
	
	snake.p = (Position *) realloc( snake.p, snake.size * sizeof(Position));//Realoca a memória para aumentar o corpo da cobra
	for(i = snake.size -1; i >= 0 ;i--){
        if(i == 0)
            snake.p[i] = p;
		else
            snake.p[i] = snake.p[i - 1] ;
    }
}

void clear(){//Limpa a matriz
    int i, j;
	for(i = 0; i < MAT ; i++)
        for(j = 0; j < MAT ; j++)
            mat[i][j] = ' ';   
}

void imprimir(){//Imprime a matriz
    int i, j;
    for(i = 0; i < 10; i++){
        printf("|");
        for(j = 0; j < 10; j++)
            printf("%c",mat[i][j]);
        printf("|\n");
    }
}

void gerarDoce(){//Gera um doce com coordenada aleatória
	int i;
	
	do{
	   	srand(time(NULL));
        candy.position.x = rand() %10; //Gera uma coordenada aleatória no eixo X
        candy.position.y = rand() %10; //Gera uma coordenada aleatória no eixo Y
		if(mat[candy.position.y][candy.position.x] == ' '){
			mat[candy.position.y][candy.position.x] = '$';
			break;
		}
	}while(1);
	candy.life = abs(snake.p[0].y - candy.position.y) + abs(snake.p[0].x - candy.position.x) + 1;//Define a vida do doce pela quantidade de movimentos que faltam pra cobra chegar
}

void insert(){//Cadastra o corpo da cobra na matriz
	int i;
	for(i = 0; i < snake.size; i++) 
		mat[snake.p[i].y][snake.p[i].x] = '*';
}

int ponteiroNulo (Position *p){//Retorna verdadeiro ou falso para a alocação de memória
	if(p == NULL) {
		printf("Doesn't possible alloc");
		exit(1);
	}
	return 0;
}

void fileHelperW() { //Helper de file, para escrever as posi��es do doce e cobra respectivamente no arquivo settings
	FILE *arq;
	int i, j;
	
	arq = fopen("settings.txt", "w");  // Cria um arquivo texto para grava��o
	if (arq == NULL) {	printf("Problemas na CRIACAO do arquivo\n"); return;}
	fprintf(arq, "Tamanho da snake: %d\n\n", snake.size);
	for(i = 0; i < MAT; i++){
		for(j = 0; j < MAT; j++){
			if(mat[i][j] == '*')
				fprintf(arq, "%d ", j);
			else
				fprintf(arq, " ");
		}
		fprintf(arq, "\n");
	}
	fprintf(arq, "\nVida do doce: %d\n", candy.life);
	fprintf(arq, "Doce X e Y: %d %d\n", candy.position.x, candy.position.y);
 	fclose(arq);
}

void fileHelperL() { //Ler do arquivo... Posteriormente definir um aquivo C de helper pra manipular s� o aquivo
	FILE *arq;
	int verifyArq;
	arq = fopen("settings.txt", "r");
	verifyArq = (arq == NULL) ? 1 : 0;
	if(verifyArq == 1) { printf("Problemas em abrir o arquivo"); return; }
	fscanf(arq, "%d %d %d %d %d",candy.position.x, candy.position.y, candy.life, *snake.p, snake.size); //Pega os valores que o arquivo cont�m e coloca nas vari�veis
	printf("%d %d %d",candy.position.x, candy.position.y, candy.life);
}
