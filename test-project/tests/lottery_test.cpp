#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#include "lottery_example.cpp"
#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>

BOOST_AUTO_TEST_CASE(point_accessor_test) {
    BOOST_CHECK_EQUAL(lottery_example(0, 12, 21, 23, 55), 0);
    BOOST_CHECK_EQUAL(lottery_example(13, 13, 13, 13, 13), 1);
    BOOST_CHECK_EQUAL(lottery_example(5, 13, 22, 28, 39), 5);
}
