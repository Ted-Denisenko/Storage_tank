#include "Storage_tank.h"

using namespace boost::units;
using namespace boost::units::si;

//namespace extended_area_names {
//	namespace squared_millimeters_system 
//	{
//		// "area" is not a base unit
//		typedef make_scaled_unit<area, scale<10, static_rational<-6>>>::type millimeter_unit;	
//		typedef make_system<millimeter_unit>::type system;
//		typedef unit<area_dimension, system> area;
//			
//		BOOST_UNITS_STATIC_CONSTANT(squared_millimeter, area);
//		BOOST_UNITS_STATIC_CONSTANT(squared_millimeters, area);
//	} // namespace squared_millimeters_system
//
//	typedef quantity<squared_millimeters_system::area> quantity_area_square_millimeter;
//	using squared_millimeters_system::squared_millimeter;
//	using squared_millimeters_system::squared_millimeters;
//} // namespace extended_area_names

typedef make_scaled_unit<area, scale<10, static_rational<-6>>>::type millimeter_unit;

Volume ContentVolume(std::string tankType, double contentLevel_raw, double tankHeight_raw, double tankDiameter_raw)
{
	quantity<length> contentLevel(contentLevel_raw * milli * meters);
	quantity<length> tankHeight(tankHeight_raw * milli * meters);
	quantity<length> tankDiameter(tankDiameter_raw * milli * meters);
	quantity<length> tankRadius = tankDiameter / 2.0;
	Volume tankVolume(3.1415 * (tankRadius * tankRadius) * tankHeight);
	Volume contentVolume;

	if (contentLevel_raw > tankHeight_raw)
	{
		return (tankVolume);
	}
	else
	{
		if (tankType == "v")
		{
			contentVolume = (3.1415 * (tankRadius * tankRadius) * contentLevel);
			return contentVolume; //m^3
		}
		else if (tankType == "h")
		{
			//using namespace extended_area_names;

			quantity
				<unit<plane_angle_dimension,degree::system>
				> sectorAngle(2 * acos((tankRadius - tankHeight) / tankRadius)
				* degree::degree);

			quantity<millimeter_unit> sectorSquare(
				(sectorAngle.value() * (tankRadius.value() * tankRadius.value()) / 2.0)
				* square_meter);

			quantity<length> triangleBase(
				sqrt(
				(tankRadius.value() * tankRadius.value()) -
				((tankRadius.value() - tankHeight.value()) *
				(tankRadius.value() - tankHeight.value())))
				* milli * meters);

			quantity<length> p(
				(tankRadius + tankRadius + triangleBase) / 2.0);

			//quantity_area_square_millimeter mm((sectorAngle.value() * (tankRadius.value() * tankRadius.value()) / 2.0)
			//	* squared_millimeter);
			//quantity_area_square_millimeter bfg(sqrt
			//(p.value() *
			//	(p.value() - tankRadius.value()) *
			//	(p.value() - tankRadius.value()) *
			//	(p.value() - triangleBase.value()))
			//	* square_meters);
			//contentVolume = (mm-bfg)* tankHeight;

			quantity<millimeter_unit> triangleSquare(
				sqrt(
				 p.value() *
				(p.value() - tankRadius.value()) *
				(p.value() - tankRadius.value()) *
				(p.value() - triangleBase.value()))
				* square_meter);
			contentVolume = (sectorSquare - triangleSquare) * tankHeight;
			// alpha = 2*acos((tankRadius-tankHeight)/tankRadius)
			// sector square = (alpha*(radius * radius)/2
			// triangle base = sqrt((radius * radius) - ((radius - tankHeight)*(radius - tankHeight)))
			// p = (radius+radius+base)/2
			// triangle square = sqrt(p * (p - radius) * (p - radius) * (p - base))
			// contentVolume = (sector_square - triangle_square) * tankHeight

			return contentVolume; //m^2
		}
		//else
		//{
		//	todo: исключение о несоответсвии 
		//}
	}
}

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

Mass ContentMass(Volume contentVolume, double contentDensity_raw)
{
	using namespace extended_mass_names;
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








