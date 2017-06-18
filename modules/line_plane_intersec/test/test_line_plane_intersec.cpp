// Copyright 2017 Lapin Artem

#include <gtest/gtest.h>

#include <string>
#include <stdexcept>
#include <vector>

#include "include/line_plane_intersec.h"

TEST(Lapin_Artem_Line_Plane_Intersec_Test, Do_Throw_When_Line_Parallel_Plane) {
    // Arrange
    Intersection Intersec(1, 1, 1, 0, 0, 0, 1, 1, 1, 0);
    // Act & Assert
    EXPECT_THROW(Intersec.CalculateIntersection(), std::string);
}

TEST(Lapin_Artem_Line_Plane_Intersec_Test, Calculate_Return_Is_Correct) {
    // Arrange
    Intersection Intersec(-1, -2, 3, -3, 2, -2, 1, 3, -5, 9);
    std::vector<double> expected(3);
    expected[0] = -4;
    expected[1] = 0;
    expected[2] = 1;
    // Act & Assert
    EXPECT_EQ(Intersec.CalculateIntersection(), expected);
}

TEST(Lapin_Artem_Line_Plane_Intersec_Test, GetLine_And_SetLine_Works_Correct) {
    // Arrange
    Intersection Intersec;
    std::vector<double> expected(6);
    expected[0] = 6;
    expected[1] = 5;
    expected[2] = 4;
    expected[3] = 3;
    expected[4] = 2;
    expected[5] = 1;
    // Act
    Intersec.SetLine(6, 5, 4, 3, 2, 1);
    // Assert
    EXPECT_EQ(Intersec.GetLine(), expected);
}

TEST(Lapin_Artem_Line_Plane_Intersec_Test, GetPlane_And_SetPlane_Correct) {
    // Arrange
    Intersection Intersec;
    std::vector<double> expected(4);
    expected[0] = 6;
    expected[1] = 5;
    expected[2] = 4;
    expected[3] = 3;
    // Act
    Intersec.SetPlane(6, 5, 4, 3);
    // Assert
    EXPECT_EQ(Intersec.GetPlane(), expected);
}

TEST(Lapin_Artem_Line_Plane_Intersec_Test, More_Test_For_Calculate) {
    // Arrange
    Intersection Intersec(-3, 0, -2, -1, -3, 3, 1, -2, -1, 3);
    std::vector<double> expected(3);
    expected[0] = -2;
    expected[1] = 3;
    expected[2] = -5;
    // Act & Assert
    EXPECT_EQ(Intersec.CalculateIntersection(), expected);
}

TEST(Lapin_Artem_Line_Plane_Intersec_Test, Test_Line_In_Vec_Constructor) {
    // Arrange
    std::vector<double> lineStart(3);
    std::vector<double> lineDir(3);
    std::vector<double> plane(4);
    std::vector<double> expected(6);
    lineStart[0] = 1;
    lineStart[1] = 2;
    lineStart[2] = 3;
    lineDir[0] = 4;
    lineDir[1] = 5;
    lineDir[2] = 6;
    plane[0] = 7;
    plane[1] = 8;
    plane[2] = 9;
    plane[3] = 10;
    expected[0] = 1;
    expected[1] = 2;
    expected[2] = 3;
    expected[3] = 4;
    expected[4] = 5;
    expected[5] = 6;
    Intersection Intersec(lineStart, lineDir, plane);
    // Act & Assert
    EXPECT_EQ(Intersec.GetLine(), expected);
}

TEST(Lapin_Artem_Line_Plane_Intersec_Test, Test_Plane_In_Vec_Constructor) {
    // Arrange
    std::vector<double> lineStart(3);
    std::vector<double> lineDir(3);
    std::vector<double> plane(4);
    std::vector<double> expected(4);
    lineStart[0] = 1;
    lineStart[1] = 2;
    lineStart[2] = 3;
    lineDir[0] = 4;
    lineDir[1] = 5;
    lineDir[2] = 6;
    plane[0] = 7;
    plane[1] = 8;
    plane[2] = 9;
    plane[3] = 10;
    expected[0] = 7;
    expected[1] = 8;
    expected[2] = 9;
    expected[3] = 10;
    Intersection Intersec(lineStart, lineDir, plane);
    // Act & Assert
    EXPECT_EQ(Intersec.GetPlane(), expected);
}

