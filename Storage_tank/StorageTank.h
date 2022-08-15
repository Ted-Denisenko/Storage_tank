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
	double contentLevel_raw;
	double tankHeight_raw;
	double tankDiameter_raw;
	double contentDensity_raw;

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

// геттеры и сеттеры: для каких данных нужно использовать?
// если использовать для сырых значений, то при вызове консутруктора класса будет нужно задавать данные через сеттеры
// затем эти данные через конструктор помогут в инициализации буст значений
// сеттеры для сырых значений имеют смысл
// геттеры позволят узнать, какие значения были переданы в конструктор без привязки к единицам измерения (они известны заранее - мм)
// хотя такой функционал будет нужен только разработчику
// если использовать сеттеры для значений буста, то смысла в инициализации данных через конструктор я не вижу
// геттеры имеют право на жизнь, если необходимо проверить, правильно ли инициализировались значения
// но пользователь не будет делать таких проверок, они нужны разработчику

	double setContentLevel_raw(double contentLevel) { contentLevel_raw = contentLevel; }
	double setTankHeight_raw(double tankHeight) { tankHeight_raw = tankHeight; }
	double setTankDiameter_raw(double tankDiameter) { tankDiameter_raw = tankDiameter; }
	double setContentDensity(double contentDensity) { contentDensity_raw = contentDensity; }

	const double getContentLevel_raw() { return contentLevel_raw; }
	const double getTankHeight_raw() { return tankHeight_raw; }
	const double getTankDiameter_raw() { return tankDiameter_raw; }
	const double getContentDensity() { return contentDensity_raw; }
	const Volume getContentVolume() { return contentVolume; }
	const Mass getContentMass() { return contentMass; }

	virtual Volume ContentVolume(double contentLevel_raw, double tankHeight_raw, double tankDiameter_raw);
	Mass ContentMass(Volume contentVolume, double contentDensity_raw);

	StorageTank(double contentLevel_raw, double tankHeight_raw, double tankDiameter_raw);

	~StorageTank();

	void printVolume();

	void printMass();
};

//Volume ContentVolume(std::string tankType, double contentLevel_raw, double tankHeight_raw, double tankDiameter_raw);
//
//Mass ContentMass(Volume contentVolume, double contentDensity_raw);
//
//void printVolume(Volume contentVolume);
//
//void printMass(Mass contentMass);