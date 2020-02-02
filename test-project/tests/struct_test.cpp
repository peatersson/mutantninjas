#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#include "struct_example.hpp"
#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>
#include <iostream>

BOOST_AUTO_TEST_CASE(point_accessor_test) {
    /*cubeType cube1;
    cube1.height = 10;
    cube1.width = 5;
    cube1.depth = 10;
    BOOST_CHECK_EQUAL(getVolume_example(cube1), 500);

    cubeType cube2;
    cube2.height = 5;
    cube2.width = 10;
    cube2.depth = 10;
    BOOST_CHECK_EQUAL(getVolume_example(cube2), 500);
    BOOST_CHECK_EQUAL(getVolume_example(cube1), getVolume_example(cube2));

    cubeType cube3;
    cube3.height = 0;
    cube3.width = 5;
    cube3.depth = 5;
    BOOST_CHECK_EQUAL(getVolume_example(cube3), -1);
    BOOST_CHECK_PREDICATE(std::not_equal_to<int>(),(getVolume_example(cube2))(getVolume_example(cube3)));

    cubeType cube4;
    cube4.height = 5;
    cube4.width = -1;
    cube4.depth = 4;
    BOOST_CHECK_EQUAL(getVolume_example(cube4), -1);

    cubeType cube5;
    cube5.height = 1;
    cube5.width = 5;
    cube5.depth = 0;
    BOOST_CHECK_EQUAL(getVolume_example(cube5), -1);

    cubeType cube6;
    cube6.height = 2147483647;
    cube6.width = 2147483647;
    cube6.depth = 0;
    BOOST_CHECK_EQUAL(getVolume_example(cube6), -1);*/
}
