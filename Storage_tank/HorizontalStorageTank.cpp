#include "HorizontalStorageTank.h"

HorizontalStorageTank::HorizontalStorageTank(double tankDiameter_raw, double tankHeight_raw, double contentLevel_raw, double contentDensity_raw)
	:StorageTank(tankDiameter_raw, tankHeight_raw, contentLevel_raw, contentDensity_raw)
{
	this->tankRadius = tankDiameter / 2.0;
}

Volume HorizontalStorageTank::ContentVolume()
{
	if (this->contentLevel >= this->tankDiameter)
	{
		return (this->tankVolume);
	}
	
	if (this->contentLevel > this->tankRadius)
	{
		quantity<area> circleSquare(
			3.14159265359 * tankRadius * tankRadius); //mm sqaured

		quantity<plane_angle> sectorAngle(
			2.0 * boost::units::acos((this->tankRadius - (this->tankDiameter - this->contentLevel)) / this->tankRadius));

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

		this->contentVolume = (circleSquare - (sectorSquare - triangleSquare)) * this->tankHeight;
		return this->contentVolume;
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