#include "VerticalStorageTank.h"

VerticalStorageTank::VerticalStorageTank(double tankDiameter_raw, double tankHeight_raw, double contentLevel_raw, double contentDensity_raw)
{
	// при попытке задать значение через функцию from_value(), 
	// ожидаетс€, что параметр val пол€ tankDiameter будет tankDiameter_raw / 1000 (метров)
	// на деле же значение не мен€етс€
	// задать значение в мм через операцию присвоени€ невозможно из-за ошибки компил€ции
	this->tankDiameter.from_value(tankDiameter_raw);
	this->tankHeight.from_value(tankHeight_raw);
	this->contentLevel.from_value(contentLevel_raw);
	this->contentDensity.from_value(contentDensity_raw);
	this->tankRadius = tankDiameter / 2.0;
}

Volume VerticalStorageTank::ContentVolume()
{
	if (this->getContentLevel_raw() >= this->getTankHeight_raw())
	{
		return (this->tankVolume);
	}
	this->contentVolume = (3.1415 * this->tankRadius * this->tankRadius * this->contentLevel);
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