TEST(Lapin_Artem_Line_Plane_Intersec_Test, SetLine_Vec_Works_Correct) {
    // Arrange
    Intersection Intersec;
    std::vector<double> expected(6);
    std::vector<double> lineStart(3);
    std::vector<double> lineDir(3);
    lineStart[0] = 6;
    lineStart[1] = 5;
    lineStart[2] = 4;
    lineDir[0] = 3;
    lineDir[1] = 2;
    lineDir[2] = 1;
    expected[0] = 6;
    expected[1] = 5;
    expected[2] = 4;
    expected[3] = 3;
    expected[4] = 2;
    expected[5] = 1;
    // Act
    Intersec.SetLine(lineStart, lineDir);
    // Assert
    EXPECT_EQ(Intersec.GetLine(), expected);
}

TEST(Lapin_Artem_Line_Plane_Intersec_Test, SetPlane_Vec_Works_Correct) {
    // Arrange
    Intersection Intersec;
    std::vector<double> expected(4);
    expected[0] = 6;
    expected[1] = 5;
    expected[2] = 4;
    expected[3] = 3;
    // Act
    Intersec.SetPlane(expected);
    // Assert
    EXPECT_EQ(Intersec.GetPlane(), expected);
}

TEST(Lapin_Artem_Line_Plane_Intersec_Test, SetLine_With_Two_Points_Correct) {
    // Arrange
    Intersection Intersec;
    std::vector<double> expected(6);
    std::vector<double> point1(3);
    std::vector<double> point2(3);
    point1[0] = 6;
    point1[1] = 5;
    point1[2] = 4;
    point2[0] = 9;
    point2[1] = 7;
    point2[2] = 5;
    expected[0] = 6;
    expected[1] = 5;
    expected[2] = 4;
    expected[3] = 3;
    expected[4] = 2;
    expected[5] = 1;
    // Act
    Intersec.SetLineWithTwoPoints(point1, point2);
    // Assert
    EXPECT_EQ(Intersec.GetLine(), expected);
}

TEST(Lapin_Artem_Line_Plane_Intersec_Test, Do_Throw_When_Line_Input_Incorrect) {
    // Arrange
    Intersection Intersec;
    std::vector<double> point1(3);
    std::vector<double> point2(3);
    point1[0] = 6;
    point1[1] = 5;
    point1[2] = 4;
    point2[0] = 6;
    point2[1] = 5;
    point2[2] = 4;
    // Act & Assert
    EXPECT_THROW(Intersec.SetLineWithTwoPoints(point1, point2), std::string);
}

TEST(Lapin_Artem_Line_Plane_Intersec_Test, SetPlane_With_Three_Points_Correct) {
    // Arrange
    Intersection Intersec;
    std::vector<double> expected(4);
    std::vector<double> point1(3);
    std::vector<double> point2(3);
    std::vector<double> point3(3);
    point1[0] = -3;
    point1[1] = 2;
    point1[2] = -1;
    point2[0] = -1;
    point2[1] = 2;
    point2[2] = 4;
    point3[0] = 3;
    point3[1] = 3;
    point3[2] = -1;
    expected[0] = -5;
    expected[1] = 30;
    expected[2] = 2;
    expected[3] = -73;
    // Act
    Intersec.SetPlaneWithThreePoints(point1, point2, point3);
    // Assert
    EXPECT_EQ(Intersec.GetPlane(), expected);
}

TEST(Lapin_Artem_Line_Plane_Intersec_Test,
    Do_Throw_When_Plane_Input_Incorrect) {
    // Arrange
    Intersection Intersec;
    std::vector<double> expected(4);
    std::vector<double> point1(3);
    std::vector<double> point2(3);
    std::vector<double> point3(3);
    point1[0] = 5;
    point1[1] = -8;
    point1[2] = -2;
    point2[0] = 1;
    point2[1] = -2;
    point2[2] = 0;
    point3[0] = -1;
    point3[1] = 1;
    point3[2] = 1;
    // Act & Assert
    EXPECT_THROW(Intersec.SetPlaneWithThreePoints(point1, point2, point3),
        std::string);
}
