#include "Storage_tank.h"
#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(my_test)
{
	BOOST_REQUIRE(ContentValue(1000) == 6);
}