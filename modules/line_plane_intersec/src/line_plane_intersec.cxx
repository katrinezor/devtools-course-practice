// Copyright 2017 Lapin Artem

#include "include/line_plane_intersec.h"
#include <string.h>
#include <string>
#include <vector>

Intersection::Intersection() {
    linex0_ = 1.0;
    liney0_ = 1.0;
    linez0_ = 1.0;
    linedirx_ = 1.0;
    linediry_ = 1.0;
    linedirz_ = 1.0;
    planeA_ = 1.0;
    planeB_ = 1.0;
    planeC_ = 1.0;
    planeD_ = 1.0;
}

Intersection::Intersection(double x0, double y0, double z0, double dirx,
    double diry, double dirz, double A, double B, double C, double D) {
    linex0_ = x0;
    liney0_ = y0;
    linez0_ = z0;
    linedirx_ = dirx;
    linediry_ = diry;
    linedirz_ = dirz;
    planeA_ = A;
    planeB_ = B;
    planeC_ = C;
    planeD_ = D;
}

Intersection::Intersection(std::vector<double>lineStart,
    std::vector<double>lineDirection, std::vector<double>plane) {
    linex0_ = lineStart[0];
    liney0_ = lineStart[1];
    linez0_ = lineStart[2];
    linedirx_ = lineDirection[0];
    linediry_ = lineDirection[1];
    linedirz_ = lineDirection[2];
    planeA_ = plane[0];
    planeB_ = plane[1];
    planeC_ = plane[2];
    planeD_ = plane[3];
}

void Intersection::SetLine(double x0, double y0, double z0,
    double dirx, double diry, double dirz) {
    linex0_ = x0;
    liney0_ = y0;
    linez0_ = z0;
    linedirx_ = dirx;
    linediry_ = diry;
    linedirz_ = dirz;
}

void Intersection::SetLine(std::vector<double>lineStart,
    std::vector<double>lineDirection) {
    linex0_ = lineStart[0];
    liney0_ = lineStart[1];
    linez0_ = lineStart[2];
    linedirx_ = lineDirection[0];
    linediry_ = lineDirection[1];
    linedirz_ = lineDirection[2];
}

void Intersection::SetLineWithTwoPoints(std::vector<double>point1,
    std::vector<double>point2) {
    if ((point1[0] == point2[0]) || (point1[1] == point2[1]) ||
    (point1[2] == point2[2])) {
        throw std::string("Incorrect input");
    } else {
        linex0_ = point1[0];
        liney0_ = point1[1];
        linez0_ = point1[2];
        linedirx_ = point2[0]-point1[0];
        linediry_ = point2[1]-point1[1];
        linedirz_ = point2[2]-point1[2];
    }
}

void Intersection::SetPlane(std::vector<double>plane) {
    planeA_ = plane[0];
    planeB_ = plane[1];
    planeC_ = plane[2];
    planeD_ = plane[3];
}

void Intersection::SetPlane(double A, double B, double C, double D) {
    planeA_ = A;
    planeB_ = B;
    planeC_ = C;
    planeD_ = D;
}

void Intersection::SetPlaneWithThreePoints(std::vector<double>point1,
    std::vector<double>point2, std::vector<double>point3) {
    std::vector<double> point12Vector(3);
    std::vector<double> point13Vector(3);
    std::vector<double> normalVec(3);
    point12Vector[0] = point2[0]-point1[0];
    point12Vector[1] = point2[1]-point1[1];
    point12Vector[2] = point2[2]-point1[2];
    point13Vector[0] = point3[0]-point1[0];
    point13Vector[1] = point3[1]-point1[1];
    point13Vector[2] = point3[2]-point1[2];
    normalVec[0] = point12Vector[1]*point13Vector[2] -
        point12Vector[2]*point13Vector[1];
    normalVec[1] = -(point12Vector[0]*point13Vector[2] -
        point12Vector[2]*point13Vector[0]);
    normalVec[2] = point12Vector[0]*point13Vector[1] -
        point12Vector[1]*point13Vector[0];
    if ((normalVec[0] == 0) && (normalVec[1] == 0) &&
    (normalVec[2] == 0)) {
        throw std::string("Incorrect input");
    } else {
        planeA_ = normalVec[0];
        planeB_ = normalVec[1];
        planeC_ = normalVec[2];
        planeD_ = 0 - normalVec[0]*point1[0] - normalVec[1]*point1[1] -
            normalVec[2]*point1[2];
    }
}

std::vector<double> Intersection::GetLine() {
    std::vector<double> result(6);
    result[0] = linex0_;
    result[1] = liney0_;
    result[2] = linez0_;
    result[3] = linedirx_;
    result[4] = linediry_;
    result[5] = linedirz_;
    return result;
}

std::vector<double> Intersection::GetPlane() {
    std::vector<double> result(4);
    result[0] = planeA_;
    result[1] = planeB_;
    result[2] = planeC_;
    result[3] = planeD_;
    return result;
}

std::vector<double> Intersection::CalculateIntersection() {
    double parameterValue;
    parameterValue = planeA_*linedirx_ + planeB_*linediry_ + planeC_*linedirz_;
    std::vector<double> result(3);
    if (parameterValue == 0) {
        throw std::string("Line and plane are parallel or line lies in plane");
    } else {
        parameterValue = (-1 * (planeA_*linex0_ + planeB_*liney0_ +
        planeC_*linez0_ + planeD_))/ parameterValue;
        result[0] = linex0_ + linedirx_*parameterValue;
        result[1] = liney0_ + linediry_*parameterValue;
        result[2] = linez0_ + linedirz_*parameterValue;
    }
    return result;
}


