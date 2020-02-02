#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#include "void_example.hpp"
#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>

BOOST_AUTO_TEST_CASE(point_accessor_test) {
    int x = 115;
    void_example(x);
    BOOST_CHECK_EQUAL(x, 100);
    x = 20;
    void_example(x);
    BOOST_CHECK_EQUAL(x, 400);
    /*x = -20;
    void_example(x);
    BOOST_CHECK_EQUAL(x, 0);*/
}
