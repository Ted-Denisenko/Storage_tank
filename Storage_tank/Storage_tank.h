#pragma once
#include <iostream>
#include <boost/units/systems/si/volume.hpp>
#include <boost/units/systems/si/mass.hpp>

using Volume = boost::units::quantity<boost::units::si::volume>;
using Mass = boost::units::quantity<boost::units::si::mass>;


Volume ContentValue(int level, int tankHeight, int tankDiameter);

Mass ContentMass(double contentValue_raw, double contentDensity_raw);

void printValue(double contentValue);

void printMass(double contentMass);