/**
 * CS 153 PROGRAM ASSIGNMENT #6
 * 
 * This source file descibes a simple
 * program that calculates Pi by throwing
 * darts
 *
 * @author    Christopher Schmitt
 * @version   3.16.19
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void throwDart(double *x, double *y)
{
  *x = (double) rand() / RAND_MAX * 2 - 1;
  *y = (double) rand() / RAND_MAX * 2 - 1;
}

void main(void)
{
  srand(time(NULL));
  int number = 0;
  int count = 0;

  printf("How many darts would you like to throw? ");
  scanf("%d", &number);

  int i;
  for (i = 0; i < number; i++)
  {
    double x;
    double y;
    throwDart(&x, &y);
    if ((x * x + y * y) <= 1.0) 
      count += 1;
  }

  printf("Pi is roughly equal to %lf\n", 4.0 * count / number);

  system("pause");
  return 0;
}