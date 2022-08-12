#include "Storage_tank.h"
#define BOOST_TEST_MODULE Storage_tank.UNIT_TESTS
#include <boost/test/unit_test.hpp>

using namespace boost::units;
using namespace boost::units::si;


BOOST_AUTO_TEST_CASE(test_ContentValue_1000)
{
	double expected = 785375.0;
	double differ = 0.01;
	BOOST_CHECK_CLOSE(ContentVolume("v",1000, 1000, 1000).value(), expected, differ);
}

BOOST_AUTO_TEST_CASE(test_ContentValue_1)
{
	double expected = 0.785375;
	double differ = 0.01;
	BOOST_CHECK_CLOSE(ContentVolume("v", 1, 1, 1).value(), expected, differ);
}

BOOST_AUTO_TEST_CASE(test_ContentMass_1000)
{
	Volume check(1000.0 * cubic_meter);
	double expected = 1040;
	double differ = 0.01;
	BOOST_CHECK_CLOSE(float(ContentMass(check, 1040.0).value()), expected, differ);
}

BOOST_AUTO_TEST_CASE(test_ContentMass_1)
{
	Volume check(1.0 * cubic_meter);
	double expected = 1.04;
	double differ = 0.01;
	BOOST_CHECK_CLOSE(float(ContentMass(check, 1040.0).value()), expected, differ);
}