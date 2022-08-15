#include "HorizontalStorageTank.h"

HorizontalStorageTank::HorizontalStorageTank(double tankDiameter_raw, double tankHeight_raw, double contentLevel_raw, double contentDensity_raw)
{
	using namespace extended_mass_names;

	this->contentLevel = this->getContentLevel_raw() * meters /** milli*/ / 1000.0;
	this->tankHeight = this->getTankHeight_raw() * meters /** milli*/ / 1000.0;
	this->tankDiameter = this->getTankDiameter_raw() * meters/** milli*/ / 1000.0;
	this->tankRadius = this->tankDiameter / 2.0;
	this->contentDensity = this->getContentDensity_raw() * /*tons*/ kilogrammes / cubic_meters / 1000.0;
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