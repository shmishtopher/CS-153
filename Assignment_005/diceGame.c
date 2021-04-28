/**
 * CS 153 PROGRAM ASSIGNMENT #5
 * 
 * This source file descibes a simple
 * program that plays a game of dice
 * against a computer opponent.
 *
 * @author    Christopher Schmitt
 * @version   3.2.19
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void roll(int number, int *player)
{
  int i;
  for (i = 0; i < number; i++)
  {
    player[i] = rand() % 6 + 1;
  }
}


int max(int *array, int length)
{
  int max = 0;
  int i;
  for (i = 0; i < length; i++)
  {
    if (array[i] > max)
      max = array[i];
  }
  return max;
}


int main(void)
{
  srand(time(NULL));
  int extraRoll = 0;
  int humanScore = 0;
  int robotScore = 0;
  int humanMax = 0;
  int robotMax = 0;
  int humanToss[4];
  int robotToss[4];
  char buffer[195];

  int round;
  for (round = 0; round < 7; round++)
  {
    printf("\nRound %d\n\n", round + 1);
    printf("Player's turn: (hit enter)\n");
    getchar();

    /* Player's Turn */
    roll(3, humanToss);
    humanMax = max(humanToss, 3);
    printf("You throw: ");
    printf("%d, ", humanToss[0]);
    printf("%d, ", humanToss[1]);
    printf("%d  ", humanToss[2]);
    printf("\nThe max is: %d", humanMax);
    printf("\nDo you wish to throw again? [Y or N] ");

    if (getchar() == 'Y')
    {
      extraRoll = 1;
      roll(3, humanToss);
      humanMax = max(humanToss, 3);
      printf("\nYou throw: ");
      printf("%d, ", humanToss[0]);
      printf("%d, ", humanToss[1]);
      printf("%d  ", humanToss[2]);
      printf("\nYour final score is %d\n", humanMax);
    }

    /* Computer's Turn */
    if (extraRoll)
    {
      extraRoll = 0;
      roll(4, robotToss);
      robotMax = max(robotToss, 4);
      printf("\nComputer's Turn:\n");
      printf("Computer throws: ");
      printf("%d, ", robotToss[0]);
      printf("%d, ", robotToss[1]);
      printf("%d, ", robotToss[2]);
      printf("%d  ", robotToss[3]);
      printf("\nComputer's score is %d\n", robotMax);
    }
    else
    {
      roll(3, robotToss);
      robotMax = max(robotToss, 3);
      printf("\nComputer's Turn:\n");
      printf("Computer throws: ");
      printf("%d, ", robotToss[0]);
      printf("%d, ", robotToss[1]);
      printf("%d  ", robotToss[2]);
      printf("\nComputer's score is %d\n", robotMax);
    }

    /* Compare Rolls */
    if (humanMax > robotMax)
    {
      printf("The Huamn scores!\n");
      printf("Human: %d\n", humanScore += 1);
      printf("computer: %d\n", robotScore += 0);
    }
    else
    {
      printf("The Computer scores!\n");
      printf("Human: %d\n", humanScore += 0);
      printf("computer: %d\n", robotScore += 1);
    }
  }

  /* Compare Scores */
  if (robotScore > humanScore)
    printf("\nThe Computer Wins!!!\n");
  else if (humanScore > robotScore)
    printf("\nThe Human Wins!!!\n");
  else
    printf("\nIt's a Tie!!!\n");

  system("pause");
  return 0;
}