#include "StorageTank.h"
#include "VerticalStorageTank.h"
#include "HorizontalStorageTank.h"

#define BOOST_TEST_MODULE Storage_tank.UNIT_TESTS
#include <boost/test/unit_test.hpp>

using namespace boost::units;
using namespace boost::units::si;


BOOST_AUTO_TEST_CASE(test_ContentValue_vertical_1000)
{
	double expected = 785398.163;
	double differ = 0.01;
	VerticalStorageTank v(1000.0, 1000.0, 1000.0, 1040.0);
	BOOST_CHECK_CLOSE(v.ContentVolume(), expected, differ);
}

BOOST_AUTO_TEST_CASE(test_ContentValue_vertical_1)
{
	double expected = 0.785398163;
	double differ = 0.01;
	VerticalStorageTank v(1.0, 1.0, 1.0, 1040.0);
	BOOST_CHECK_CLOSE(v.ContentVolume(), expected, differ);
}


BOOST_AUTO_TEST_CASE(test_ContentValue_horizontal_1000)
{
	double expected = 785398.163;
	double differ = 0.01;
	HorizontalStorageTank h(1000.0, 1000.0, 1000.0, 1040.0);
	BOOST_CHECK_CLOSE(h.ContentVolume(), expected, differ);
}

BOOST_AUTO_TEST_CASE(test_ContentValue_horizontal_1)
{
	double expected = 0.785398163;
	double differ = 0.01;
	HorizontalStorageTank h(1.0, 1.0, 1.0, 1040.0);
	BOOST_CHECK_CLOSE(h.ContentVolume(), expected, differ);
}




BOOST_AUTO_TEST_CASE(test_ContentMass_vertical_1000)
{
	double expected = 1040;
	double differ = 0.01;
	VerticalStorageTank v(1000.0, 1000.0, 1000.0, 1040.0);
	BOOST_CHECK_CLOSE(v.ContentMass(), expected, differ);
}

BOOST_AUTO_TEST_CASE(test_ContentMass_horizontal_1)
{
	double expected = 1.04;
	double differ = 0.01;
	VerticalStorageTank v(1.0, 1.0, 1.0, 1040.0);
	BOOST_CHECK_CLOSE(v.ContentMass(), expected, differ);
}

BOOST_AUTO_TEST_CASE(test_ContentMass_horizontal_1000)
{
	double expected = 1040;
	double differ = 0.01;
	HorizontalStorageTank h(1000.0, 1000.0, 1000.0, 1040.0);
	BOOST_CHECK_CLOSE(h.ContentMass(), expected, differ);
}

BOOST_AUTO_TEST_CASE(test_ContentMass_vertical_1)
{
	double expected = 1.04;
	double differ = 0.01;
	HorizontalStorageTank h(1.0, 1.0, 1.0, 1040.0);
	BOOST_CHECK_CLOSE(h.ContentMass(), expected, differ);
}