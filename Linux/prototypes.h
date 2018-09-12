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
char getch();
int valueRandom(int number);
