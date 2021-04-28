/**
 * CS 153 PROGRAM ASSIGNMENT #8
 * 
 * This source file describes a
 * simple sine function.
 *
 * @author    Christopher Schmitt
 * @version   3.26.19
 */

#include <math.h>

double mysin(double x)
{
  double sum = x;
  double term = x;

  int n;
  for (n = 3; fabs(term) > 0.0000001; n += 2)
  {
    term *= (-(x*x) / ((n-1) * n));
    sum += term;
  }

  return sum;
}