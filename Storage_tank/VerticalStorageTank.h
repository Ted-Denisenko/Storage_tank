#include "StorageTank.h"
#pragma once

class VerticalStorageTank : public StorageTank
{
	//void friend printVolume(VerticalStorageTank& v);
	//void friend printMass(VerticalStorageTank& v);
public:
	VerticalStorageTank(double tankDiameter_raw, double tankHeight_raw, double contentLevel_raw, double contentDensity_raw);
	Volume ContentVolume();
	Mass ContentMass();

	//void printVolume();
	//void printMass();
};
