#include "VerticalStorageTank.h"

Volume VerticalStorageTank::ContentVolume()
{
	if (this->getContentLevel_raw() >= this->getTankHeight_raw())
	{
		return (this->tankVolume);
	}
	this->contentVolume = (3.1415 * this->tankRadius * this->tankRadius * this->contentLevel);
	return this->contentVolume; //m^3
}