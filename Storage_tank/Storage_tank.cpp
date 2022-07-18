#include "Storage_tank.h"

// Необходимо реализовать ввод через консоль уровня содержимого резервуара в мм.

// TODO: брать аргумент из ком. строки
int LevelInput(char* argv)
{
	int iargv{ 0 };
	int level{4000};
	return level;
}

float ContentValue(int level)
{
	int tankDiameter = 4000; //milimeters
	int tankHeight = 4000; //milimeters
	float contentValue = 3.14 * (tankDiameter) / 2 * (float(level) / float(1000));
	if (contentValue > tankHeight)
	{
		std::cout << "TANK OVERFLOW!!!" << std::endl;
		std::cout << "\nValue of content is " << tankHeight << ", lost due overflow: " << contentValue-(tankHeight/1000) << std::endl;
		return tankHeight;
	}
	else
	{
		std::cout << "\nValue of content is " << contentValue << std::endl;
		return contentValue; //m^3
	}
}

float ContentMass(float contentValue)
{
	int contentDensity = 1040; //kg/m^3
	float contentMass = contentValue * contentDensity / 1000;
	std::cout << "Mass of content is " << contentMass << std::endl;
	return contentMass; //tons
}