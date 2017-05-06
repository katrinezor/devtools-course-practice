// Copyright 2017 Lobanov Andrey

#include "include/LineSegment.h"
#include <iostream>
#include <string>

using std::string;
using std::stringstream;

string LineSegment2D::checkIntersection(LineSegment2D lineSegment) {
    string str1, str2, str3;
    stringstream stream1, stream2;
    double coord_X, coord_Y;
    if ((lineSegment.Get_A() / Get_A() ==
        lineSegment.Get_B() / Get_B()) &&
        (lineSegment.Get_A() / Get_A() ==
        lineSegment.Get_C() / Get_C())) {
            str = "Lines are coincide";
    }
    else if (lineSegment.Get_A()/Get_A()==lineSegment.Get_B()/Get_B())
        str = "Lines are parallel";
    else {
        coord_X = (-1) * (Get_C() * lineSegment.Get_B() -
                  lineSegment.Get_C() * Get_B()) /
                  (Get_A() * lineSegment.Get_B() -
                  Get_B() * lineSegment.Get_A());
        coord_Y = (-1) * (Get_A() * lineSegment.Get_C() -
                  lineSegment.Get_A() * Get_C()) /
                  (Get_A() * lineSegment.Get_B() -
                  lineSegment.Get_A() * Get_B());
        str1 = "Intersection point: (";
        stream1 << Corrections(coord_X);
        stream1 >> str2;
        str2 += "; ";
        stream2 << Corrections(coord_Y);
        stream2 >> str3;
        str3 += ")";
        str = str1 + str2 + str3;
    }
    return str;
}

double LineSegment2D::Corrections(double value) {
    if (value == -0)
        return -value;
    else
        return value;
}
