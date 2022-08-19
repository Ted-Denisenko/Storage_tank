#pragma once
#include <iostream>
#include <boost/units/systems/si/volume.hpp>
#include <boost/units/systems/si/mass.hpp>
#include "string"

//for StorageTank.cpp
#include <boost/units/systems/si/io.hpp> //StorageTank.cpp and UnitTests.cpp
#include <boost/units/systems/si/prefixes.hpp>
#include <boost/units/systems/angle/degrees.hpp>
#include <boost/math/constants/constants.hpp>
#include <boost/units/cmath.hpp>

namespace extended_mass_names
{
	namespace ton_system
	{
		using ton_base_unit = boost::units::scaled_base_unit<boost::units::si::kilogram_base_unit, boost::units::scale<10, boost::units::static_rational<-3> > >;
		typedef boost::units::make_system<ton_base_unit>::type system;
		typedef boost::units::unit<boost::units::mass_dimension, system> mass;
		BOOST_UNITS_STATIC_CONSTANT(ton, mass);
		BOOST_UNITS_STATIC_CONSTANT(tons, mass);
	}
	using quantity_ton = boost::units::quantity<ton_system::mass>;

	using ton_system::ton;
	using ton_system::tons;
}

using Volume = boost::units::quantity<boost::units::si::volume>;
using Mass = boost::units::quantity<boost::units::si::mass>;

class StorageTank
{

protected:
	boost::units::quantity<boost::units::si::length> contentLevel;
	boost::units::quantity<boost::units::si::length> tankHeight;
	boost::units::quantity<boost::units::si::length> tankDiameter;
	boost::units::quantity<boost::units::si::length> tankRadius;
	Volume tankVolume;
	Volume contentVolume;
	boost::units::quantity<boost::units::si::mass_density> contentDensity;
	Mass contentMass;

public:
	StorageTank();
	StorageTank(double tankDiameter_raw, double tankHeight_raw, double contentLevel_raw, double contentDensity_raw);
	~StorageTank() {};


	virtual Volume ContentVolume() = 0;
	Mass ContentMass();

	void setLevel(double newLevel);

	void printVolume();
	void printMass();
};