// Copyright 2017 Zhorin Sergey

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Zhorin_Sergey_ComplexNumberTest, Can_Sum_Complex_And_Complex_Without_Im) {
    // Arrange
    ComplexNumber z1(1, 2);
    ComplexNumber z2(1, 0);

    // Act
    ComplexNumber z = z1 + z2;

    // Assert
    ComplexNumber expected_z(2, 2);
    EXPECT_EQ(z, expected_z);
}

TEST(Zhorin_Sergey_ComplexNumberTest, Can_Mult_Complex_And_Complex_Without_Im) {
    // Arrange
    ComplexNumber z1(1, 2);
    ComplexNumber z2(2, 0);

    // Act
    ComplexNumber z = z1 * z2;

    // Assert
    ComplexNumber expected_z(2, 4);
    EXPECT_EQ(z, expected_z);
}

TEST(Zhorin_Sergey_ComplexNumberTest, Can_Multiply_Complex_And_Zero) {
    // Arrange
    ComplexNumber z1(1, 2);
    ComplexNumber z2(0, 0);

    // Act
    ComplexNumber z = z1 * z2;

    // Assert
    ComplexNumber expected_z(0, 0);
    EXPECT_EQ(z, expected_z);
}

TEST(Zhorin_Sergey_ComplexNumberTest, Can_Divide_Zero) {
    // Arrange
    ComplexNumber z1(1, 2);
    ComplexNumber z2(0, 0);

    // Act
    ComplexNumber z = z2 / z1;

    // Assert
    ComplexNumber expected_z(0, 0);
    EXPECT_EQ(z, expected_z);
}

TEST(Zhorin_Sergey_ComplexNumberTest, Can_Divide_By_Itself) {
    // Arrange
    ComplexNumber z1(1, 2);

    // Act
    ComplexNumber z = z1 / z1;

    // Assert
    ComplexNumber expected_z(1, 0);
    EXPECT_EQ(z, expected_z);
}
