#include "StorageTank.h"

using namespace boost::units;
using namespace boost::units::si;

StorageTank::StorageTank(boost::units::quantity<boost::units::si::length> param_tankDiameter,
	boost::units::quantity<boost::units::si::length> param_tankHeight,
	boost::units::quantity<boost::units::si::length> param_contentLevel,
	boost::units::quantity<boost::units::si::mass_density> param_contentDensity)
	:tankDiameter(param_tankDiameter),
	tankHeight(param_tankHeight),
	contentLevel(param_contentLevel),
	contentDensity(param_contentDensity),
	tankRadius(tankDiameter / 2.0),
	tankVolume(boost::math::constants::pi<double>()* tankRadius * tankRadius * tankHeight)
{
}

Mass StorageTank::ContentMass()
{
	this->contentMass = contentVolume * this->contentDensity;
	return this->contentMass; //tons
};

void StorageTank::setLevel(int newLevel)
{
	quantity<length> temp(newLevel * milli * meters);
	this->contentLevel = temp;
}