#include <iostream>

// Необходимо реализовать ввод через консоль уровня содержимого резервуара в мм.
int LevelInput()
{
	int level;
	std::cout << "Input tank content level (in mm)" << std::endl << "Level = ";
	std::cin >> level;
	return level;
}

void MassValue(int level)
{
	int contentDensity = 1040; //kg/m^3
	int tankDiameter = 4; //meters

	float contentValue = 3.14 * (tankDiameter) / 2 * (level / 1000);
	float contantMass = contentValue * contentDensity;
}

int main()
{
	MassValue(LevelInput());
}