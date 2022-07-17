#include "Storage_tank.h"
#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(my_test)
{
	BOOST_REQUIRE(ContentValue(1000) == 6.28000021);
	BOOST_REQUIRE(ContentValue(8000) == 50.2400017);
	BOOST_REQUIRE(ContentValue(1) == 0.00628000032);
	BOOST_REQUIRE(ContentMass(ContentValue(1000)) == 6531.20020);
	BOOST_REQUIRE(ContentMass(ContentValue(8000)) == 52249.6016);
	BOOST_REQUIRE(ContentMass(ContentValue(1)) == 6.53120041);
}