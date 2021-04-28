/**
 * CS 153 PROGRAM ASSIGNMENT #3
 * 
 * This source file provides the driver
 * program for "isPrime.c".
 *
 * @author    Christopher Schmitt
 * @version   2.16.19
 */

#include <stdio.h>
int isPrime(long);

int main(void)
{
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);

  if (isPrime(num))
    printf("%d is prime\n", num);
  else
    printf("%d is not prime\n", num);

  system("pause");
  return 0;
}