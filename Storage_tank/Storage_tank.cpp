#include "Storage_tank.h"
#include <boost/units/systems/si/io.hpp>

using namespace boost::units;
using namespace boost::units::si;

using Volume = quantity<volume>;

Volume ContentValue(int contentLevel_raw, int tankHeight_raw, int tankDiameter_raw)
{	
	quantity<length> contentLevel(contentLevel_raw * meters);
	quantity<length> tankHeight(tankHeight_raw * meters);
	quantity<length> tankDiameter(tankDiameter_raw * meters);

	Volume tankVolume(3.1415 * (tankDiameter * tankDiameter / 4.0) * tankHeight);
	Volume contentVolume(3.1415 * (tankDiameter * tankDiameter / 4.0) * contentLevel);

	if (contentLevel_raw > tankHeight_raw)
	{
		return tankVolume;
	}
	else
	{
		return contentVolume; //m^3
	}
}

namespace outernamespace
{
	namespace ton_system
	{
		using ton_base_unit = scaled_base_unit<kilogram_base_unit, scale<10, static_rational<3> > >;
		typedef make_system<ton_base_unit>::type system;
		typedef unit<mass_dimension, system> mass;
		BOOST_UNITS_STATIC_CONSTANT(ton, mass);
		BOOST_UNITS_STATIC_CONSTANT(tons, mass);
	}
	using quantity_ton = quantity<ton_system::mass>;

	using ton_system::ton;
	using ton_system::tons;
}

Mass ContentMass(Volume contentVolume, double contentDensity_raw)
{
	using namespace outernamespace;
	using MassDensity = quantity<mass_density>;
	using Mass = quantity<mass>;
	using Volume = quantity<volume>;
			
	const MassDensity massDensity(contentDensity_raw * ton / (metre * metre * metre));
	const Mass contentMass(contentVolume * massDensity);

	return contentMass; //tons
}

void printValue(double contentValue)
{
	std::cout << "Content value is " << contentValue << " m^3" << std::endl;
}

void printMass(double contentMass)
{
	std::cout << "Content mass is " << contentMass << " tons" << std::endl;
}