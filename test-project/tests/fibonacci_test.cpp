#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#include "fibonacci.cpp"
#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>

BOOST_AUTO_TEST_CASE(point_accessor_test) {
    BOOST_CHECK_EQUAL(fibonacci(0), 0);
    BOOST_CHECK_EQUAL(fibonacci(1), 1);
    BOOST_CHECK_EQUAL(fibonacci(2), 1);
    BOOST_CHECK_EQUAL(fibonacci(5), 5);
}
