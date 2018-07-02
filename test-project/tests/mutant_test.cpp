#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#include "mutant.h"
#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>

BOOST_AUTO_TEST_CASE(point_accessor_test) {
  BOOST_CHECK_EQUAL(decrement(5), -5);
}
