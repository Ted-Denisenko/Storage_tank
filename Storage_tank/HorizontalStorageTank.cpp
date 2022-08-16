#include "HorizontalStorageTank.h"

HorizontalStorageTank::HorizontalStorageTank(double tankDiameter_raw, double tankHeight_raw, double contentLevel_raw, double contentDensity_raw)
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

Volume HorizontalStorageTank::ContentVolume()
{
	if (this->getContentLevel_raw() >= this->getTankDiameter_raw())
	{
		return (this->tankVolume);
	}

	quantity<plane_angle> sectorAngle(
		2.0 * boost::units::acos((this->tankRadius - this->contentLevel) / this->tankRadius));

	quantity<area> sectorSquare(
		(sectorAngle.value() * this->tankRadius * this->tankRadius) / 2.0); //mm sqaured

	quantity<length> triangleBase(
		2.0 * boost::units::sqrt(
			(this->tankRadius * this->tankRadius) -
			((this->tankRadius - this->contentLevel) *
				(this->tankRadius - this->contentLevel))));

	quantity<length> p(
		(this->tankRadius + this->tankRadius + triangleBase) / 2.0);

	quantity<area> triangleSquare(
		boost::units::sqrt(
			p *
			(p - this->tankRadius) *
			(p - this->tankRadius) *
			(p - triangleBase)));

	this->contentVolume = (sectorSquare - triangleSquare) * this->tankHeight;

	return this->contentVolume; //m^3
};

Mass HorizontalStorageTank::ContentMass()
{
	this->contentMass = StorageTank::ContentMass();
	return this->contentMass;
}

void HorizontalStorageTank::printVolume()
{
	StorageTank::printVolume();
}

void HorizontalStorageTank::printMass()
{
	StorageTank::printMass();
}