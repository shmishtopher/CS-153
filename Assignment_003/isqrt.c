/**
 * CS 153 PROGRAM ASSIGNMENT #3
 * 
 * This source file provides a integer
 * square root algorithm.
 *
 * @author    Christopher Schmitt
 * @version   2.16.19
 */

long isqrt(long num)
{
  long trial = 2;
  while (trial * trial <= num)
    trial++;
  return trial - 1;
}

/* Newton's method (O(LOG n)) */
/*
long isqrt(long num) {
  long x = num;
  long y = (num + 1) / 2;
  while (y < x)
  {
    x = y;
    y = (x + num / x) / 2;
  }
  return x;
}
*/