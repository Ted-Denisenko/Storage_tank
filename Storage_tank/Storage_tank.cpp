#include "Storage_tank.h"


double ContentValue(int contentLevel, int tankHeight, int tankDiameter)
{
	double tankValue = ((3.1415 * (tankDiameter / 2 * tankDiameter / 2) * tankHeight) / float(1000000000));
	double contentValue = ((3.1415 * (tankDiameter / 2 * tankDiameter / 2) * contentLevel) / float(1000000000));
	if (contentLevel > tankHeight)
	{
		std::cout << tankHeight << std::endl;
		return tankValue;
	}
	else
	{
		std::cout << contentValue << std::endl;
		return contentValue; //m^3
	}
}

double ContentMass(double contentValue, int contentDensity)
{
	double contentMass = contentValue * (float)contentDensity / (float)1000;
	std::cout << contentMass << std::endl;
	return contentMass; //tons
}