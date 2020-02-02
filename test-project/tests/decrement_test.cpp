#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#include "decrement_example.hpp"
#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>

BOOST_AUTO_TEST_CASE(point_accessor_test) {
  BOOST_CHECK_EQUAL(decrement(5), -5);
  BOOST_CHECK_EQUAL(decrement(0), -10);
  BOOST_CHECK_EQUAL(decrement(10), 0);
}
