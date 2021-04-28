/**
 * CS 153 PROGRAM ASSIGNMENT #10
 * 
 * This source file describes a
 * simple cipher program
 *
 * @author    Christopher Schmitt
 * @version   4.29.19
 */


#include <stdlib.h>
#include <stdio.h>


static unsigned int a = 998;
static unsigned int c = 53;
static unsigned int m = 997;
static unsigned int x;


unsigned int random()
{
  x = (a * x + c) % m;
  return x;
}


void startRandom(unsigned int seed)
{
  x = seed;
}


int main(int argc, char **argv) {
  FILE *input = fopen(argv[2], "rb");
  FILE *output = fopen(argv[3], "wb");

  startRandom(atoi(argv[1]));

  int byte;
  while ((byte = fgetc(input)) != EOF)
  {
    unsigned int rand = random();
    fputc(byte ^ rand, output);
  }

  fclose(input);
  fclose(output);
  return 0;
}