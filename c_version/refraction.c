//
//  refraction.c
//  Assignment 1
//
//  This program finds the angle of refraction when given the angle
//  of incidence and index of refraction
//
//  Created by Caeden Hoffschneider on 1/17/18.
//  Copyright © 2018 Caeden Hoffschneider. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]){

  double angleOfIncidence, refractionIndex, radians, degrees, refractionAngle;

  //Promting use for imput
  printf("Angle of incidence:\n");
  //Scan for imput
  scanf("%lf", &angleOfIncidence);

  if (angleOfIncidence > 180 || angleOfIncidence < -180) {
    printf("ERROR: Angle must be between -180 and 180!\n");
    exit(1);
    }

  radians = angleOfIncidence*M_PI/180;

  printf("Index of refraction:\n");
  scanf("%lf", &refractionIndex);

  if (refractionIndex < 1) {
    printf("ERROR: Invalid refraction index level!\n");
    exit(1);
    }

  degrees = asin((sin(radians))/refractionIndex);

  refractionAngle = degrees*180/M_PI;

  printf("Angle of refraction: %lf\n", refractionAngle);


  return 0;
}
