#include "triangle_example.hpp"

Triangle triangle_new(int s1, int s2, int s3) {
    Triangle t;
    t.s1 = s1;
    t.s2 = s2;
    t.s3 = s3;

    return t;
}

Triangle_type triangle_type(Triangle t) {
    int s = 0;

    if (t.s1 <= 0 || t.s2 <= 0 || t.s3 <= 0) {
        return ERR;
    }

    if (t.s1 == t.s2) {
        s += 1;
    }

    if (t.s1 == t.s3) {
        s += 2;
    }

    if (t.s2 == t.s3) {
        s += 3;
    }

    if (s == 0) {
        if ((t.s1 + t.s2 <= t.s3) || (t.s2 + t.s3 <= t.s1) || (t.s1 + t.s3 <= t.s2)) {
            return ERR;
        } else {
            return SCA;
        }
    } else if (s > 3) {
        return EQU;

    } else if (s == 1 && (t.s1 + t.s2 > t.s3)) {
        return ISO;

    } else if (s == 2 && (t.s1 + t.s3 > t.s2)) {
        return ISO;

    } else if (s == 3 && (t.s2 + t.s3 > t.s1)) {
        return ISO;
    }

    return ERR;
}
