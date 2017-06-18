// Copyright 2017 Pletnev Nikita

#include <gtest/gtest.h>

#include "include/complex_number.h"


TEST(Pletnev_Nikita_ComplexNumberTest, Assignment_Returns_The_Value) {
    // Arrange
    ComplexNumber z1(0.0, 0.0);
    ComplexNumber z2(1.0, 1.0);

    // Act & Assert
    EXPECT_EQ(z2, z1 = z2);
}

TEST(Pletnev_Nikita_ComplexNumberTest, Divide_Zero_By_A_Complex) {
    // Arrange
    ComplexNumber z1(0.0, 0.0);
    ComplexNumber z2(1.0, 1.0);

    // Act
    ComplexNumber z = z1 / z2;

    // Assert
    EXPECT_EQ(z1, z);
}

TEST(Pletnev_Nikita_ComplexNumberTest, Subtract_A_Number_From_Zero) {
    // Arrange
    ComplexNumber z1(0.0, 0.0);
    ComplexNumber z2(1.0, 1.0);

    // Act
    ComplexNumber z = z1 - z2;

    // Assert
    ComplexNumber expected_z(-1.0, -1.0);
    EXPECT_EQ(expected_z, z);
}

TEST(Pletnev_Nikita_ComplexNumberTest, Copy_Constructor_Works) {
    // Arrange
    ComplexNumber z1(0.0, 0.0);

    // Act
    ComplexNumber z2(z1);

    // Assert
    EXPECT_EQ(z1, z2);
}

TEST(Pletnev_Nikita_ComplexNumberTest, Different_Memory_After_Assignment) {
    // Arrange
    ComplexNumber z1(1.0, 1.0);

    // Act
    ComplexNumber z2 = z1;

    // Assert
    EXPECT_NE(&z1, &z2);
}

TEST(Pletnev_Nikita_ComplexNumberTest, Different_Memory_After_Copy_Constr) {
    // Arrange
    ComplexNumber z1(1.0, 1.0);

    // Act
    ComplexNumber z2(z1);

    // Assert
    EXPECT_NE(&z1, &z2);
}
