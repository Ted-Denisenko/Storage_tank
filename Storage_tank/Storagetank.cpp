#include "StorageTank.h"

StorageTank::StorageTank()
	:tankDiameter(1.0 * meters* milli),
	tankHeight(0.0 * meters* milli),
	contentLevel(0.0 * meters* milli),
	contentDensity(0.0 * extended_mass_names::tons / cubic_meter)
{
}

StorageTank::StorageTank(double tankDiameter_raw, double tankHeight_raw, double contentLevel_raw, double contentDensity_raw)
	:tankDiameter(tankHeight_raw* meters* milli),
	tankHeight(tankHeight_raw * meters * milli),
	contentLevel(tankHeight_raw* meters* milli),
	contentDensity(contentDensity_raw * extended_mass_names::tons / cubic_meter)
{
	this->tankDiameter.from_value(tankDiameter_raw);
	this->tankHeight.from_value(tankHeight_raw);
	this->contentLevel.from_value(contentLevel_raw);
	this->contentDensity.from_value(contentDensity_raw);
	this->tankRadius = tankDiameter / 2.0;
}

StorageTank::~StorageTank()
{
	this->contentLevel.from_value(0.0);
	this->tankHeight.from_value(0.0);
	this->tankDiameter.from_value(0.0);
	this->tankRadius.from_value(0.0);
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
	using namespace extended_mass_names;

	// TODO: найти способ избавиться от "/ 1000.0" в пользу "* milli"

	this->contentDensity = contentDensity_raw * /*tons*/kilogrammes / 1000.0 / cubic_meter;
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