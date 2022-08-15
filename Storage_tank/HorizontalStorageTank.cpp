#include "HorizontalStorageTank.h"

//HorizontalStorageTank::HorizontalStorageTank(double contentLevel_raw, double tankHeight_raw, double tankDiameter_raw)
//{
//	contentLevel = contentLevel_raw * meters /** milli*/ / 1000.0;
//	tankHeight = tankHeight_raw * meters /** milli*/ / 1000.0;
//	tankDiameter = tankDiameter_raw * meters/** milli*/ / 1000.0;
//	tankRadius = tankDiameter / 2.0;
//}
//
//HorizontalStorageTank::~HorizontalStorageTank()
//{
//	contentLevel.from_value(0.0);
//	tankHeight.from_value(0.0);
//	tankDiameter.from_value(0.0);
//	tankRadius.from_value(0.0);
//}

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