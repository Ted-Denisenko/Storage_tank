#pragma once
#include <iostream>

double ContentValue(int level, int tankHeight, int tankDiameter);

double ContentMass(double contentValue, int contentDensity);

void printValue(double contentValue);

void printMass(double contentMass);