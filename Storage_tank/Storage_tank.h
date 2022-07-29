#pragma once
#include <iostream>
#include <boost/units/systems/si/volume.hpp>
#include <boost/units/systems/si/mass.hpp>

//for Storage_tank.cpp
#include <boost/units/systems/si/io.hpp> //Storage_tank.cpp and UnitTests.cpp
#include <boost/units/systems/si/prefixes.hpp>


using Volume = boost::units::quantity<boost::units::si::volume>;
using Mass = boost::units::quantity<boost::units::si::mass>;


Volume ContentValue(int contentLevel_raw, int tankHeight_raw, int tankDiameter_raw);

Mass ContentMass(Volume contentVolume, double contentDensity_raw);

void printValue(double contentValue);

void printMass(double contentMass);