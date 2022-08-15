#include "VerticalStorageTank.h"

Volume VerticalStorageTank::ContentVolume(double contentLevel_raw, double tankHeight_raw, double tankDiameter_raw)
{
	if (contentLevel_raw >= tankHeight_raw)
	{
		return (tankVolume);
	}
	contentVolume = (3.1415 * tankRadius * tankRadius * contentLevel);
	return contentVolume; //m^3
}