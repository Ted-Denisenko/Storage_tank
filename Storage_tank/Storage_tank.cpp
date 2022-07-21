#include "Storage_tank.h"

#include <boost/units/systems/si/length.hpp>
#include <boost/units/systems/si/mass.hpp>
#include <boost/units/systems/si/base.hpp>
#include <boost/units/systems/si/mass_density.hpp>
#include <boost/units/systems/si/io.hpp>
#include <boost/units/base_units/si/kilogram.hpp>
#include <boost/units/static_constant.hpp>
#include <boost/units/systems/si/prefixes.hpp>
#include <boost/units/unit.hpp>
#include <boost/units/scale.hpp>
#include <boost/units/scaled_base_unit.hpp>




using ton_base_unit = scaled_base_unit<boost::units::si::kilogram_base_unit, scale<10, static_rational<3> > >;

using Volume = boost::units::quantity<boost::units::si::volume>;

Volume ContentValue(int contentLevel, int tankHeight, int tankDiameter)
{	
	using boost::units::si::kilogrammes_per_cubic_metre;

	double tankValue_raw = ((3.1415 * (tankDiameter / 2 * tankDiameter / 2) * tankHeight) / float(1000000000));
	double contentValue_raw = ((3.1415 * (tankDiameter / 2 * tankDiameter / 2) * contentLevel) / float(1000000000));

	Volume tankVolume(tankValue_raw * boost::units::si::cubic_meter);
	Volume contentVolume(contentValue_raw * boost::units::si::cubic_meter);

	if (contentLevel > tankHeight)
	{
		return tankVolume;
	}
	else
	{
		return contentVolume; //m^3
	}
}

Mass ContentMass(double contentValue_raw, double contentDensity_raw)
{
	/*
	typedef void(*func_pointer)(int);
	vs
	using func_pointer = void(*)(int);
	*/

	using MassDensity = boost::units::quantity<boost::units::si::mass_density>;;

	const MassDensity mass_density(contentDensity_raw * boost::units::si::kilogrammes_per_cubic_metre);
	const Volume volume(contentValue_raw * boost::units::si::cubic_meter);
	const Mass contentMass(volume * mass_density);

	return (contentMass/1000); //tons
}

void printValue(double contentValue)
{
	std::cout << "Content value is " << contentValue << " m^3" << std::endl;
}

void printMass(double contentMass)
{
	std::cout << "Content mass is " << contentMass << " tons" << std::endl;
}