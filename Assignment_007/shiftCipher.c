/**
 * CS 153 PROGRAM ASSIGNMENT #7
 * 
 * This source file descibes a simple
 * program that performas a shift cipher
 * on an input stream.
 *
 * @author    Christopher Schmitt
 * @version   3.26.19
 */


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  int value = 0;
  int shift = atoi(argv[1]);

  while ((value = getchar()) != EOF)
  {
    if (value >= 'a' && value <= 'z')
      putchar((value - 'a' + shift) % 26 + 'a');
    
    if (value >= 'A' && value <= 'Z')
      putchar((value - 'A' + shift) % 26 + 'A');
    
    if (value == ' ' || value == '\n')
      putchar(value);
  }
}