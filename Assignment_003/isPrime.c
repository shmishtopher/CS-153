/**
 * CS 153 PROGRAM ASSIGNMENT #3
 * 
 * This source file provides a integer
 * prime test algorithm.
 *
 * @author    Christopher Schmitt
 * @version   2.16.19
 */

long isqrt(long);

int isPrime(long num)
{
  long max = isqrt(num);
  long trial = 2;
  while (trial <= max)
  {
    if (num % trial == 0)
      return 0;
    trial++;
  }
  return 1;
}