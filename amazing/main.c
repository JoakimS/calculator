#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIN 100 

int rolldice(){
  return (rand()%6)+1;
}

int snake[3][2]=
  {{99,1},{56,34},{20,10}};
int ladder[3][2]=
  {{2,80},{30,70},{40,65}};

int checkladderandsnake(int pos){
  for(int i=0;i<3;i++){
    if(pos==snake[i][0]){
      printf("oooopps bitten by a snake in %d and now your in %d\n",snake[i][0], snake[i][1]);
      return snake[i][1];
    }
  }
  for(int i=0;i<3;i++){
    if(pos==ladder[i][0]){
      printf("yay climbed a ladder from %d up to %d\n",ladder[i][0], ladder[i][1]);
      return ladder[i][1];
    }
  }
  return pos;
}

void board(){
  int num=100;
  int size=10;

  for(int row=0;row<size;row++){
    if(row %2==0){
      for(int col=0;col<size;col++)
        printf("%4d",num--);
    } else {
      int start=num-size+1;
      for(int col=0;col<size;col++){
        printf("%4d",start++);
      }
      num -=size;
    }
    printf("\n\n");
  }
}

int main(){
  int player1=1, player2=1;
  int turn = 1;
  srand(time(NULL));
  
  printf("Welcome to snake and ladder game\n");
  
  board();

  while(player1<WIN && player2<WIN){
    printf("press Enter to roll the dice");
    getchar();
    int dice = rolldice();
    
    if(turn==1){
      printf("\nPlayer 1 turn\n");
      player1 += dice;
      if(player1 > WIN) player1 = WIN;
      player1 = checkladderandsnake(player1);
      printf("Player1 is at %d position\n", player1);
      if(player1==WIN){
        printf("Player1 won!\n");
        break;
      }
      turn=2;
    } else {
      printf("\nPlayer 2 turn\n");
      player2 += dice;
      if(player2 > WIN) player2 = WIN;
      player2 = checkladderandsnake(player2);
      printf("Player2 is at %d position\n", player2);
      if(player2==WIN){
        printf("Player2 won!\n");
        break;
      }
      turn=1;
    }
  }

  return 0;
}
