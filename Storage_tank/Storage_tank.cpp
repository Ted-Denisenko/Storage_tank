#include <iostream>
#include "Storage_tank.h"
// Необходимо реализовать ввод через консоль уровня содержимого резервуара в мм.


int LevelInput()
{
	int level;
	std::cout << "Input tank content level (in mm)" << std::endl << "Level = ";
	std::cin >> level;
	return level;
}

float ContentValue(int level)
{
	int tankDiameter = 4; //meters
	float contentValue = 3.14 * (tankDiameter) / 2 * (float(level) / float(1000));
	std::cout << "\nValue of content is " << contentValue << std::endl;
	return contentValue;
}

float ContentMass(float contentValue)
{
	int contentDensity = 1040; //kg/m^3
	float contentMass = contentValue * contentDensity;
	std::cout << "Mass of content is " << contentMass << std::endl;
	return contentMass;
}