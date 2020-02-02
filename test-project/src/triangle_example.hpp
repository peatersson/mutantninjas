#ifndef TRIANGLE_H
#define TRIANGLE_H

enum Triangle_type {
    SCA,
    ISO,
    EQU,
    ERR
};

struct Triangle {
public:
    int s1;
    int s2;
    int s3;
};

Triangle triangle_new(int s1, int s2, int s3);
Triangle_type triangle_type(Triangle t);

#endif // TRIANGLE_H
