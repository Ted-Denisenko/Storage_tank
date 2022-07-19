#pragma once
#include <iostream>
#include <boost/units/systems/si/volume.hpp>

typedef boost::units::quantity<boost::units::si::volume> Volume;
typedef boost::units::quantity<boost::units::si::mass> Mass;


Volume ContentValue(int level, int tankHeight, int tankDiameter);

Mass ContentMass(double contentValue_raw, double contentDensity_raw);

void printValue(double contentValue);

void printMass(double contentMass);