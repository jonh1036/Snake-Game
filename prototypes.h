//  Created by Jonathan Pinho and Vinicius Mangueira 10/07/2018.
//  Aquivo onde ficará as protótipos de funções e structs


typedef struct _Position_ {
    int x,y;
};

struct _Snake_ {
    int size;
};

struct _Candy_ {
    _Position_ *CandyPosition;
    int life;
  
};
