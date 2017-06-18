// Copyright 2017 Simonyan Vaginak

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Simonyan_Vaginak_ComplexNumberTest, Can_setRe) {
    // Arrange
    double re = 2.9;
    double im = 3.4;
    double newRe = 5.2;

    // Act
    ComplexNumber z(re, im);
    z.setRe(newRe);

    // Assert
    EXPECT_EQ(newRe, z.getRe());
}

TEST(Simonyan_Vaginak_ComplexNumberTest, Can_Create_Using_ComplexNum) {
    // Arrange
    double re = 2.9;
    double im = 3.4;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber x(z);

    // Assert
    EXPECT_EQ(z, x);
}

TEST(Simonyan_Vaginak_ComplexNumberTest, Can_Assign_Value) {
    // Arrange
    double re = 2.9;
    double im = 3.4;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber x;
    x = z;

    // Assert
    EXPECT_EQ(x, z);
}

TEST(Simonyan_Vaginak_ComplexNumberTest, Can_Sum) {
    // Arrange
    double reZ = 2.9;
    double imZ = 3.4;
    double reX = 7.5;
    double imX = 2.3;

    // Act
    ComplexNumber z(reZ, imZ);
    ComplexNumber x(reX, imX);
    z = z + x;

    // Assert
    EXPECT_EQ(reZ + reX, z.getRe());
    EXPECT_EQ(imZ + imX, z.getIm());
}

TEST(Simonyan_Vaginak_ComplexNumberTest, Can_Multiply) {
    // Arrange
    double reZ = 2.9;
    double imZ = 3.4;
    double reX = 7.5;
    double imX = 2.3;

    // Act
    ComplexNumber z(reZ, imZ);
    ComplexNumber x(reX, imX);
    z = z * x;

    // Assert
    EXPECT_EQ(reZ*reX - imZ*imX, z.getRe());
    EXPECT_EQ(reZ*imX + reX*imZ, z.getIm());
}
