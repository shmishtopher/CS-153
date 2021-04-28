/**
 * CS 153 PROGRAM ASSIGNMENT #8
 * 
 * This source file describes a
 * simple cosine function.
 *
 * @author    Christopher Schmitt
 * @version   3.26.19
 */

#include <math.h>

double mycos(double x)
{
  double sum = 1;
  double term = 1;

  int n;
  for (n = 2; fabs(term) > 0.0000001; n += 2)
  {
    term *= (-(x*x) / ((n-1) * n));
    sum += term;
  }

  return sum;
}