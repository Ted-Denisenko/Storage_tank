#include "StorageTank.h"

using namespace boost::units;
using namespace boost::units::si;

StorageTank::StorageTank()
	:tankDiameter(0.0 * meters* milli),
	tankHeight(0.0 * meters* milli),
	contentLevel(0.0 * meters* milli),
	contentDensity(0.0 * extended_mass_names::tons / cubic_meter)
{
}

StorageTank::StorageTank(double tankDiameter_raw, double tankHeight_raw, double contentLevel_raw, double contentDensity_raw)
	:tankDiameter(tankDiameter_raw* meters* milli),
	tankHeight(tankHeight_raw* meters* milli),
	contentLevel(contentLevel_raw* meters* milli),
	contentDensity(contentDensity_raw* extended_mass_names::tons / cubic_meter),
	tankRadius(tankDiameter / 2.0),
	tankVolume(3.14159265359 * tankRadius * tankRadius * tankHeight)
{
}

StorageTank::~StorageTank()
{
}

Volume StorageTank::ContentVolume()
{
	if (this->getContentLevel_raw() >= this->getTankHeight_raw())
	{
		return (this->tankVolume);
	}
	this->contentVolume = (3.1415 * this->tankRadius * this->tankRadius * this->contentLevel);
	return this->contentVolume; //m^3
};

Mass StorageTank::ContentMass()
{
	this->contentMass = contentVolume * this->contentDensity;
	return this->contentMass; //tons
};

void StorageTank::printVolume()
{
	std::cout << this->contentVolume << std::endl;
}

void StorageTank::printMass()
{
	std::cout << this->contentMass << std::endl;
}