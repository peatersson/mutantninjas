#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#include "triangle_example.hpp"
#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>
#include <iostream>

/*BOOST_AUTO_TEST_CASE(point_accessor_test) {
    Triangle tri;
    tri.s1=1;
    tri.s2=1;
    tri.s3=1;
    BOOST_CHECK_EQUAL(triangle_new(1,1,1).s1, tri.s1);
    BOOST_CHECK_EQUAL(triangle_new(1,1,3).s2, tri.s2);
    BOOST_CHECK_EQUAL(triangle_new(3,2,1).s3, tri.s3);


    BOOST_CHECK_EQUAL(triangle_type(tri), EQU);
    tri.s1 = 2;
    BOOST_CHECK_EQUAL(triangle_type(tri), ERR);
    tri.s2 = 2;
    BOOST_CHECK_EQUAL(triangle_type(tri), ISO);
    tri.s1 = 4;
    tri.s3 = 3;
    BOOST_CHECK_EQUAL(triangle_type(tri), SCA);
    tri.s2 = 7;
    BOOST_CHECK_EQUAL(triangle_type(tri), ERR);
    tri.s3 = 11;
    BOOST_CHECK_EQUAL(triangle_type(tri), ERR);
    tri.s3 = -1;
    BOOST_CHECK_EQUAL(triangle_type(tri), ERR);
    tri.s2 = -1;
    BOOST_CHECK_EQUAL(triangle_type(tri), ERR);
    tri.s1 = -1;
    BOOST_CHECK_EQUAL(triangle_type(tri), ERR);

    //50331648, 16777216, 16777216
    tri.s1 = 5;
    tri.s2 = 1;
    tri.s3 = 1;
    BOOST_CHECK_EQUAL(triangle_type(tri), ERR);

    //65536, 16777216, 16777216
    tri.s1 = 1;
    tri.s2 = 10;
    tri.s3 = 10;
    BOOST_CHECK_EQUAL(triangle_type(tri), ISO);

    //16777216, 16777216, 33554432
    tri.s1 = 1;
    tri.s2 = 1;
    tri.s3 = 2;
    BOOST_CHECK_EQUAL(triangle_type(tri), ERR);

    //33554432, 16777216, 33554432
    tri.s1 = 2;
    tri.s2 = 1;
    tri.s3 = 2;
    BOOST_CHECK_EQUAL(triangle_type(tri), ISO);

    //16777216, 50331648, 16777216
    tri.s1 = 2;
    tri.s2 = 10;
    tri.s3 = 2;
    BOOST_CHECK_EQUAL(triangle_type(tri), ERR);

    //16777216, 33554432, 16777216
    tri.s1 = 1;
    tri.s2 = 2;
    tri.s3 = 1;
    BOOST_CHECK_EQUAL(triangle_type(tri), ERR);
}*/

void assert_triangle_type(int s1, int s2, int s3, Triangle_type expected){
    Triangle t = triangle_new(s1, s2, s3);
    Triangle_type actual = triangle_type(t);
    BOOST_CHECK_EQUAL(expected, actual);
}


BOOST_AUTO_TEST_CASE(point_accessor_test) {
    assert_triangle_type(1, 1, 1, EQU);

    assert_triangle_type(2, 2, 1, ISO);
    assert_triangle_type(2, 1, 2, ISO);
    assert_triangle_type(1, 2, 2, ISO);

    assert_triangle_type(4, 3, 2, SCA);

    // expect integer overflow
    assert_triangle_type(4201476, 4201476, 2145527840, ERR);
    assert_triangle_type(681740491, 1534703449, 681740491, ERR);
    assert_triangle_type(50331648, 16777216, 16777216, ERR);

    assert_triangle_type(2, 1, 1, ERR);
    assert_triangle_type(1, 1, 2, ERR);

    assert_triangle_type(1, 1, 0, ERR);
    assert_triangle_type(0, 1, 1, ERR);
    assert_triangle_type(1, 0, 1, ERR);

    assert_triangle_type(2, 1, 3, ERR);
    assert_triangle_type(2, 3, 1, ERR);
    assert_triangle_type(3, 2, 1, ERR);

    assert_triangle_type(1, 2, 4, ERR);
    assert_triangle_type(4, 2, 1, ERR);
    assert_triangle_type(2, 4, 1, ERR);
}
