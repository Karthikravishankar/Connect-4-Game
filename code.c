#include <stdio.h>
#include "code.h"
#include <stdlib.h>
#include <unistd.h>

void initialize(game_t *g)
{
  int i,j;
  for(i=0;i<9;i++)
    {
      for(j=0;j<9;j++)
	{
	  g->board[i][j] =0;
	}
    }
}

void print(game_t *g)
{
  int i,j;
  for(i=0;i<9;i++)
    {
      for(j=0;j<9;j++)
	{
	  if(g->board[i][j] ==0)
	    {
	      printf(". ");
	    }
	  else if(g->board[i][j] ==1)
	    {
	      printf("X ");
	    }
	  else if(g->board[i][j] ==2)
	    {
	      printf("O ");
	    }
	}
      printf("\n");
    }
  for(i = 0; i<9;i++)
    {
      printf("_ ");
    }
  printf("\n");
  for(i = 0; i<9;i++)
    {
      printf("%d ",i);
    }
  printf("\n");
}

int input(game_t *g)
{

  int move;
  int return_value = 0;
  char buffer[1024];

    scanf("%1024s", buffer);
    return_value = sscanf(buffer, "%d", &move);
  if(!return_value)
    {
      printf("Illegal Move - Invalid Input\n");
      sleep(1);
      return 0;
    }
{
  if(!(move == 1|| move ==2||move==3||move==4||move==5||move==6||move==7||move==8||move==0))
    {
      printf("Illegal Move - Enter b/w 0 and 8\n");
      sleep(1);
      return 0;
    }
  else
    {
      if(g->board[0][move] != 0)
	{
	  printf("Illegal Move - Column Full!\n");
	  sleep(1);
	  return 0;
	}
      place(g,move);
      return 1;
    }
  }
}

void place(game_t *g,int move)
{
  int i;
  for(i=8;i>=0;i--)
    {
      if(valid(g,move)==1)
	{
	  if(g->board[i][move] == 0)
	    {
	      if(g->player =='X')
		{
		  g->board[i][move] = 1;
		}
	      else if(g->player =='O')
		{
		  g->board[i][move] =2;
		}
	      return;
	    }
	}
    }
}

int valid(game_t *g,int move)
{
  if(g->board[0][move] != 0)
    {
      return 0;
    }
  else
    {
      return 1;
    }
}

int check(game_t *g)
{
  int i,j;
  //horizontal check
  for(i=0;i<9;i++)
    {
      for(j=0;j<9-3;j++)
	{
	  if(g->board[i][j] == 1 && g->board[i][j+1] == 1 && g->board[i][j+2] == 1 && g->board[i][j+3] == 1)
	    {
	      return 1;
	    }
	  else if(g->board[i][j] == 2 && g->board[i][j+1] == 2 && g->board[i][j+2] == 2 && g->board[i][j+3] == 2)
	    {
	      return 2;
	    }
	}
      
    }

  //vertical check
  for(i=0;i<9-3;i++)
    {
      for(j=0;j<9;j++)
	{
	  
	  if(g->board[i][j] == 1 && g->board[i+1][j] == 1 && g->board[i+2][j] == 1 && g->board[i+3][j] == 1)
	    {
	      return 1;
	    }
	  else if(g->board[i][j] == 2 && g->board[i+1][j] == 2 && g->board[i+2][j] == 2 && g->board[i+3][j] == 2)
	    {
	      return 2;
	    }
	}
      
    }
  
  //Diagonal check
  for (i=3; i<9; i++)
    {
    for (j=0; j<9-3; j++)
      {
	if (g->board[i][j] == 1 && g->board[i-1][j+1] == 1 && g->board[i-2][j+2] == 1 && g->board[i-3][j+3] == 1)
	  {
	    return 1;
	  }
	else if (g->board[i][j] == 2 && g->board[i-1][j+1] == 2 && g->board[i-2][j+2] == 2 && g->board[i-3][j+3] == 2)
	  {
	    return 2;
	  }
      }
    }
  // Anti Diagonal check
  for (i=3; i<9; i++)
    {
      for (j=3; j<9; j++)
	{
	  if (g->board[i][j] == 1 && g->board[i-1][j-1] == 1 && g->board[i-2][j-2] == 1 && g->board[i-3][j-3] == 1)
	    {
	      return 1;
	    }
	  else if (g->board[i][j] == 2 && g->board[i-1][j-1] == 2 && g->board[i-2][j-2] == 2 && g->board[i-3][j-3] == 2)
	    {
	      return 2;
	    }
	   
	}
    }
  

  return 0;
}

int main()
{
  printf("Hello\nWhat is your name?\n");
  char name[30];
  scanf("%s",name);
  printf("Would you like to play a game, %s?(Y or N)\n",name);
  char temp;
  scanf(" %c",&temp);
  if(temp =='Y' || temp=='y')
    {
      game_t g;
      g.status = 1;
      initialize(&g);
      g.turn =0;
      while(g.status ==1)
	{
	  if(g.turn %2 ==0)
	    {
	      g.player = 'X';
	    }
	  else
	    {
	      g.player = 'O';
	    }
	  system("clear");
	  print(&g);
	  printf("Enter move:\n\n");
	  int con = input(&g);
	  int winner = check(&g);
	  if(con ==1)
	    {
	      if(winner ==1)
		{
		  sleep(1.5);
		  system("clear");
		  print(&g);
		  printf("--------Player X wins--------\n");
		  g.status =0;
		}
	      else if(winner==2)
		{
		  sleep(1.5);
		  system("clear");
		  print(&g);
		  printf("--------Player O wins--------\n");
		  g.status =0;
		}
	      g.turn = g.turn +1;
	    }
	}
    }
  return 0;
}
