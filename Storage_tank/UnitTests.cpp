#include "StorageTank.h"
#include "VerticalStorageTank.h"
#include "HorizontalStorageTank.h"

#define BOOST_TEST_MODULE Storage_tank.UNIT_TESTS
#include <boost/test/unit_test.hpp>

using namespace boost::units;
using namespace boost::units::si;

// TODO: адаптировать тесты под новый конструктор классов

VerticalStorageTank makeVerticalTank(int diam, int height, int level, int dens)
{
	quantity<length> tankDiameter(diam * milli * meters);
	quantity<length> tankHeight(height * milli * meters);
	quantity<length> contentLevel(level * milli * meters);
	quantity<mass_density> contentDensity(dens * kilogrammes_per_cubic_metre);
	VerticalStorageTank v(
		tankDiameter,
		tankHeight,
		contentLevel,
		contentDensity);

	return v;
}
HorizontalStorageTank makeHorizontalTank(int diam, int height, int level, int dens)
{
	quantity<length> tankDiameter(diam * milli * meters);
	quantity<length> tankHeight(height * milli * meters);
	quantity<length> contentLevel(level * milli * meters);
	quantity<mass_density> contentDensity(dens * kilogrammes_per_cubic_metre);
	HorizontalStorageTank h(
		tankDiameter,
		tankHeight,
		contentLevel,
		contentDensity);

	return h;
}

BOOST_AUTO_TEST_CASE(test_ContentValue_vertical_1000)
{
	auto v = makeVerticalTank(1000, 1000, 1000, 1040);
	double expected = 785398.163;
	double differ = 0.01;
	BOOST_CHECK_CLOSE(v.ContentVolume().value(), expected, differ);
}

BOOST_AUTO_TEST_CASE(test_ContentValue_vertical_1)
{
	auto v = makeVerticalTank(1, 1, 1, 1040);
	double expected = 0.785398163;
	double differ = 0.01;
	BOOST_CHECK_CLOSE(v.ContentVolume().value(), expected, differ);
}


BOOST_AUTO_TEST_CASE(test_ContentValue_horizontal_1000)
{
	auto h = makeHorizontalTank(1000, 1000, 1000, 1040);
	double expected = 785398.163;
	double differ = 0.01;
	BOOST_CHECK_CLOSE(h.ContentVolume().value(), expected, differ);
}

BOOST_AUTO_TEST_CASE(test_ContentValue_horizontal_1)
{
	auto h = makeHorizontalTank(1, 1, 1, 1040);
	double expected = 0.785398163;
	double differ = 0.01;
	BOOST_CHECK_CLOSE(h.ContentVolume().value(), expected, differ);
}




BOOST_AUTO_TEST_CASE(test_ContentMass_vertical_1000)
{
	auto v = makeVerticalTank(1000, 1000, 1000, 1040);
	double expected = 1040;
	double differ = 0.01;
	BOOST_CHECK_CLOSE(v.ContentMass().value(), expected, differ);
}

BOOST_AUTO_TEST_CASE(test_ContentMass_horizontal_1)
{
	auto v = makeVerticalTank(1, 1, 1, 1040);
	double expected = 1.04;
	double differ = 0.01;
	BOOST_CHECK_CLOSE(v.ContentMass().value(), expected, differ);
}

BOOST_AUTO_TEST_CASE(test_ContentMass_horizontal_1000)
{
	auto h = makeHorizontalTank(1000, 1000, 1000, 1040);
	double expected = 1040;
	double differ = 0.01;
	BOOST_CHECK_CLOSE(h.ContentMass().value(), expected, differ);
}

BOOST_AUTO_TEST_CASE(test_ContentMass_vertical_1)
{
	auto h = makeHorizontalTank(1, 1, 1, 1040);
	double expected = 1.04;
	double differ = 0.01;
	BOOST_CHECK_CLOSE(h.ContentMass().value(), expected, differ);
}