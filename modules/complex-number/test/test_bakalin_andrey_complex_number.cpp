// Copyright 2017 Bakalin Andrey

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Bakalin_Andrey_ComplexNumberTest, Can_Get_Real) {
    // Arrange
    double re = 1.0, im = 2.0;
    ComplexNumber z(re, im);

    // Act
    double re_real = z.getRe();

    // Assert
    double re_expected = re;
    EXPECT_EQ(re_real, re_expected);
}

TEST(Bakalin_Andrey_ComplexNumberTest, Can_Get_Imaginary) {
    // Arrange
    double re = 1.0, im = 2.0;
    ComplexNumber z(re, im);

    // Act
    double im_real = z.getIm();

    // Assert
    double im_expected = im;
    EXPECT_EQ(im_real, im_expected);
}

TEST(Bakalin_Andrey_ComplexNumberTest, Additive_Commutativity_Works) {
    // Arrange
    ComplexNumber z1(1.0, 2.0), z2(3.0, 4.0), z3, z4;

    // Act
    z3 = z1 + z2;
    z4 = z2 + z1;

    // Assert
    EXPECT_EQ(z3, z4);
}

TEST(Bakalin_Andrey_ComplexNumberTest, Additive_Associativity_Works) {
    // Arrange
    ComplexNumber z1(1.0, 2.0), z2(3.0, 4.0), z3(7.0, 8.0), z4, z5;

    // Act
    z4 = (z1 + z2) + z3;
    z5 = z1 + (z2 + z3);

    // Assert
    EXPECT_EQ(z4, z5);
}

TEST(Bakalin_Andrey_ComplexNumberTest, Left_Distributivity_Works) {
    // Arrange
    ComplexNumber z1(1.0, 2.0), z2(3.0, 4.0), z3(7.0, 8.0), z4, z5;

    // Act
    z4 = z1 * (z2 + z3);
    z5 = z1 * z2 + z1 * z3;

    // Assert
    EXPECT_EQ(z4, z5);
}
