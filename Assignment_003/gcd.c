/**
 * CS 153 PROGRAM ASSIGNMENT #3
 * 
 * This source file provides a greatest
 * common denominator algorithm.
 *
 * @author    Christopher Schmitt
 * @version   2.16.19
 */

long gcd(long a, long b)
{
  if (b == 0)
    return a;
  else
    return gcd(a, a % b);
}