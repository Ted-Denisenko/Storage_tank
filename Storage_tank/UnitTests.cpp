#include "Storage_tank.h"
#define BOOST_TEST_MODULE Storage_tank.UNIT_TESTS
#include <boost/test/unit_test.hpp>
#include <boost/units/systems/si/io.hpp>
#include <boost/units/systems/si/mass.hpp>
#include <boost/units/systems/si/base.hpp>
#include <boost/units/systems/si/mass_density.hpp>
#include <boost/units/base_units/si/kilogram.hpp>
namespace utf = boost::unit_test;

using Volume = boost::units::quantity<boost::units::si::volume>;
	

//BOOST_AUTO_TEST_CASE(test_ContentValue_1000)
//{
//	BOOST_CHECK_CLOSE(ContentValue(1000), 6.28000021, 0000001);
//}
//
//BOOST_AUTO_TEST_CASE(test_ContentValue_1)
//{
//	BOOST_CHECK_CLOSE(ContentValue(1), 0.00628000032, 0000001);
//}

//BOOST_AUTO_TEST_CASE(test_ContentMass_1000)
//{
//	BOOST_CHECK_CLOSE(ContentMass(ContentValue(1000)), 6531.20020, 0000001);
//}

	namespace outernamespace
	{
		namespace ton_system
		{
			using ton_base_unit = boost::units::scaled_base_unit<boost::units::si::kilogram_base_unit, boost::units::scale<10, boost::units::static_rational<3> > >;
			typedef boost::units::make_system<ton_base_unit>::type system;
			typedef boost::units::unit<boost::units::mass_dimension, boost::units::si::system> mass;
			BOOST_UNITS_STATIC_CONSTANT(ton, mass);
			BOOST_UNITS_STATIC_CONSTANT(tons, mass);
		}
		using quantity_ton = boost::units::quantity<ton_system::mass>;

		using ton_system::ton;
		using ton_system::tons;
	}

	BOOST_AUTO_TEST_CASE(test_ContentMass_1)
	{
		//using outernamespace;
		Volume check(50.0 * boost::units::si::cubic_meter);
		Mass expected(52.0 * boost::units::si::kilogram);
		Mass differ(0.1 * boost::units::si::kilogram);
	//	BOOST_CHECK_CLOSE(ContentMass(check, 1040.0), expected, differ);
	}