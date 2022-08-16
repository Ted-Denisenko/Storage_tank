#pragma once
#include <iostream>
#include <boost/units/systems/si/volume.hpp>
#include <boost/units/systems/si/mass.hpp>
#include "string"

//for StorageTank.cpp
#include <boost/units/systems/si/io.hpp> //StorageTank.cpp and UnitTests.cpp
#include <boost/units/systems/si/prefixes.hpp>
#include <boost/units/systems/angle/degrees.hpp>
#include <boost/units/cmath.hpp>

using namespace boost::units;
using namespace boost::units::si;

namespace extended_mass_names
{
	namespace ton_system
	{
		using ton_base_unit = scaled_base_unit<kilogram_base_unit, scale<10, static_rational<-3> > >;
		typedef make_system<ton_base_unit>::type system;
		typedef unit<mass_dimension, system> mass;
		BOOST_UNITS_STATIC_CONSTANT(ton, mass);
		BOOST_UNITS_STATIC_CONSTANT(tons, mass);
	}
	using quantity_ton = quantity<ton_system::mass>;

	using ton_system::ton;
	using ton_system::tons;
}

using Volume = quantity<volume>;
using Mass = quantity<mass>;

class StorageTank
{
	double contentLevel_raw{ 0 };
	double tankHeight_raw{ 0 };
	double tankDiameter_raw{ 0 };
	double contentDensity_raw{ 0 };

protected:
	quantity<length> contentLevel;
	quantity<length> tankHeight;
	quantity<length> tankDiameter;
	quantity<length> tankRadius;
	Volume tankVolume;
	Volume contentVolume;
	quantity<mass_density> contentDensity;
	Mass contentMass;

public:
	StorageTank();
	StorageTank(double tankDiameter_raw, double tankHeight_raw, double contentLevel_raw, double contentDensity_raw);
	~StorageTank();

	double setContentLevel_raw(double contentLevel) { contentLevel_raw = contentLevel; }
	double setTankHeight_raw(double tankHeight) { tankHeight_raw = tankHeight; }
	double setTankDiameter_raw(double tankDiameter) { tankDiameter_raw = tankDiameter; }
	double setContentDensity_raw(double contentDensity) { contentDensity_raw = contentDensity; }

	quantity<length> setContentLevel(double contentLevel_raw) { contentLevel.from_value(contentLevel_raw); }

	const double getContentLevel_raw() { return contentLevel_raw; }
	const double getTankHeight_raw() { return tankHeight_raw; }
	const double getTankDiameter_raw() { return tankDiameter_raw; }
	const double getContentDensity_raw() { return contentDensity_raw; }
	const Volume getContentVolume() { return contentVolume; }
	const Mass getContentMass() { return contentMass; }

	virtual Volume ContentVolume();
	Mass ContentMass();

	void printVolume();
	void printMass();
};