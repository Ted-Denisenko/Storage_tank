#include "StorageTank.h"
#pragma once

class VerticalStorageTank : public StorageTank
{
public:
	VerticalStorageTank(boost::units::quantity<boost::units::si::length> param_tankDiameter,
		boost::units::quantity<boost::units::si::length> param_tankHeight,
		boost::units::quantity<boost::units::si::length> param_contentLevel,
		boost::units::quantity<boost::units::si::mass_density> param_contentDensity);
	Volume ContentVolume();
	Mass ContentMass();
};
