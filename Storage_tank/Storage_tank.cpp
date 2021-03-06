#include "Storage_tank.h"


double ContentValue(int contentLevel, int tankHeight, int tankDiameter)
{
	double tankValue = ((3.1415 * (tankDiameter / 2 * tankDiameter / 2) * tankHeight) / float(1000000000));
	double contentValue = ((3.1415 * (tankDiameter / 2 * tankDiameter / 2) * contentLevel) / float(1000000000));
	if (contentLevel > tankHeight)
	{
		return tankValue;
	}
	else
	{
		return contentValue; //m^3
	}
}

double ContentMass(double contentValue, int contentDensity)
{
	double contentMass = contentValue * (float)contentDensity / (float)1000;
	return contentMass; //tons
}

void printValue(double contentValue)
{
	std::cout << "Content value is " << contentValue << " m^3" << std::endl;
}

void printMass(double contentMass)
{
	std::cout << "Content mass is " << contentMass << " tons" << std::endl;
}