#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#include "enum_example.h"
#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>

BOOST_AUTO_TEST_CASE(point_accessor_test) {
  BOOST_CHECK_EQUAL(enum_example(0), 3);
  BOOST_CHECK_EQUAL(enum_example(1), 4);
  BOOST_CHECK_EQUAL(enum_example(2), 7);
  BOOST_CHECK_EQUAL(enum_example(3), 1);
}
