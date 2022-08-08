#include "Storage_tank.h"

using namespace boost::units;
using namespace boost::units::si;

namespace outernamespace {
	namespace squared_millimeters_system {
		typedef boost::units::scaled_base_unit<boost::units::si::area, boost::units::scale<10, boost::units::static_rational<-6>>> millimeter_base_unit;

		typedef boost::units::make_system<millimeter_base_unit>::type system;
		typedef boost::units::unit<boost::units::length_dimension, system> length;

		BOOST_UNITS_STATIC_CONSTANT(squared_millimeter, length);
		BOOST_UNITS_STATIC_CONSTANT(squared_millimeters, length);
	}

	typedef boost::units::quantity<squared_millimeters_system::length> quantity_millimeter;
	using squared_millimeters_system::squared_millimeter;
	using squared_millimeters_system::squared_millimeters;
}

typedef make_scaled_unit<si::area, scale<10, static_rational<-6> > >::type squared_millimeters;

Volume ContentValue(std::string tankType, double contentLevel_raw, double tankHeight_raw, double tankDiameter_raw)
{	
	quantity<length> contentLevel(contentLevel_raw * milli * meters);
	quantity<length> tankHeight(tankHeight_raw * milli * meters);
	quantity<length> tankDiameter(tankDiameter_raw * milli * meters);
	Volume tankVolume;
	Volume contentVolume;

	if (tankType == "v")
	{

		tankVolume = (3.1415 * (tankDiameter * tankDiameter / 4.0) * tankHeight);
		contentVolume = (3.1415 * (tankDiameter * tankDiameter / 4.0) * contentLevel);
	}
	else if(tankType == "h")
	{	
		quantity<length> tankRadius = tankDiameter / 2.0;

		boost::units::quantity<
		boost::units::unit<
		boost::units::plane_angle_dimension,
		boost::units::degree::system
		>
		> sectorAngle(2 * acos((tankRadius - tankHeight) / tankRadius) * boost::units::degree::degree);


		boost::units::quantity<si::area> sectorSquare = ((sectorAngle.value() * (tankRadius.value() * tankRadius.value()) / 2.0)
			/** milli * milli*/ * square_meter);
		sectorSquare.from_value(sectorSquare.value() / 1000000);

		quantity<length> triangleBase(sqrt(
			(tankRadius.value() * tankRadius.value()) - 
			((tankRadius.value() - tankHeight.value()) * 
			(tankRadius.value() - tankHeight.value()))) * milli * meters);

		quantity<length> p((tankRadius + tankRadius + triangleBase) / 2.0);
		boost::units::quantity<squared_millimeters> triangleSquare = (sqrt
			(p.value() * 
			(p.value() - tankRadius.value()) * 
			(p.value() - tankRadius.value()) * 
			(p.value() - triangleBase.value()))
			* square_meters);
		contentVolume = (sectorSquare - triangleSquare) * tankHeight;
		// alpha = 2*acos((tankRadius-tankHeight)/tankRadius)
		// sector square = (alpha*(radius * radius)/2
		// triangle base = sqrt((radius * radius) - ((radius - tankHeight)*(radius - tankHeight)))
		// p = (radius+radius+base)/2
		// triangle square = sqrt(p * (p - radius) * (p - radius) * (p - base))
		// contentVolume = (sector_square - triangle_square) * tankHeight
		tankVolume = (3.1415 * (tankDiameter * tankDiameter / 4.0) * tankHeight);
		contentVolume = (3.1415 * (tankDiameter * tankDiameter / 4.0) * contentLevel);
	}
	//else
	//{
	//	todo: исключение о несоответсвии 
	//}

	if (contentLevel_raw > tankHeight_raw)
	{
		return (tankVolume);
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

void printVolume(Volume contentVolume)
{
	std::cout << "Content value is " << contentVolume.value() << std::endl;
}

void printMass(Mass contentMass)
{
	std::cout << "Content mass is " << contentMass.value() << std::endl;
}