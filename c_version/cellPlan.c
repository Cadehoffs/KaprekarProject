//
//  bearing.c
//  Assignment 1
//
//  This program calculates the amount of Data on a cell plan and copares
//  it to the usage.
//
//  Created by Caeden Hoffschneider on 1/17/18.
//  Copyright © 2018 Caeden Hoffschneider. All rights reserved.
//

#include "stdlib.h"
#include "stdio.h"
#include "math.h"

int main(int argc, char const *argv[]) {

  double planGb, dayNumber, totalGbUsed, averageUse, recomendedUse,
    remainingDays, remainingUse, excedingUse, remainingGb;

  printf("Enter amount of data in plan:\n");
  scanf("%lf", &planGb);

  printf("Enter the current day:\n");
  scanf("%lf", &dayNumber);

  printf("Enter amount of data used:\n");
  scanf("%lf", &totalGbUsed);

  if (totalGbUsed > planGb) {
    printf("You are over your limit!\n");
    return 0;
  }

  remainingGb = planGb - totalGbUsed;
  recomendedUse = planGb/30;
  averageUse = totalGbUsed/dayNumber;
  remainingDays = 30 - dayNumber;
  remainingUse = remainingGb/remainingDays;
  excedingUse = averageUse*remainingDays + totalGbUsed - planGb;

  printf("%.0f days used, %.0f remaining\n"
    "%.2f GB remaining\n"
    "Your average usage: %.2f GB/Day\n", dayNumber, remainingDays, remainingGb,
    averageUse);

  if (recomendedUse > averageUse) {
    printf("You are below target with your average daily use\n"
      "You may use %.2f GB/day for the remainder of the month!", remainingUse);
  } else if (recomendedUse < averageUse) {
    printf("You are exceeding your recomended daily use of %.2f GB/days\n"
      "If you continue you will exceed your plan by %.2f GB\n"
      "Please reduce usage to %.2f GB/day\n", recomendedUse, excedingUse,
      remainingUse);
  } else if (recomendedUse = averageUse) {
    printf("You are on target with this months usage\n");
  }


  return 0;
}
