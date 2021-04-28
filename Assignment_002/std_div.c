/**
 * CS 153 PROGRAM ASSIGNMENT #2
 * 
 * This source file describes a simple
 * program that calculates the normal
 * distribution for a given X.
 *
 * @author    Christopher Schmitt
 * @version   1.23.19
 */

/* This flag enables M_PI in versions < C99 */
#define  _USE_MATH_DEFINES

#include <math.h>
#include <stdio.h>

/* M_PI removed in C99, I don't know what the   */
/* professor uses, so this is here for security */
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

double normal(double x, double sigma, double mu)
{
  double result = 0.0;

  result += exp(-((x - mu) * (x - mu) / (sigma * sigma * 2)));
  result *= 1 / (sigma * sqrt(2 * M_PI));

  return result;
}

int main(void)
{
  double mu;
  double sigma;
  int n;

  printf("Enter mean u: ");
  scanf("%lf", &mu);
  printf("Enter std dev s: ");
  scanf("%lf", &sigma);

  if (sigma == 0)
  {
    printf("Error: Sigma must be non-zero\n");
    return 0;
  }

  printf("Number of X values: ");
  scanf("%d", &n);

  double x;
  int i;
  for (i = 0; i < n; i++)
  {
    printf("X value %i: ", i + 1);
    scanf("%lf", &x);
    printf("f(x) = %f\n", normal(x, sigma, mu));
  }

  system("pause");
  return 0;
}