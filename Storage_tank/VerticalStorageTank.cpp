#include "VerticalStorageTank.h"

using namespace boost::units;
using namespace boost::units::si;

VerticalStorageTank::VerticalStorageTank(boost::units::quantity<boost::units::si::length> param_tankDiameter,
	boost::units::quantity<boost::units::si::length> param_tankHeight,
	boost::units::quantity<boost::units::si::length> param_contentLevel,
	boost::units::quantity<boost::units::si::mass_density> param_contentDensity)
	:StorageTank(param_tankDiameter, param_tankHeight, param_contentLevel, param_contentDensity)
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