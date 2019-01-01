#include<stdio.h>


typedef struct pair{
  int x;
  int y;
}pair_t;

typedef struct game{
  int board[9][9];
  int status;
  pair_t pos;
  int turn;
  char player;
}game_t;


void initialize(game_t *g);
void print(game_t *g);
void place(game_t *g, int move);
int input(game_t *g);
int valid(game_t *g, int move);
int check(game_t *g);
