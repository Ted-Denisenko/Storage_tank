#include "StorageTank.h"

StorageTank::StorageTank()
{
	this->contentLevel = 0.0 * meters /** milli*/ / 1000.0;
	this->tankHeight = 0.0 * meters /** milli*/ / 1000.0;
	this->tankDiameter = 0.0 * meters/** milli*/ / 1000.0;
	this->tankRadius = 0.0 / 2.0 * meters;
}

StorageTank::StorageTank(double tankDiameter_raw, double tankHeight_raw, double contentLevel_raw, double contentDensity_raw)
{
	this->contentLevel = contentLevel_raw * meters /** milli*/ / 1000.0;
	this->tankHeight = tankHeight_raw * meters /** milli*/ / 1000.0;
	this->tankDiameter = tankDiameter_raw * meters/** milli*/ / 1000.0;
	this->tankRadius = tankDiameter / 2.0;
	this->contentDensity = contentDensity_raw * /*tons*/ kilogrammes / cubic_meters / 1000.0;
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

	this->contentDensity = contentDensity_raw * /*tons*/kilogrammes / cubic_meter;
	this->contentMass = contentVolume * this->contentDensity;

	return this->contentMass; //tons
};