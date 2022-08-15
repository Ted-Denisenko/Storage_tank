#include "HorizontalStorageTank.h"

Volume HorizontalStorageTank::ContentVolume(double contentLevel_raw, double tankHeight_raw, double tankDiameter_raw)
{
	if (contentLevel_raw >= tankDiameter_raw)
	{
		return (tankVolume);
	}

	quantity<plane_angle> sectorAngle(
		2.0 * boost::units::acos((tankRadius - contentLevel) / tankRadius));

	quantity<area> sectorSquare(
		(sectorAngle.value() * tankRadius * tankRadius) / 2.0); //mm sqaured

	quantity<length> triangleBase(
		2.0 * boost::units::sqrt(
			(tankRadius * tankRadius) -
			((tankRadius - contentLevel) *
				(tankRadius - contentLevel)))); //

	quantity<length> p(
		(tankRadius + tankRadius + triangleBase) / 2.0);

	quantity<area> triangleSquare(
		boost::units::sqrt(
			p *
			(p - tankRadius) *
			(p - tankRadius) *
			(p - triangleBase)));

	contentVolume = (sectorSquare - triangleSquare) * tankHeight;

	return contentVolume; //m^3
};