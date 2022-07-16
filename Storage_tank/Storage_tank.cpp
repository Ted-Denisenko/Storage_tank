#include <iostream>
#include <cassert>

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

void Tests()
{
	float valueExpected{-1};
	valueExpected = 6.28;
	assert(ContentValue(1000) == valueExpected && "Value test failed!");
	valueExpected = 50.24;
	assert(ContentValue(8000) == valueExpected && "Value test failed!");
	valueExpected = 0.00628000032;
	assert(ContentValue(1) == valueExpected && "Value test failed!");
	std::cout << "Value tests passed" << std::endl;

	float massExpected{ -1 };
	massExpected = 6531.20020;
	assert(ContentMass(ContentValue(1000)) == massExpected && "Mass test failed!");
	massExpected = 52249.6;
	assert(ContentMass(ContentValue(8000)) == massExpected && "Mass test failed!");
	massExpected = 6.5312003328;
	assert(ContentMass(ContentValue(1)) == massExpected && "Mass test failed!");
	std::cout << "Mass tests passed" << std::endl;
}

int main()
{
	Tests();
	ContentMass(ContentValue(LevelInput()));
	
}