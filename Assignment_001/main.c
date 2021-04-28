/**
 * CS 153 PROGRAM ASSIGNMENT #1
 * 
 * This source file describes a simple
 * program that takes the users weight
 * and height and then calculates the 
 * users BMI.
 *
 * @author    Christopher Schmitt
 * @version   1.23.19
 */

#include <stdio.h>

int main (void)
{
  double weight;
  double height;
  double bmi;

  printf("Enter weight in pounds: ");
  scanf("%lf", &weight);
  printf("Enter hight in inches: ");
  scanf("%lf", &height);

  bmi = (weight * 703.0) / (height * height);
  printf("BMI: %lf ", bmi);

  if (bmi < 18.5)
    printf("Underwight\n");
  else if (bmi >= 18.5 && bmi < 25.0)
    printf("Normal\n");
  else if (bmi >= 25.0 && bmi < 30.0)
    printf("Slightly Overweight\n");
  else if (bmi >= 30.0 && bmi < 40.0)
    printf("Overweight\n");
  else
    printf("Obese\n");

  system("pause");

  return 0;
}