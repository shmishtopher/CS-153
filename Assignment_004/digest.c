/**
 * CS 153 PROGRAM ASSIGNMENT #4
 * 
 * This source file descibes a simple
 * program that calculates the digest
 * for a file
 *
 * Usage: digest < MY_FILE.txt
 *
 * @author    Christopher Schmitt
 * @version   2.16.19
 */

#include <stdio.h>
#include <fcntl.h>
#include <io.h>

/* Set read mode to binary */
_setmode(_fileno(stdin), _O_BINARY);

int main(void)
{
  int s1 = 0;
  int s2 = 0;
  int s3 = 0;
  int s4 = 0;
  int m1 = 3;
  int m2 = 7;
  int m3 = 13;
  int m4 = 23;

  int byte;
  while ((byte = getchar()) != EOF)
  {
    s1 = (s1 + byte * m1) % 256;
    s2 = (s1 + s2 + byte * m2) % 256;
    s3 = (s1 + s2 + s3 + byte * m3) % 256;
    s4 = (s1 + s2 + s3 + s4 + byte * m4) % 256;
  }
  
  printf("%02x%02x%02x%02x\n", s1, s2, s3, s4);

  system("pause");
  return 0;
}