/**
 * CS 153 PROGRAM ASSIGNMENT #2
 * 
 * This source file describes a simple
 * program that counts the number of times
 * that each letter [a .. Z] appears in
 * an input file.
 *
 * Usage: count < FILE.txt
 *
 * @author    Christopher Schmitt
 * @version   1.23.19
 */

#include <stdio.h>

int main(void)
{
  int map[52] = {0};
  int letter = 0;

  while ((letter = getchar()) != EOF)
  {
    if (letter > 64 && letter < 91)
      map[letter - 65] += 1;
    else if (letter > 96 && letter < 123)
      map[letter - 71] += 1;
  }

  int i;
  for (i = 0; i < 52; i++)
  {
    if (i < 26)
      printf("%c occured %d times\n", i + 65, map[i]);
    else
      printf("%c occured %d times\n", i + 71, map[i]);
  }

  system("pause");
  return 0;
}