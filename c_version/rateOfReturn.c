//
//  rateOfReturn.c
//  Assignment 1
//
//  This program finds rate of return when given initial value final value
//  and time.
//
//  Created by Caeden Hoffschneider on 1/17/18.
//  Copyright © 2018 Caeden Hoffschneider. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]){

  double initialValue, finalValue, durationY, durationW, durationD, rateOfGrowth,
    base, power, duration;

  //Promt user for input
  printf("Initial Value: $");
  scanf("%lf", &initialValue);

  printf("Final Value: $");
  scanf("%lf", &finalValue);

  printf("Years:");
  scanf("%lf", &durationY);

  printf("Weeks:");
  scanf("%lf", &durationW);

  printf("Days:");
  scanf("%lf", &durationD);

  if (durationY<0 || durationW<0 || durationD<0) {
    printf("Must be positive!\n");
    exit(2);
  }

  duration = durationY + (durationW*7/365) + (durationD/365);
  base = (finalValue/initialValue);
  power = (1/duration);
  rateOfGrowth = ((pow(base, power)) - 1)*100;

  printf("Anual Rate of Return: %.3f% \n", rateOfGrowth);


  return 0;
}
