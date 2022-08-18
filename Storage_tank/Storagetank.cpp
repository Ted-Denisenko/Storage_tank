#include "StorageTank.h"

using namespace boost::units;
using namespace boost::units::si;

StorageTank::StorageTank(double tankDiameter_raw, double tankHeight_raw, double contentLevel_raw, double contentDensity_raw)
	:tankDiameter(tankDiameter_raw* meters* milli),
	tankHeight(tankHeight_raw* meters* milli),
	contentLevel(contentLevel_raw* meters* milli),
	contentDensity(contentDensity_raw* extended_mass_names::tons / cubic_meter),
	tankRadius(tankDiameter / 2.0),
	tankVolume(boost::math::constants::pi<double>()* tankRadius * tankRadius * tankHeight)
{
}

Mass StorageTank::ContentMass()
{
	this->contentMass = contentVolume * this->contentDensity;
	return this->contentMass; //tons
};

// todo: избавиться от взаимодействия с пользователем
void StorageTank::printVolume()
{
	std::cout << this->contentVolume << std::endl;
}

void StorageTank::printMass()
{
	std::cout << this->contentMass << std::endl;
}