#include "Storage_tank.h"


Volume ContentVolume(std::string tankType, double contentLevel_raw, double tankHeight_raw, double tankDiameter_raw)
{
	quantity<length> contentLevel(contentLevel_raw * milli * meters);
	quantity<length> tankHeight(tankHeight_raw * milli * meters);
	quantity<length> tankDiameter(tankDiameter_raw * milli * meters);
	quantity<length> tankRadius = tankDiameter / 2.0;
	Volume tankVolume(3.1415 * (tankRadius * tankRadius) * tankHeight);
	Volume contentVolume;



	if (tankType == "v")
	{
		if (contentLevel_raw >= tankHeight_raw)
		{
			return (tankVolume);
		}
		contentVolume = (3.1415 * tankRadius * tankRadius * contentLevel);
		return contentVolume; //m^3
	}
	else if (tankType == "h")
	{
		if (contentLevel_raw >= tankDiameter_raw)
		{
			return (tankVolume);
		}

		quantity<plane_angle> sectorAngle(
			2.0 * boost::units::acos((tankRadius - contentLevel) / tankRadius));

		quantity<area> sectorSquare(
			(sectorAngle.value() * tankRadius * tankRadius) / 2.0); //mm sqaured

		quantity<length> triangleBase(
			2.0 * boost::units::sqrt(
				(tankRadius * tankRadius) -
				((tankRadius - contentLevel) *
					(tankRadius - contentLevel)))); //

		quantity<length> p(
			(tankRadius + tankRadius + triangleBase) / 2.0);

		quantity<area> triangleSquare(
			boost::units::sqrt(
				p *
				(p - tankRadius) *
				(p - tankRadius) *
				(p - triangleBase)));

		contentVolume = (sectorSquare - triangleSquare) * tankHeight;

		return contentVolume; //m^3
	}
	else
	{
		throw std::exception("Invalid tank type. Only 'v' and 'h' accepted. ");
		return contentVolume;
	}

	return contentVolume;
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

	const MassDensity massDensity(contentDensity_raw * ton / cubic_meter);
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