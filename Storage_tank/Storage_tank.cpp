#include "Storage_tank.h"


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

	// функции надо сделать абстрактными для использования в других классах
	virtual Volume ContentVolume(double contentLevel_raw, double tankHeight_raw, double tankDiameter_raw);
	Mass ContentMass(Volume contentVolume, double contentDensity_raw)
	{
		using namespace extended_mass_names;

		contentDensity = contentDensity_raw * ton / cubic_meter;
		contentMass = contentVolume * contentDensity;

		return contentMass; //tons
	};

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

	StorageTank(double contentLevel_raw, double tankHeight_raw, double tankDiameter_raw)
	{
		// TODO: найти способ избавиться от "/ 1000.0" в пользу "* milli"

		contentLevel = contentLevel_raw * meters / 1000.0;
		tankHeight = tankHeight_raw  * meters / 1000.0;
		tankDiameter = tankDiameter_raw  * meters / 1000.0;
		tankRadius = tankDiameter / 2.0;

		tankVolume = 3.1415 * (tankRadius * tankRadius) * tankHeight;
	};

	~StorageTank() {}

	void printVolume()
	{
		std::cout << "Content volume is " << this->getContentVolume().value() << std::endl;
	}

	void printMass()
	{
		std::cout << "Content mass is " << this->getContentMass().value() << std::endl;
	}
};

class VerticalStorageTank : StorageTank
{
protected:
	Volume ContentVolume(double contentLevel_raw, double tankHeight_raw, double tankDiameter_raw)
	{
		if (contentLevel_raw >= tankHeight_raw)
		{
			return (tankVolume);
		}
		contentVolume = (3.1415 * tankRadius * tankRadius * contentLevel);
		return contentVolume; //m^3
	};

public:
	VerticalStorageTank();
	~VerticalStorageTank();
};

class HorizontalStorageTank : StorageTank
{
protected:
	Volume ContentVolume(double contentLevel_raw, double tankHeight_raw, double tankDiameter_raw)
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
	};

public:
	HorizontalStorageTank();
	~HorizontalStorageTank();
};

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