#pragma once
#include <iostream>
#include <boost/units/systems/si/volume.hpp>
#include <boost/units/systems/si/mass.hpp>
#include "string"

//for Storage_tank.cpp
#include <boost/units/systems/si/io.hpp> //Storage_tank.cpp and UnitTests.cpp
#include <boost/units/systems/si/prefixes.hpp>
#include <boost/units/systems/angle/degrees.hpp>
#include <boost/units/cmath.hpp>

using namespace boost::units;
using namespace boost::units::si;

using Volume = quantity<volume>;
using Mass = quantity<mass>;

Volume ContentVolume(std::string tankType, double contentLevel_raw, double tankHeight_raw, double tankDiameter_raw);

Mass ContentMass(Volume contentVolume, double contentDensity_raw);

void printVolume(Volume contentVolume);

void printMass(Mass contentMass);