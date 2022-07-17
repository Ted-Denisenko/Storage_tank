#include "Storage_tank.h"
#define BOOST_TEST_MODULE Storage_tank.UNIT_TESTS
#include <boost/test/unit_test.hpp>
namespace utf = boost::unit_test;


BOOST_AUTO_TEST_CASE(my_test, *utf::tolerance(0.00001))
{
	BOOST_CHECK_CLOSE(ContentValue(1000), 6.28000021, 0000001);
	BOOST_CHECK_CLOSE(ContentValue(1), 0.00628000032, 0000001);
	BOOST_CHECK_CLOSE(ContentMass(ContentValue(1000)), 6531.20020, 0000001);
	BOOST_CHECK_CLOSE(ContentMass(ContentValue(1)), 6.53120041, 0000001);
}