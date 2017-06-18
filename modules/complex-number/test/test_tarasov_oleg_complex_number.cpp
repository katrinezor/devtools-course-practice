// Copyright 2017 Tarasov Oleg


#include <gtest/gtest.h>
#include <string>
#include "include/complex_number.h"


TEST(TarasovOlegTest, Divide_By_Zero) {
    // Arrange
    ComplexNumber z1(5.0, 11.0);
    ComplexNumber z2(0.0, 0.0);

    EXPECT_THROW(z1 / z2, std::string);
}

TEST(TarasovOlegTest, Complex_Expression) {
    // Arrange
    ComplexNumber z1(10.0, 5.0);
    ComplexNumber z2(7.0, 1.0);

    // Act
    ComplexNumber z = (z1 * z2) + (z1 - z2);

    // Assert
    ComplexNumber expected_z(68.0, 49.0);
    EXPECT_EQ(z, expected_z);
}

TEST(TarasovOlegTest, Complex_Expression_With_Divide) {
    // Arrange
    ComplexNumber z1(10.0, 5.0);
    ComplexNumber z2(7.0, 1.0);

    // Act
    ComplexNumber z = (z1 * z2) / (z1 - z2);

    // Assert
    ComplexNumber expected_z(15.0, -5.0);
    EXPECT_EQ(z, expected_z);
}

TEST(TarasovOlegTest, Check_Additivity) {
    // Arrange
    ComplexNumber z1(5.0, 11.0);
    ComplexNumber z2(14.0, -1.0);

    // Act & Assert
    EXPECT_EQ(z1 + z2, z2 + z1);
}

TEST(TarasovOlegTest, Check_Assotiative) {
    // Arrange
    ComplexNumber z1(5.0, 11.0);
    ComplexNumber z2(14.0, -1.0);
    ComplexNumber z3(5.0, 2.0);

    // Act & Assert
    EXPECT_EQ((z1 + z2) + z3, z1 + (z2 + z3));
}

TEST(TarasovOlegTest, Check_Distributive) {
    // Arrange
    ComplexNumber z1(5.0, 11.0);
    ComplexNumber z2(14.0, -1.0);
    ComplexNumber z3(5.0, 2.0);

    // Act & Assert
    EXPECT_EQ((z1 + z2) * z3, z1 * z3 + z2 * z3);
}
