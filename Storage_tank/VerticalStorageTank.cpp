#include "VerticalStorageTank.h"

using namespace boost::units;
using namespace boost::units::si;

VerticalStorageTank::VerticalStorageTank(double tankDiameter_raw, double tankHeight_raw, double contentLevel_raw, double contentDensity_raw)
	:StorageTank(tankDiameter_raw, tankHeight_raw, contentLevel_raw, contentDensity_raw)
{
	this->tankRadius = tankDiameter / 2.0;
}

Volume VerticalStorageTank::ContentVolume()
{
	if (this->contentLevel >= this->tankDiameter)
	{
		return (this->tankVolume);
	}
	this->contentVolume = (boost::math::constants::pi<double>() * this->tankRadius * this->tankRadius * this->contentLevel);
	return this->contentVolume; //m^3
}

Mass VerticalStorageTank::ContentMass()
{
	this->contentMass = StorageTank::ContentMass();
	return this->contentMass;
}

void VerticalStorageTank::printVolume()
{
	StorageTank::printVolume();
}

void VerticalStorageTank::printMass()
{
	StorageTank::printMass();
}