/**
 * CS 153 PROGRAM ASSIGNMENT #7
 * 
 * This source file descibes a simple
 * program splits an input stream into
 * chunks or "blocks".
 *
 * @author    Christopher Schmitt
 * @version   3.26.19
 */


#include <stdio.h>
#include <ctype.h>

int main(void)
{
  int count = 0;
  int value = 0;

  while ((value = getchar()) != EOF)
  {
    if (value >= 'a' && value <= 'z')
    {
      putchar(toupper(value));
      count += 1;
      if (count % 50 == 0)
        putchar('\n');
      else if (count % 5 == 0)
        putchar(' ');
    }
    
    if (value >= 'A' && value <= 'Z')
    {
      putchar(value);
      count += 1;
      if (count % 50 == 0)
        putchar('\n');
      else if (count % 5 == 0)
        putchar(' ');
    }
  }
}