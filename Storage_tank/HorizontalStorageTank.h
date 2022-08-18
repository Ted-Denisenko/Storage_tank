#include "StorageTank.h"
#pragma once
class HorizontalStorageTank : public StorageTank
{
public:
	HorizontalStorageTank(double tankDiameter_raw, double tankHeight_raw, double contentLevel_raw, double contentDensity_raw);
	Volume ContentVolume();
	Mass ContentMass();

	void printVolume();
	void printMass();
};

