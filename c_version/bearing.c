//
//  bearing.c
//  Assignment 1
//
//  This program that finds the bearing of one point to the next given the
//  latitude and longitude.
//
//  Created by Caeden Hoffschneider on 1/17/18.
//  Copyright © 2018 Caeden Hoffschneider. All rights reserved.
//

#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int main(int argc, char const *argv[]) {

  double originNorth, originWest, destinationNorth, destinationWest,
    radiansOriginNorth, radiansOriginWest, radiansDestinationNorth,
    radiansDestinationWest, bearingRadian, bearing, deltaWest, bearingPositive;

  //Prompt for input
  printf("Enter Latitude and Longitude of Origin\n");
  scanf("%lf %lf", &originNorth, &originWest);

  printf("Enter Latitude and Longitude of Destination\n");
  scanf("%lf %lf", &destinationNorth, &destinationWest);

  //convert from degrees to radians
  radiansOriginNorth = originNorth*M_PI/180;
  radiansOriginWest = originWest*M_PI/180;
  radiansDestinationNorth = destinationNorth*M_PI/180;
  radiansDestinationWest = destinationWest*M_PI/180;

  deltaWest = radiansDestinationWest - radiansOriginWest;
  bearingRadian = atan2(sin(deltaWest)*cos(radiansDestinationNorth),
      cos(radiansOriginNorth)*sin(radiansDestinationNorth) -
      sin(radiansOriginNorth)*cos(radiansDestinationNorth)*cos(deltaWest));

  bearing = 180*bearingRadian/M_PI;

  if (bearing < 0) {
    bearingPositive = bearing + 360;
    printf("From (%lf, %lf) to (%lf, %lf):\n bearing %lf degrees",
      originNorth, originWest, destinationNorth, destinationWest,
      bearingPositive);
    return 0;
  }

  printf("From (%lf, %lf) to (%lf, %lf):\n bearing %lf degrees",
    originNorth, originWest, destinationNorth, destinationWest, bearing);

  return 0;
}
