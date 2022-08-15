#include "VerticalStorageTank.h"

//VerticalStorageTank::VerticalStorageTank(double contentLevel_raw, double tankHeight_raw, double tankDiameter_raw)
//{
//	contentLevel = contentLevel_raw * meters /** milli*/ / 1000.0;
//	tankHeight = tankHeight_raw * meters /** milli*/ / 1000.0;
//	tankDiameter = tankDiameter_raw * meters/** milli*/ / 1000.0;
//	tankRadius = tankDiameter / 2.0;
//}
//
//VerticalStorageTank::~VerticalStorageTank()
//{
//	contentLevel.from_value(0.0);
//	tankHeight.from_value(0.0);
//	tankDiameter.from_value(0.0);
//	tankRadius.from_value(0.0);
//}

Volume VerticalStorageTank::ContentVolume(double contentLevel_raw, double tankHeight_raw, double tankDiameter_raw)
{
	if (contentLevel_raw >= tankHeight_raw)
	{
		return (tankVolume);
	}
	contentVolume = (3.1415 * tankRadius * tankRadius * contentLevel);
	return contentVolume; //m^3
}