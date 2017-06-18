// Copyright 2017 Lapin Artem

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Lapin_Artem_ComplexNumberTest, Can_Create_With_Negative_Real) {
    // Arrange
    double re = -20.0;
    double im = 20.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Lapin_Artem_ComplexNumberTest, Can_Create_With_Negative_Imaginary) {
    // Arrange
    double re = 20.0;
    double im = -20.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Lapin_Artem_ComplexNumberTest, Zero_Complex_Number_Is_Equal_To_Zero) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(z.getRe(), 0);
    EXPECT_EQ(z.getIm(), 0);
}

TEST(Lapin_Artem_ComplexNumberTest, Zero_Add_Complex_Is_Equal_To_Complex) {
    // Arrange
    ComplexNumber z1(0.0, 0.0);
    ComplexNumber z2(20.0, 20.0);

    // Act
    ComplexNumber z = z1 + z2;

    // Assert
    ComplexNumber expected_z = z2;
    EXPECT_EQ(expected_z, z);
}

TEST(Lapin_Artem_ComplexNumberTest, Zero_Mult_Complex_Is_Equal_To_Zero) {
    // Arrange
    ComplexNumber z1(0.0, 0.0);
    ComplexNumber z2(20.0, 20.0);

    // Act
    ComplexNumber z = z1 * z2;

    // Assert
    ComplexNumber expected_z = z1;
    EXPECT_EQ(expected_z, z);
}

TEST(Lapin_Artem_ComplexNumberTest, Add_Commutativity_Check) {
    // Arrange
    ComplexNumber z1(15.5, 10.2);
    ComplexNumber z2(20.0, 20.0);

    // Act
    ComplexNumber sum1 = z1 + z2;
    ComplexNumber sum2 = z2 + z1;

    // Assert
    EXPECT_EQ(sum1, sum2);
}

TEST(Lapin_Artem_ComplexNumberTest, Multipication_Commutativity_Check) {
    // Arrange
    ComplexNumber z1(16.6, 11.2);
    ComplexNumber z2(19.1, 18.3);

    // Act
    ComplexNumber mult1 = z1 * z2;
    ComplexNumber mult2 = z2 * z1;

    // Assert
    EXPECT_EQ(mult1, mult2);
}

TEST(Lapin_Artem_ComplexNumberTest, Multipication_Associativity_Check) {
    // Arrange
    ComplexNumber z1(16.6, 11.2);
    ComplexNumber z2(19.1, 18.3);
    ComplexNumber z3(9.1, 23.9);

    // Act
    ComplexNumber mult1 = (z1 * z2) * z3;
    ComplexNumber mult2 = z1 * (z2 * z3);

    // Assert
    EXPECT_EQ(mult1, mult2);
}
