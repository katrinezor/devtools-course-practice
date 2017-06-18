// Copyright 2017 Mitrokhin Nikita

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Mitrokhin_Nikita_ComplexNumberTest, Can_Add_Imaginary_Complex) {
    // Arrange
    ComplexNumber z1(0.0, 2.0);
    ComplexNumber z2(0.0, 13.0);

    // Act
    ComplexNumber z = z1 + z2;

    // Assert
    EXPECT_DOUBLE_EQ(0.0, z.getRe());
    EXPECT_DOUBLE_EQ(15.0, z.getIm());
}

TEST(Mitrokhin_Nikita_ComplexNumberTest, Can_Multiply_Imaginary_Complex) {
    // Arrange
    ComplexNumber z1(0.0, 2.0);
    ComplexNumber z2(0.0, 13.0);

    // Act
    ComplexNumber z = z1 * z2;

    // Assert
    EXPECT_DOUBLE_EQ(-26.0, z.getRe());
    EXPECT_DOUBLE_EQ(0.0, z.getIm());
}

TEST(Mitrokhin_Nikita_ComplexNumberTest, Equal_Imaginary_Complex) {
    // Arrange
    ComplexNumber z1(0.0, 2.0);
    ComplexNumber z2(0.0, 2.0);

    // Act & Assert
    EXPECT_TRUE(z1 == z2);
}

TEST(Mitrokhin_Nikita_ComplexNumberTest, Can_Multiply_By_Zero) {
    // Arrange
    ComplexNumber z1(0.0, 0.0);
    ComplexNumber z2(1.0, 7.0);

    // Act
    ComplexNumber z = z1 * z2;

    // Assert
    EXPECT_DOUBLE_EQ(0.0, z.getRe());
    EXPECT_DOUBLE_EQ(0.0, z.getIm());
}

TEST(Mitrokhin_Nikita_ComplexNumberTest, Can_Division_Imaginary_Complex) {
    // Arrange
    ComplexNumber z1(0.0, 2.0);
    ComplexNumber z2(0.0, 4.0);

    // Act
    ComplexNumber z = z2 / z1;

    // Assert
    EXPECT_DOUBLE_EQ(2.0, z.getRe());
    EXPECT_DOUBLE_EQ(0.0, z.getIm());
}

