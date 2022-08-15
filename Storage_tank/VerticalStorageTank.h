#include "StorageTank.h"
#pragma once

class VerticalStorageTank : StorageTank
{
protected:
	Volume ContentVolume(double contentLevel_raw, double tankHeight_raw, double tankDiameter_raw);

public:
};
