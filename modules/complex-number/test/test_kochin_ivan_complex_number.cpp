// Copyright 2017 Kochin Ivan

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kochin_Ivan_ComplexNumberTest, Work_of_Link_Constructor) {
    // Arrange
    ComplexNumber z(1, 1);

    // Act
    ComplexNumber z1(z);

    // Assert
    EXPECT_EQ(z, z1);
}

TEST(Kochin_Ivan_ComplexNumberTest, Can_Multiplication_Zero) {
    // Arrange
    ComplexNumber z1(1, 1);
    ComplexNumber z2(0, 0);

    // Act
    ComplexNumber z = z2*z1;

    // Assert
    ComplexNumber expected_z(0, 0);
    EXPECT_EQ(expected_z, z);
}

TEST(Kochin_Ivan_ComplexNumberTest, Can_Difference_By_Yourself) {
    // Arrange
    ComplexNumber z(1, 1);

    // Act
    z = z - z;

    // Assert
    ComplexNumber expected_z(0, 0);
    EXPECT_EQ(expected_z, z);
}

TEST(Kochin_Ivan_ComplexNumberTest, Can_Add_By_Yourself) {
    // Arrange
    ComplexNumber z(1, 1);

    // Act
    z = z + z;

    // Assert
    ComplexNumber expected_z(2, 2);
    EXPECT_EQ(expected_z, z);
}


TEST(Kochin_Ivan_ComplexNumberTest, Can_Double_Assignment) {
    // Arrange
    ComplexNumber z1(1, 1);
    ComplexNumber z2(2, 2);
    ComplexNumber z3(3, 3);

    // Act
    z1 = z2 = z3;

    // Assert
    ComplexNumber expected_z(3, 3);
    EXPECT_EQ(expected_z, z1);
}


TEST(Kochin_Ivan_ComplexNumberTest, Can_Multiply_With_One) {
    // Arrange
    ComplexNumber z1(1, 0);
    ComplexNumber z2(5, -3);

    // Act
    ComplexNumber z3 = z1 * z2;

    // Assert
    ComplexNumber expected_z(5, -3);
    EXPECT_EQ(expected_z, z3);
}

TEST(Kochin_Ivan_ComplexNumberTest, Sqr_of_Imaginary_Part) {
    // Arrange
    ComplexNumber z1(0, 5);

    // Act
    ComplexNumber z2 = z1*z1;

    // Assert
    ComplexNumber expected_z(-25, 0);
    EXPECT_EQ(expected_z, z2);
}
