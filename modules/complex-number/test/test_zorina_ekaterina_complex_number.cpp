// Copyright 2017 Zorina Ekaterina

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Zorina_Ekaterina_ComplexNumberTest, Can_Assign_Complex_Number_To_Itself) {
    // Arrange
    double re = 1.0, im = -1.0;
    // Act
    ComplexNumber z1(re, im);
    ComplexNumber z2(re, im);
    z2 = z2;
    // Assert
    EXPECT_EQ(z1, z2);
}

TEST(Zorina_Ekaterina_ComplexNumberTest, Can_Substract_Many_Complex_Numbers) {
    // Arrange
    double re = 2.0, im = -1.0;
    // Act
    ComplexNumber z1(re, im);
    ComplexNumber z2(re, im);
    ComplexNumber z3(re, im);
    ComplexNumber z4(re, im);
    ComplexNumber z5(re, im);
    ComplexNumber z(5 * re, 5 * im), zt(0, 0);
    z = z - z1 - z2 - z3 - z4 - z5;
    // Assert
    EXPECT_EQ(z, zt);
}

TEST(Zorina_Ekaterina_ComplexNumberTest, Can_Add_Many_Complex_Numbers) {
    // Arrange
    double re = 1.0, im = -1.0;
    // Act
    ComplexNumber z1(re, im);
    ComplexNumber z2(re, im);
    ComplexNumber z3(re, im);
    ComplexNumber z4(re, im);
    ComplexNumber z5(re, im);
    ComplexNumber z(5 * re, 5 * im);
    // Assert
    EXPECT_EQ(z, z1 + z2 + z3 + z4 + z5);
}

TEST(Zorina_Ekaterina_ComplexNumberTest, Conjugate_Complex_Numbers_Multiply) {
    // Arrange
    double re = 6.0, im = 4.22;
    // Act
    ComplexNumber z1(re, im);
    ComplexNumber z2(re, - im);
    ComplexNumber z(re * re + im * im, 0.0);
    // Assert
    EXPECT_EQ(z, z1 * z2);
}

TEST(Zorina_Ekaterina_ComplexNumberTest, Copied_Number_Has_Its_Own_Memory) {
    // Arrange
    double re = 1.0, im = -1.0;
    // Act
    ComplexNumber z1(re, im);
    ComplexNumber z2(z1);
    ComplexNumber *p1, *p2;
    p1 = &z1;
    p2 = &z2;
    // Assert
    EXPECT_NE(p1, p2);
}
